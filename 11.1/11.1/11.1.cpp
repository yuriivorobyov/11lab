#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <iomanip>
using namespace std;

void create(char* FileName, int N, int min, int max)
{
    ofstream f(FileName, ios::binary);
    if (!f)
    {
        cerr << "file did not opened" << endl;
        exit(1);
    }

    int a;
    double test = 0;
    for (int i = 0; i < N; i++)
    {
        a = min + rand() % (max - min + 1);
        f.write((char*)&a, sizeof(int));
    }
    cout << endl;
}
double averageOdd(char* FileName)
{
    ifstream f(FileName, ios::binary);
    if (!f)
    {
        cerr << "file did not opened" << endl;
        exit(1);
    }
    int a, l = 0;
    double avgOdd = 0;
    while (f.read((char*)&a, sizeof(int)))
    {

        if (a % 2 == !0)
        {
            ++l;
            avgOdd += a;
        }
    }
    if (l > 0)
        avgOdd = avgOdd / l;
    return avgOdd;
}

double averageEven(char* FileName)
{
    ifstream f(FileName, ios::binary);
    if (!f)
    {
        cerr << "file did not opened" << endl;
        exit(1);
    }
    int a, l = 0;
    double avgEven = 0;
    while (f.read((char*)&a, sizeof(int)))
    {

        if (a % 2 == 0)
        {
            ++l;
            avgEven += a;
        }
    }
    if (l > 0)
        avgEven = avgEven / l;
    return avgEven;
}
void print(char* FileName)
{
    ifstream f(FileName, ios::binary);
    if (!f)
    {
        cerr << "file did not opened" << endl;
        exit(1);
    }
    int a;
    while (f.read((char*)&a, sizeof(int)))
        cout << a << "   ";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(NULL));
    int N, min, max, menu;
    double avgOdd, avgEven;
    char FileName[] = "t.txt";
    cout << "Select a menu item" << endl;
    do {
        cout << endl;
        cout << "[0] - Write the numbers in a binary file: " << endl;
        cout << "[1] - Download binary file and output arithmetic mean of positive and negative" << endl;
        cout << "[2] - Download numbers from a binary file and display" << endl;
        cout << "[other] - Exit the program" << endl;
        cout << "Menu item:"; cin >> menu;
        switch (menu)
        {
        case 0:
            cout << endl;
            cout << "Enter the number of numbers: "; cin >> N;
            cout << "Enter the minimum value:"; cin >> min;
            cout << "Enter the maximum value:"; cin >> max;
            create(FileName, N, min, max);
            break;
        case 1:
            cout << endl;
            cout << "Arithmetic mean negative: " << averageOdd(FileName) << endl;
            cout << "Positive arithmetic mean:" << averageEven(FileName) << endl;
            break;
        case 2:
            print(FileName);
        default:
            break;
        }
    } while (menu == 0 || menu == 1 || menu == 2);
}

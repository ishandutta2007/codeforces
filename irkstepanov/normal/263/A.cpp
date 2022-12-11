#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{

    int a, b;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
    {
        int x;
        cin >> x;
        if (x) {a = i; b = j;}
    }

    cout << abs (a - 3) + abs (b - 3);

}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

int a, b, n;
bool kol[101][101];

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    cin >> n >> a >> b;
    if (n == 1)
    {
        cout << 1 << " ";
        for (int i = 0; i < b - 1; i++)
            cout << 0 << " ";
        cout << endl;
        for (int i = 0; i < a - 1; i++)
        {
            for (int j = 0; j < b; j++)
                cout << 0 << " ";
            cout << endl;
        }
        return 0;
    }
    if (n > a * b)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            kol[i][j] = (i - j) % 2;
    int a1 = 0;
    int a2 = 0;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
        {
            if (kol[i][j])
                a2++;
            else
                a1++;
        }
    int nech = (n + 1) / 2;
    int ch = n / 2;
    int lastn, lastc;
    if (n % 2 == 0)
        lastn = n - 1, lastc = n;
    else
        lastn = n, lastc = n - 1;
    if (nech <= a1 && ch <= a2)
    {
        int curn = 1;
        int curc = 2;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if (kol[i][j])
                {
                    if (curc > lastc)
                        cout << 0 << " ";
                    else
                    {
                        cout << curc << " ";
                        curc += 2;
                    }
                }
                else
                {
                    if (curn > lastn)
                        cout << 0 << " ";
                    else
                    {
                        cout << curn << " ";
                        curn += 2;
                    }
                }
            }
            cout << endl;
        }
        return 0;
    }
    if (ch <= a1 && nech <= a2)
    {
        int curn = 1;
        int curc = 2;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if (kol[i][j])
                {
                    if (curn > lastn)
                        cout << 0 << " ";
                    else
                    {
                        cout << curn << " ";
                        curn += 2;
                    }
                }
                else
                {
                    if (curc > lastc)
                        cout << 0 << " ";
                    else
                    {
                        cout << curc << " ";
                        curc += 2;
                    }
                }
            }
            cout << endl;
        }
        return 0;
    }
    cout << -1;
    return 0;
}
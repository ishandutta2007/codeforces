#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>

#define int long long
//#define double long double

using namespace std;

const long long MOD = 998244353;

long long a, b;

long long e = (128) - 1;
long long d = (128 << 7) - e - 1;
long long f = (1 << 14);

signed main()
{
    cout << "? ";
    int c = 0;
    for (int i = 0; i < (1 << 14); i++)
    {
        if ((i & d) == d)
        {
            if (c < 100)
            {
                cout << i << " ";
                c++;
            }
        }
    }
    cout << endl;
    cin >> a;

    cout << "? ";
    c = 0;
    for (int i = 0; i < (1 << 14); i++)
    {
        if ((i & e) == e)
        {
            if (c < 100)
            {
                cout << i << " ";
                c++;
            }
        }
    }
    cout << endl;
    cin >> b;

    long long kek = 0;
    for (int i = 0; i < 7; i++)
    {
        if (b & (1 << i))
            kek += (1 << i);
    }
    for (int i = 7; i < 14; i++)
    {
        if (a & (1 << i))
            kek += (1 << i);
    }
    cout << "! " << f - 1 - kek << endl;
}
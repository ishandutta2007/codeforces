#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string>

using namespace std;

long long d[500], h[500];

void solve()
{
    long long a, b, c;
    cin >> a >> b >> c;
    if (a <= b)
    {
        long long d = b + 1 - a;
        c -= d;
        a = b + 1;
        if (c < 0)
        {
            cout << 0 << "\n";
            return;
        }
    }
    long long minX = -1, maxX = c;
    while (minX + 1 < maxX)
    {
        long long mid = (minX + maxX) / 2;
        long long p1 = a + mid;
        long long p2 = b + c - mid;
        if (p1 > p2)
        {
            maxX = mid;
        }
        else
        {
            minX = mid;
        }
    }
    cout << c - maxX + 1 << "\n";
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
}
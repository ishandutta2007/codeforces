#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string>

using namespace std;

long long d[500], h[500];

void solve()
{
    long long n, x;
    cin >> n >> x;
    long long max_ = 0;
    long long max_opera = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i] >> h[i];
        max_ = max(max_, d[i]);
        max_opera = max(max_opera, d[i] - h[i]);
    }
    if (max_opera == 0)
    {
        if (x <= max_)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
        return;
    }
    long long l = -1, r = 1e9 + 4;
    while (l + 1 < r)
    {
        long long mid = (l + r) / 2;
        long long after_mid = x - mid * max_opera;
        if (after_mid <= max_)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r + 1 << "\n";
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
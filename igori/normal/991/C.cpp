#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    ll L = 0, R = n;
    while (L + 1 < R)
    {
        ll M = (L + R) / 2;
        ll x = n;
        ll p = 0;
        int t = 0;
        while (x)
        {
            if (!t)
            {
                p += min(x, M);
                x -= min(x, M);
            }
            else
            {
                x -= x / 10;
            }
            t ^= 1;
        }
        if (2 * p >= n) R = M;
        else L = M;
    }
    cout << R << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void solve()
{
    int n;
    cin >> n;
    vector<vector<ll> > a(2 * n, vector<ll>(2 * n));
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    for (int i = n; i < 2 * n; i++)
    {
        for (int j = n; j < 2 * n; j++)
        {
            ans += a[i][j];
        }
    }
    ll mn = 1e9 + 1;
    mn = min(mn, a[n][0]);
    mn = min(mn, a[n][n - 1]);
    mn = min(mn, a[2 * n - 1][0]);
    mn = min(mn, a[2 * n - 1][n - 1]);
    mn = min(mn, a[0][n]);
    mn = min(mn, a[n - 1][n]);
    mn = min(mn, a[0][2 * n - 1]);
    mn = min(mn, a[n - 1][2 * n - 1]);
    cout << ans + mn << "\n";
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
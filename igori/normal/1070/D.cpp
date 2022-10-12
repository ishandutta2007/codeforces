#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        ll x = (a[i - 1] + k - 1) / k;
        ll rm = x * k;
        ans += x;
        ll have = rm - a[i - 1];
        if (i < n)
        {
            a[i] -= have;
            if (a[i] < 0) a[i] = 0;
        }
    }
    cout << ans << "\n";
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
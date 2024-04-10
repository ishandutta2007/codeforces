#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    map<long long, long long> mm;
    map<pair<int, int>, long long> m2;
    for (int i = 0; i < n; i++)
    {
        int x, dx, dy;
        cin >> x >> dx >> dy;
        mm[dy - 1ll * a * dx]++;
        m2[{dx, dy}]++;
        //cout << dy - 1ll * a * dx << "\n";
    }
    long long ans = 0;
    for (auto e : mm) ans += e.second * (e.second - 1);
    for (auto e : m2) ans -= e.second * (e.second - 1);
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //cout << "\n";

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n;
    cin >> n;
    map<pair<int, int>, ll> mm;
    for (int i = 0; i < n; i++)
    {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        u -= x, v -= y;
        int g = __gcd(abs(u), abs(v));
        u /= g, v /= g;
        mm[{u, v}]++;
    }
    ll ans = 0;
    for (auto e : mm)
    {
        ans += mm[{-e.first.first, -e.first.second}] * e.second;
    }
    cout << ans / 2 << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
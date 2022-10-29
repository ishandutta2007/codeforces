#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
vector<ll> g[N];
ll s[N];
map<pair<ll, ll>, ll> mp;

ll dfs(ll u, ll k, ll sum) {
    if (mp.count({u, k})) return mp[{u, k}];
    sum += s[u];
    if (g[u].size() == 0) return k * sum;
    ll ans = 0;
    ll num = k / g[u].size();
    ll yu = k % g[u].size();
    vector<ll> vec;
    for (ll v: g[u]) {
        ll tmp = dfs(v, num, sum);
        ans += tmp;
        if (yu) vec.push_back(dfs(v, num + 1, sum) - tmp);
    }
    sort(vec.rbegin(), vec.rend());
    if (yu) {
        for (ll i = 0; i < yu; i++) {
            ans += vec[i];
        }
    }
    return mp[{u, k}] = ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        mp.clear();
        ll n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) g[i].clear();
        for (ll i = 2; i <= n; i++) {
            ll fa;
            cin >> fa;
            g[fa].push_back(i);
        }
        for (ll i = 1; i <= n; i++) cin >> s[i];
        ll ans = dfs(1, k, 0);
        cout << ans << endl;
    }
}
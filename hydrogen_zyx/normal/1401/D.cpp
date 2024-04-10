#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
vector<ll> g[300000];
ll n;
ll a[100000];
vector<ll> v;
ll dfs(ll u, ll fa) {
    ll sub = 1;
    for (int i = 0; i < g[u].size(); i++) {
        ll v = g[u][i];
        if (v == fa) continue;
        sub += dfs(v, u);
    }
    if (fa != -1) v.push_back(sub * (n - sub));
    return sub;
}
ll cmp(ll a, ll b) { return a > b; }
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) g[i].clear();
        v.clear();
        for (int i = 1; i < n; i++) {
            ll a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1, -1);
        sort(v.begin(), v.end(), cmp);
        ll k;
        cin >> k;
        for (int i = 1; i <= k; i++) cin >> a[i];
        sort(a + 1, a + 1 + k, cmp);
        ll ans = 0;
        if (k > v.size()) {
            ll cnt = v[0];
            ll fir = k - v.size() + 1;
            for (int i = 1; i <= fir; i++) cnt = (cnt * a[i]) % mod;
            ans = cnt;
            for (int i = 1; i < v.size(); i++) {
                cnt = v[i];
                ans = (ans + cnt * a[fir + i]) % mod;
            }
        } else {
            for (int i = 0; i < v.size(); i++) {
                ll cnt = v[i];
                if (i < k)
                    ans = (ans + cnt * a[i + 1]) % mod;
                else
                    ans = (ans + cnt) % mod;
            }
        }
        cout << ans << endl;
    }
}
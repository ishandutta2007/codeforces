#include<bits/stdc++.h>

using namespace std;
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define de(x) cout<< #x << ' ' << x << endl;
typedef long long ll;
const ll N = 1e6 + 5;
const ll mod = 1e9 + 7;

vector<ll> g[N];
ll l[N], r[N];
ll ans = 0;

ll dfs(ll u) {
    ll sum = 0;
    for (auto x: g[u]) {
        sum += dfs(x);
    }
    if (sum < l[u]) {
        ans++;
        sum = r[u];
    } else {
        sum = min(sum, r[u]);
    }
    return sum;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        for (ll i = 1; i <= n; i++) g[i].clear();
        for (ll i = 2; i <= n; i++) {
            ll f;
            cin >> f;
            g[f].push_back(i);
        }
        ans = 0;
        for (ll i = 1; i <= n; i++) cin >> l[i] >> r[i];
        dfs(1);
        cout << ans << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> g[300000];
ll cost[300000];
ll change[300000];
ll fa[300000];
ll pos[300000];
ll neg[300000];
ll ans = 0;
void dfs(ll s, ll c) {
    cost[s] = min(cost[s], c);
    for (ll i = 0; i < g[s].size(); i++) {
        if (g[s][i] == fa[s]) continue;
        fa[g[s][i]] = s;
        dfs(g[s][i], cost[s]);
        pos[s] += pos[g[s][i]];
        neg[s] += neg[g[s][i]];
    }
    if (change[s] == 1)
        pos[s]++;
    else if (change[s] == -1)
        neg[s]++;
    ll k = min(pos[s], neg[s]);
    ans += k * cost[s] * 2;
    pos[s] -= k;
    neg[s] -= k;
}
int main() {
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        cost[i] = a;
        change[i] = b - c;
    }
    for (ll i = 1; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 1000000000);
    if (pos[1] == neg[1])
        cout << ans;
    else
        cout << -1;
}
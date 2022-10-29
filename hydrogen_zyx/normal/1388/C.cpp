#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> g[200000];
ll p[200000];
ll h[200000];
ll sub[200000];
ll hap[200000];
ll dfs(ll u, ll fa) {
    sub[u] = p[u];
    for (auto v : g[u]) {
        if (v == fa) continue;
        sub[u] += dfs(v, u);
    }
    return sub[u];
}
void dfs2(ll u, ll fa) {
    hap[u] = 0;
    for (auto v : g[u]) {
        if (v == fa) continue;
        hap[u] += h[v];
        dfs2(v, u);
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) cin >> h[i];
        for (int i = 1; i < n; i++) {
            ll a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1, -1);
        dfs2(1, -1);
        bool f = 1;
        for (int i = 1; i <= n; i++) {
            int nowhap = (sub[i] + h[i]) / 2LL;
            if ((sub[i] + h[i]) & 1LL) f = 0;
            int lashap = (sub[i] - p[i] + hap[i]) / 2;
            if ((sub[i] - p[i] + hap[i]) & 1) f = 0;
            if (nowhap < lashap) f = 0;
            if (abs(hap[i] + p[i] - h[i]) & 1) f = 0;
            if (nowhap < 0 || nowhap > sub[i]) f = 0;
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
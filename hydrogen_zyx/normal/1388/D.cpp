#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000000];
ll b[1000000];
vector<ll> g[1000000];
bool vis[1000000];
ll f[1000000];
vector<ll> root;
vector<ll> ans;
stack<ll> shun;
ll dfs(ll u, ll fa) {
    f[u] = fa;
    ll sum = a[u];
    for (auto v : g[u]) {
        if (v == fa) continue;
        ll p = dfs(v, u);
        if (p < 0)
            shun.push(v), vis[v] = 1;
        else
            sum += p;
    }
    return sum;
}
void dfs2(ll u, ll fa) {
    vis[u] = 1;
    for (auto v : g[u]) {
        if (f[u] == v) continue;
        if (vis[v]) continue;
        dfs2(v, u);
    }
    ans.push_back(u);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] == -1)
            root.push_back(i);
        else
            g[i].push_back(b[i]), g[b[i]].push_back(i);
    }
    for (auto t : root) {
        dfs(t, -1);
        shun.push(t);
    }
    while (!shun.empty()) {
        dfs2(shun.top(), -1);
        shun.pop();
    }
    ll tot = 0;
    for (auto x : ans) {
        tot += a[x];
        if (b[x] == -1) continue;
        a[b[x]] += a[x];
    }
    cout << tot << endl;
    for (auto x : ans) cout << x << ' ';
}
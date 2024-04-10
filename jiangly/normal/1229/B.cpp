#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
constexpr int MOD = 1e9+7;
void solve() {
    int n;
    cin >> n;
    vector<LL> x(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    vector<map<LL, int>> f(n);
    function<void(int, int)> dfs = [&](int u, int p) {
        ++f[u][x[u]];
        for (auto [a, c] : f[u])
            ans = (ans + a % MOD * c) % MOD;
        for (int v : g[u]) {
            if (v == p)
                continue;
            for (auto [a, c] : f[u])
                f[v][__gcd(a, x[v])] += c;
            dfs(v, u);
        }
    };
    dfs(0, -1);
    printf("%d\n", ans);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
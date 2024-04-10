#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<tuple<int, int, int>> vt(m);
        vector f(n + 1, vector<LL>(n + 1, n));
        vector<LL> g(n + 1);
        for (int i = 1; i <= n; i += 1)
            f[i][i] = 0;
        for (auto& [u, v, w] : vt) {
            cin >> u >> v >> w;
            f[u][v] = 1;
            f[v][u] = 1;
        }
        for (int k = 1; k <= n; k += 1)
            for (int i = 1; i <= n; i += 1)
                for (int j = 1; j <= n; j += 1)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        for (int i = 1; i <= n; i += 1) {
            g[i] = INT_MAX;
            for (int j = 1; j <= n; j += 1)
                g[i] = min(g[i], f[i][j] + f[j][1] + f[j][n]);
        }
        LL ans = LLONG_MAX;
        for (auto [u, v, w] : vt) {
            ans = min(ans, (LL)w * (f[1][u] + f[v][n] + 1));
            ans = min(ans, (LL)w * (f[1][v] + f[u][n] + 1));
            ans = min(ans, (LL)w * (g[u] + 2));
            ans = min(ans, (LL)w * (g[v] + 2));
        }
        cout << ans << "\n";
    }
}
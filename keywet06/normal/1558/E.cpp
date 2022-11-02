#include <bits/stdc++.h>

using int64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    int a[n], b[n];
    a[0] = b[0] = 0;
    for (int i = 1; i < n; ++i) std::cin >> a[i], ++a[i];
    for (int i = 1; i < n; ++i) std::cin >> b[i];
    std::vector<int> adj[n];
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v, --u, --v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    int lo = 1, hi = 1E9 + 1;
    while (lo < hi) {
        int x = (lo + hi) / 2;
        bool vis[n];
        std::memset(vis, 0, sizeof(vis));
        vis[0] = true;
        int cntvis = 1;
        int64 cur = x;
        while (cntvis < n) {
            bool f[n];
            std::memcpy(f, vis, sizeof(f));
            int parent[n];
            std::memset(parent, -1, sizeof(parent));
            bool nice = 0;
            std::function<bool(int, int64)> dfs = [&](int u, int64 w) {
                f[u] = true;
                w += b[u];
                for (auto v : adj[u]) {
                    if (v == parent[u] || w < a[v]) continue;
                    if (!f[v]) {
                        parent[v] = u;
                        if (dfs(v, w)) return true;
                    } else {
                        for (int i = u; i != -1; i = parent[i]) {
                            if (!vis[i]) vis[i] = true, ++cntvis, cur += b[i];
                        }
                        for (int i = v; i != -1; i = parent[i]) {
                            if (!vis[i]) vis[i] = true, ++cntvis, cur += b[i];
                        }
                        return true;
                    }
                }
                return false;
            };
            for (int u = 0; u < n; ++u) {
                if (!vis[u]) {
                    continue;
                }
                for (auto v : adj[u]) {
                    if (vis[v]) continue;
                    if (cur >= a[v]) {
                        parent[v] = u;
                        if (dfs(v, cur) && (nice = true)) break;
                    }
                }
                if (nice) break;
            }
            if (!nice) break;
        }
        if (cntvis == n) {
            hi = x;
        } else {
            lo = x + 1;
        }
    }
    std::cout << lo << "\n";
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int T;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
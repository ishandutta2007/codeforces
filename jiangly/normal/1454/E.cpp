#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> e(n);
        for (int i = 0; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            --u, --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        std::vector<int> parent(n, -1);
        std::vector<bool> circle(n), vis(n);
        bool found = false;
        std::function<void(int)> dfs1 = [&](int u) {
            vis[u] = true;
            for (auto v : e[u]) {
                if (v == parent[u]) continue;
                if (vis[v]) {
                    for (int x = u; x != parent[v]; x = parent[x]) circle[x] = true;
                    found = true;
                    return;
                }
                parent[v] = u;
                dfs1(v);
                if (found) return;
            }
        };
        dfs1(0);
        std::function<int(int)> dfs2 = [&](int u) {
            int siz = 1;
            for (auto v : e[u]) {
                if (v == parent[u] || circle[v]) continue;
                parent[v] = u;
                siz += dfs2(v);
            }
            return siz;
        };
        parent.assign(n, -1);
        int64_t ans = int64_t(n) * (n - 1);
        for (int i = 0; i < n; ++i) {
            if (circle[i]) {
                int x = dfs2(i);
                ans -= int64_t(x) * (x - 1) / 2;
            }
        }
        std::cout << ans << "\n";
    }
    
    return 0;
}
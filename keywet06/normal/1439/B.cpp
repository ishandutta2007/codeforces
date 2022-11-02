#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--) {
        int n, m, k;
        std::cin >> n >> m >> k;

        std::vector<std::vector<int>> e(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            --u, --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        std::vector<int> deg(n);
        for (int i = 0; i < n; ++i) {
            std::sort(e[i].begin(), e[i].end());
            deg[i] = e[i].size();
        }
        std::queue<int> que;
        std::vector<int> vis(n);
        for (int i = 0; i < n; ++i) {
            if (deg[i] < k) {
                vis[i] = true;
                que.push(i);
            }
        }

        std::vector<int> clique;
        while (!que.empty()) {
            int u = que.front();
            que.pop();

            vis[u] = 2;

            if (deg[u] == k - 1 && clique.empty() &&
                int64_t(k) * (k - 1) / 2 <= m) {
                clique = {u};
                for (auto v : e[u])
                    if (vis[v] <= 1) clique.push_back(v);
                bool ok = true;
                for (auto u : clique) {
                    for (auto v : clique) {
                        if (u == v) break;
                        if (!std::binary_search(e[u].begin(), e[u].end(), v))
                            ok = false;
                    }
                }
                if (!ok) clique.clear();
            }

            for (auto v : e[u]) {
                if (--deg[v] < k && !vis[v]) {
                    vis[v] = 1;
                    que.push(v);
                }
            }
        }
        if (std::count(vis.begin(), vis.end(), 0) > 0) {
            std::vector<int> ans;
            for (int i = 0; i < n; ++i)
                if (!vis[i]) ans.push_back(i);
            std::cout << 1 << " " << ans.size() << "\n";
            for (int i = 0; i < int(ans.size()); ++i)
                std::cout << ans[i] + 1 << " \n"[i == int(ans.size()) - 1];
        } else if (!clique.empty()) {
            std::cout << 2 << "\n";
            for (int i = 0; i < k; ++i)
                std::cout << clique[i] + 1 << " \n"[i == k - 1];
        } else
            std::cout << -1 << "\n";
    }

    return 0;
}
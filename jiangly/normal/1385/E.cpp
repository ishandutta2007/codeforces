#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> e(n);
        std::vector<int> deg(n), pos(n);
        std::vector<std::pair<int, int>> edges;
        for (int i = 0; i < m; ++i) {
            int x, u, v;
            std::cin >> x >> u >> v;
            --u;
            --v;
            edges.emplace_back(u, v);
            if (x == 1) {
                e[u].push_back(v);
                ++deg[v];
            }
        }
        std::queue<int> que;
        for (int i = 0; i < n; ++i)
            if (deg[i] == 0)
                que.push(i);
        int cnt = 0;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            pos[u] = cnt++;
            for (auto v : e[u])
                if (--deg[v] == 0)
                    que.push(v);
        }
        if (cnt != n) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
            for (auto [u, v] : edges) {
                if (pos[u] > pos[v])
                    std::swap(u, v);
                std::cout << u + 1 << " " << v + 1 << "\n";
            }
        }
    }
    return 0;
}
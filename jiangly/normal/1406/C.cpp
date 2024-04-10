#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> siz(n), parent(n);
        std::vector<std::vector<int>> e(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            --u;
            --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        std::function<void(int)> dfs = [&](int u) {
            siz[u] = 1;
            for (auto v : e[u]) {
                if (v == parent[u])
                    continue;
                parent[v] = u;
                dfs(v);
                siz[u] += siz[v];
            }
        };
        parent[0] = -1;
        dfs(0);
        std::function<int(int)> find = [&](int u) {
            for (auto v : e[u])
                if (v != parent[u] && 2 * siz[v] >= n)
                    return find(v);
            return u;
        };
        int cen = find(0);
        if (siz[cen] * 2 == n) {
            int p = parent[cen];
            int v = e[p][e[p][0] == cen];
            std::cout << p + 1 << " " << v + 1 << "\n";
            std::cout << cen + 1 << " " << v + 1 << "\n";
        } else {
            std::cout << 1 << " " << e[0][0] + 1 << "\n";
            std::cout << 1 << " " << e[0][0] + 1 << "\n";
        }
    }
    return 0;
}
#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> c(n), h(n);
        for (int i = 0; i < n; ++i)
            std::cin >> c[i];
        for (int i = 0; i < n; ++i)
            std::cin >> h[i];
        std::vector<std::vector<int>> e(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            --u;
            --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        bool ok = true;
        std::function<void(int, int)> dfs = [&](int u, int p) {
            int64_t sum = 0;
            for (auto v : e[u]) {
                if (v == p)
                    continue;
                dfs(v, u);
                c[u] += c[v];
                sum += h[v];
            }
            h[u] += c[u];
            if (h[u] % 2 != 0)
                ok = false;
            if (h[u] > 2 * c[u])
                ok = false;
            if (h[u] < sum)
                ok = false;
        };
        dfs(0, -1);
        if (ok) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<std::pair<int, int>>> e(n);
        int64_t S;
        std::cin >> S;
        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            --u;
            --v;
            e[u].emplace_back(v, w);
            e[v].emplace_back(u, w);
        }
        std::vector<int> siz(n), weight(n);
        std::function<void(int, int)> dfs = [&](int u, int p) {
            if (p != -1 && e[u].size() == 1)
                siz[u] = 1;
            for (auto [v, w] : e[u]) {
                if (v == p)
                    continue;
                weight[v] = w;
                dfs(v, u);
                siz[u] += siz[v];
            }
        };
        dfs(0, -1);
        for (int i = 1; i < n; ++i)
            S -= 1ll * siz[i] * weight[i];
        std::priority_queue<std::pair<int64_t, int>> h;
        for (int i = 1; i < n; ++i)
            h.emplace(1ll * siz[i] * ((weight[i] + 1) / 2), i);
        int ans = 0;
        while (S < 0) {
            auto [w, u] = h.top();
            h.pop();
            ++ans;
            S += w;
            weight[u] /= 2;
            h.emplace(1ll * siz[u] * ((weight[u] + 1) / 2), u);
        }
        std::cout << ans << "\n";
    }
    return 0;
}
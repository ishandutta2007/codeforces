#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<std::tuple<int, int, int>>> e(n);
        int64_t S;
        std::cin >> S;
        for (int i = 0; i < n - 1; ++i) {
            int u, v, w, c;
            std::cin >> u >> v >> w >> c;
            --u;
            --v;
            e[u].emplace_back(v, w, c);
            e[v].emplace_back(u, w, c);
        }
        std::vector<int> siz(n), weight(n), cost(n);
        std::function<void(int, int)> dfs = [&](int u, int p) {
            if (p != -1 && e[u].size() == 1)
                siz[u] = 1;
            for (auto [v, w, c] : e[u]) {
                if (v == p)
                    continue;
                weight[v] = w;
                cost[v] = c;
                dfs(v, u);
                siz[u] += siz[v];
            }
        };
        dfs(0, -1);
        for (int i = 1; i < n; ++i)
            S -= 1ll * siz[i] * weight[i];
        int ans = 1e9;
        std::vector<int64_t> v[2];
        for (int i = 1; i < n; ++i)
            for (; weight[i] > 0; weight[i] /= 2)
                v[cost[i] - 1].push_back(1ll * siz[i] * ((weight[i] + 1) / 2));
        for (int c = 0; c < 2; ++c)
            std::sort(v[c].begin(), v[c].end(), std::greater<>());
        int64_t res = 0;
        for (auto x : v[0])
            res += x;
        for (int i = 0, j = v[0].size(); i <= int(v[1].size()); ++i) {
            while (j > 0 && res - v[0][j - 1] + S >= 0) {
                --j;
                res -= v[0][j];
            }
            if (res + S >= 0)
                ans = std::min(ans, 2 * i + j);
            if (i < int(v[1].size()))
                res += v[1][i];
        }
        std::cout << ans << "\n";
    }
    return 0;
}
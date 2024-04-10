#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<std::pair<int, int>>> e(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        --u;
        --v;
        e[u].emplace_back(w, v);
    }
    int id[10][10] = {};
    int cnt = 0;
    for (int i = 1; i <= k; ++i)
        for (int j = 0; j < i; ++j)
            id[i][j] = cnt++;
    std::vector<int64_t> can(45, (1ll << 45) - 1);
    int ans = 0;
    std::vector<std::vector<std::pair<int, int>>> lim(n);
    for (int i = 0; i < n; ++i) {
        std::sort(e[i].begin(), e[i].end());
        for (int j = 0; j < int(e[i].size()); ++j) {
            int v = e[i][j].second;
            lim[v].emplace_back(e[i].size(), j);
        }
    }
    for (int i = 0; i < n; ++i) {
        int cnt[45] = {};
        for (auto [x, y] : lim[i]) {
            ++cnt[id[x][y]];
        }
        for (int x = 0; x < 45; ++x) {
            if (!cnt[x])
                continue;
            if (cnt[x] > 1)
                can[x] = 0;
            for (int y = 0; y < 45; ++y)
                if (x != y && cnt[y])
                    can[x] &= ~(1ll << y);
        }
    }
    std::function<void(int, int64_t)> dfs = [&](int x, int64_t mask) {
        if (x > k) {
            ++ans;
            return;
        }
        for (int i = 0; i < x; ++i) {
            if (can[id[x][i]] && (mask >> id[x][i] & 1)) {
                dfs(x + 1, mask & can[id[x][i]]);
            }
        }
    };
    dfs(1, (1ll << 45) - 1);
    std::cout << ans << "\n";
    return 0;
}
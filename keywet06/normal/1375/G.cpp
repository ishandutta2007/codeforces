#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    std::vector<int> dep(n);
    std::function<void(int, int)> dfs = [&](int u, int p) {
        for (auto v : e[u]) {
            if (v == p) continue;
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    };
    dfs(0, -1);
    std::vector<int> cnt(2);
    for (int i = 0; i < n; ++i) ++cnt[dep[i] % 2];
    std::cout << std::min(cnt[0], cnt[1]) - 1 << "\n";
    return 0;
}
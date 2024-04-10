#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> l(n), r(n);
        std::vector<std::vector<int>> e(n);
        for (int i = 0; i < n; i++) {
            std::cin >> l[i] >> r[i];
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            std::cin >> u >> v;
            u--;
            v--;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        std::vector<i64> f0(n), f1(n);
        std::function<void(int, int)> dfs = [&](int u, int p) {
            for (auto v : e[u]) {
                if (v == p) {
                    continue;
                }
                dfs(v, u);
                f0[u] += std::max(f0[v] + std::abs(l[u] - l[v]), f1[v] + std::abs(l[u] - r[v]));
                f1[u] += std::max(f0[v] + std::abs(r[u] - l[v]), f1[v] + std::abs(r[u] - r[v]));
            }
        };
        dfs(0, -1);
        std::cout << std::max(f0[0], f1[0]) << "\n";
    }
    return 0;
}
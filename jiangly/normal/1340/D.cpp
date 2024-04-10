#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <deque>
#include <tuple>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = std::max(ans, int(e[i].size()));
    std::vector<std::pair<int, int>> steps;
    std::function<void(int, int, int)> dfs = [&](int u, int t, int p) {
        steps.emplace_back(u, t);
        int cur = t, rest = e[u].size() - (p != -1);
        for (auto v : e[u]) {
            if (v == p)
                continue;
            if (cur == ans) {
                cur = t - 1 - rest;
                steps.emplace_back(u, cur);
            }
            dfs(v, cur + 1, u);
            --rest;
            ++cur;
            steps.emplace_back(u, cur);
        }
        if (u == 0)
            return;
        if (cur != t - 1)
            steps.emplace_back(u, t - 1);
    };
    dfs(0, 0, -1);
    std::cout << steps.size() << "\n";
    for (auto [u, t] : steps)
        std::cout << u + 1 << " " << t << "\n";
    return 0;
}
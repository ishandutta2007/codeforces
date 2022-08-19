#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    std::vector<int> val(n);
    std::function<int(int, int, int)> dfs = [&](int u, int p, int d) {
        int sz = 1;
        for (auto v : e[u]) {
            if (v == p)
                continue;
            sz += dfs(v, u, d + 1);
        }
        val[u] = d + 1 - sz;
        return sz;
    };
    dfs(0, -1, 0);
    std::sort(val.begin(), val.end(), std::greater<>());
    std::cout << std::accumulate(val.begin(), val.begin() + k, 0ll) << "\n";
    return 0;
}
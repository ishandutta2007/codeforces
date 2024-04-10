#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int min, max;
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    bool even = true;
    std::function<void(int, int, int)> dfs = [&](int u, int p, int d) {
        int cnt = 0;
        for (auto v : e[u]) {
            if (v == p)
                continue;
            ++cnt;
            dfs(v, u, d + 1);
        }
        if (cnt == 0 && d % 2 == 1)
            even = false;
    };
    int s = 0;
    while (e[s].size() > 1)
        ++s;
    dfs(s, -1, 0);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        if (e[i].size() == 1)
            ++a[e[i][0]];
    min = even ? 1 : 3;
    max = n - 1;
    for (int i = 0; i < n; ++i)
        if (a[i] > 0)
            max -= a[i] - 1;
    std::cout << min << " " << max << "\n";
    return 0;
}
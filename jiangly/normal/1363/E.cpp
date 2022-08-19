#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <chrono>
#include <queue>
#include <set>
#include <cassert>
#include <random>
#include <chrono>
#include <complex>
#include <cstring>
#include <map>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i] >> b[i] >> c[i];
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    std::vector<int> x(n), y(n);
    long long ans = 0;
    std::function<void(int, int)> dfs = [&](int u, int p) {
        if (b[u] > c[u]) {
            ++x[u];
        } else if (b[u] < c[u]) {
            ++y[u];
        }
        for (auto v : e[u]) {
            if (v == p)
                continue;
            a[v] = std::min(a[u], a[v]);
            dfs(v, u);
            x[u] += x[v];
            y[u] += y[v];
        }
        int z = std::min(x[u], y[u]);
        ans += 2ll * z * a[u];
        x[u] -= z;
        y[u] -= z;
    };
    dfs(0, -1);
    if (!x[0] && !y[0]) {
        std::cout << ans << "\n";
    } else {
        std::cout << -1 << "\n";
    }
    return 0;
}
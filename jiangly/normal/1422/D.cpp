#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    int sx, sy, fx, fy;
    std::cin >> sx >> sy >> fx >> fy;
    std::vector<int> x(m), y(m);
    for (int i = 0; i < m; ++i) std::cin >> x[i] >> y[i];
    std::vector<std::vector<std::pair<int, int>>> e(m);
    std::vector<int> a(m);
    std::iota(a.begin(), a.end(), 0);
    std::sort(a.begin(), a.end(), [&](int i, int j) {return x[i] < x[j];});
    for (int i = 0; i + 1 < m; ++i) {
        e[a[i]].emplace_back(a[i + 1], x[a[i + 1]] - x[a[i]]);
        e[a[i + 1]].emplace_back(a[i], x[a[i + 1]] - x[a[i]]);
    }
    std::sort(a.begin(), a.end(), [&](int i, int j) {return y[i] < y[j];});
    for (int i = 0; i + 1 < m; ++i) {
        e[a[i]].emplace_back(a[i + 1], y[a[i + 1]] - y[a[i]]);
        e[a[i + 1]].emplace_back(a[i], y[a[i + 1]] - y[a[i]]);
    }
    std::priority_queue<std::pair<int64_t, int>> h;
    int64_t ans = std::abs(sx - fx) + std::abs(sy - fy);
    std::vector<int64_t> dis(m);
    std::vector<bool> vis(m);
    for (int i = 0; i < m; ++i) h.emplace(-std::min(std::abs(sx - x[i]), std::abs(sy - y[i])), i);
    while (!h.empty()) {
        auto [d, u] = h.top();
        h.pop();
        if (vis[u]) continue;
        vis[u] = true;
        d = -d;
        dis[u] = d;
        for (auto [v, w] : e[u]) h.emplace(-d - w, v);
    }
    for (int i = 0; i < m; ++i) ans = std::min(ans, dis[i] + std::abs(x[i] - fx) + std::abs(y[i] - fy));
    std::cout << ans << "\n";
    
    return 0;
}
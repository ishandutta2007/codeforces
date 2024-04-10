#include <bits/stdc++.h>

const int INF = 2e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> f(n), g;
    for (int i = 0; i < n; ++i) std::cin >> f[i].first >> f[i].second;
    std::sort(f.begin(), f.end());
    g = f;
    std::stable_sort(g.begin(), g.end(), [&](const auto &a, const auto &b) { return a.second < b.second; });
    std::vector<std::pair<int, int>> diag{{0, 0}}, good;
    int x = 0, y = 0;
    int i = 0, j = 0;
    while (i < n && f[i].first == 0) ++i;
    while (j < n && g[j].second == 0) ++j;
    while (i < n || j < n) {
        int dx = i == n ? INF : f[i].first - x;
        int dy = j == n ? INF : g[j].second - y;
        int t = std::min(dx, dy);
        x += t, y += t;
        bool left = false, mid = false, right = false;
        while (i < n && f[i].first == x) mid |= f[i].second == y, right |= f[i].second < y, ++i;
        while (j < n && g[j].second == y) mid |= g[j].first == x, left |= g[j].first < x, ++j;
        if (!mid && (left || right)) {
            good.emplace_back(x, y);
            x -= bool(left), y -= bool(right);
            diag.emplace_back(x + 1, y + 1);
        }
    }
    for (int i = 0; i < m; ++i) {
        std::pair<int, int> p;
        std::cin >> p.first >> p.second;
        if (std::binary_search(f.begin(), f.end(), p)) {
            std::cout << "LOSE\n";
        } else if (std::binary_search(good.begin(), good.end(), p)) {
            std::cout << "WIN\n";
        } else {
            auto q = *std::prev(std::upper_bound(diag.begin(), diag.end(), p));
            if (p.first - p.second == q.first - q.second) {
                std::cout << "LOSE\n";
            } else {
                std::cout << "WIN\n";
            }
        }
    }
    return 0;
}
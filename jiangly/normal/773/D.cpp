#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<std::tuple<int, int, int>> e;
    e.reserve(n * (n - 1) / 2);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int w;
            std::cin >> w;
            e.emplace_back(w, i, j);
        }
    }
    
    std::vector<i64> f(n, 1e18);
    std::sort(e.begin(), e.end());
    auto [mn, i, j] = e[0];
    f[i] = f[j] = 1LL * (n - 1) * mn;
    i64 g = f[i];
    for (auto [w, i, j] : e) {
        f[i] = std::min({f[i], f[j] + w - mn, g + 2 * (w - mn)});
        f[j] = std::min({f[j], f[i] + w - mn, g + 2 * (w - mn)});
        g = std::min({g, f[i], f[j]});
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << f[i] << "\n";
    }
    
    return 0;
}
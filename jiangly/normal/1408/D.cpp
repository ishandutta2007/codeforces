#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> a(n), b(m);
    for (int i = 0; i < n; ++i) std::cin >> a[i].first >> a[i].second;
    for (int i = 0; i < m; ++i) std::cin >> b[i].first >> b[i].second;
    int f[1000002] = {};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int dx = b[j].first - a[i].first;
            int dy = b[j].second - a[i].second;
            if (dx < 0) continue;
            f[dx] = std::max(f[dx], dy + 1);
        }
    }
    for (int i = 1000000; i >= 0; --i) f[i] = std::max(f[i], f[i + 1]);
    int ans = 1e9;
    for (int i = 0; i <= 1000001; ++i) ans = std::min(ans, i + f[i]);
    std::cout << ans << "\n";
    
    return 0;
}
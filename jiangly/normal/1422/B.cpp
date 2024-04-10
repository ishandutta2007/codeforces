#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> a(n, std::vector<int>(m));
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) std::cin >> a[i][j];
        int64_t ans = 0;
        for (int i = 0; 2 * i < n; ++i) {
            for (int j = 0; 2 * j < m; ++j) {
                std::vector<int> v{a[i][j]};
                if (i != n - i - 1) v.push_back(a[n - i - 1][j]);
                if (j != m - j - 1) v.push_back(a[i][m - j - 1]);
                if (i != n - i - 1 && j != m - j - 1) v.push_back(a[n - i - 1][m - j - 1]);
                std::sort(v.begin(), v.end());
                int x = v[(v.size() - 1) / 2];
                for (auto y : v) ans += std::abs(x - y);
            }
        }
        std::cout << ans << "\n";
    }
    
    return 0;
}
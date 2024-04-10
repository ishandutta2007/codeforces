#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> p(n), x(m);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> x[i];
    }
    std::sort(x.begin(), x.end());
    
    std::vector<std::array<int, 2>> a;
    
    for (int i = 0, j = 0; i < n; i++) {
        while (j < m && x[j] < 100 * i) {
            j++;
        }
        int d = 1E9;
        if (j < m) {
            d = std::min(d, std::abs(100 * i - x[j]));
        }
        if (j > 0) {
            d = std::min(d, std::abs(100 * i - x[j - 1]));
        }
        
        a.push_back({100 * i - d, p[i]});
        a.push_back({100 * i + d, -p[i]});
    }
    
    i64 ans = 0, cur = 0;
    std::sort(a.begin(), a.end());
    for (auto [x, y] : a) {
        cur += y;
        ans = std::max(ans, cur);
    }
    
    std::cout << ans << "\n";
    
    return 0;
}
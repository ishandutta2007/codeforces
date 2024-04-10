#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int x, y, p, q;
        std::cin >> x >> y >> p >> q;
        
        if (p == 0) {
            std::cout << (x == 0 ? 0 : -1) << "\n";
            continue;
        }
        
        if (p == q) {
            std::cout << (x == y ? 0 : -1) << "\n";
            continue;
        }
        
        int t = std::max((x + p - 1) / p, (y - x + q - p - 1) / (q - p));
        
        i64 ans = 1LL * q * t - y;
        std::cout << ans << "\n";
    }
    
    return 0;
}
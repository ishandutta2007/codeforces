#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, L;
    std::cin >> n >> L;
    
    std::vector<i64> c(30, 1e18);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    for (int i = 28; i >= 0; i--) {
        c[i] = std::min(c[i], c[i + 1]);
    }
    for (int i = 1; i < 30; i++) {
        c[i] = std::min(c[i], 2 * c[i - 1]);
    }
    
    i64 ans = 1e18, res = 0;
    for (int i = 29; i >= 0; i--) {
        if (L >> i & 1) {
            res += c[i];
        }
        ans = std::min(ans, res + c[i]);
    }
    ans = std::min(ans, res);
    
    std::cout << ans << "\n";
    
    return 0;
}
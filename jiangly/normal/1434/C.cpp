#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int64_t a, b, c, d;
        std::cin >> a >> b >> c >> d;
        if (a - b * c > 0) {
            std::cout << -1 << "\n";
            continue;
        }
        int64_t l = 0, r = c;
        while (l < r) {
            int64_t k = (l + r + 1) / 2;
            int64_t sum = std::min(c, d * k);
            if (sum <= a / b) l = k;
            else r = k - 1;
        }
        int64_t k = l;
        int64_t dam = (k + 1) * a;
        int64_t lim = c / d;
        if (lim >= k) lim = k;
        dam -= ((k - lim) * c + d * (lim + 1) * lim / 2) * b;
        std::cout << dam << "\n";
    }
    
    return 0;
}
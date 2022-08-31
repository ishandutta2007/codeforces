#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 k, x;
    std::cin >> k >> x;
    
    if (x <= k * (k + 1) / 2) {
        i64 t = std::sqrt(x * 2) - 1;
        while (t * (t + 1) / 2 < x) {
            t++;
        }
        std::cout << t << '\n';
    } else {
        x -= k * (k + 1) / 2;
        if (x >= k * (k - 1) / 2) {
            std::cout << 2 * k - 1 << '\n';
            return;
        }
        i64 t = k - 2 - std::sqrt(k * (k - 1) - x * 2);
        while (t < 0 || t * (k - 1 + k - t) / 2 < x) {
            t++;
        }
        std::cout << k + t << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
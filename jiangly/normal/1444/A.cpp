#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int64_t p;
        int q;
        std::cin >> p >> q;
        std::vector<int> a;
        int x = q;
        int64_t ans = 1;
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                a.push_back(i);
                while (x % i == 0) x /= i;
            }
        }
        if (x > 1) a.push_back(x);
        for (auto p0 : a) {
            int64_t x = p;
            int v = 1;
            while (q / p0 % v == 0) v *= p0;
            v /= p0;
            while (p % v != 0) v /= p0;
            while (x % p0 == 0) x /= p0;
            ans = std::max(ans, x * v);
        }
        std::cout << ans << "\n";
    }
    
    return 0;
}
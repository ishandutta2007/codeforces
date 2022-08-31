#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        i64 k;
        std::cin >> n >> k;
        i64 a0, g = 0;
        std::cin >> a0;
        for (int i = 1; i < n; i++) {
            i64 x;
            std::cin >> x;
            g = std::gcd(g, x - a0);
        }
        if ((k - a0) % g == 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
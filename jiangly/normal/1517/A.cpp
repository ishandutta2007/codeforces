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
        i64 n;
        std::cin >> n;
        if (n % 2050 != 0) {
            std::cout << "-1\n";
        } else {
            n /= 2050;
            int ans = 0;
            while (n > 0) {
                ans += n % 10;
                n /= 10;
            }
            std::cout << ans << "\n";
        }
    }
    return 0;
}
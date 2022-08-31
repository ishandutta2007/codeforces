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
        std::cin >> n;
        int ans = 0;
        for (int d = 1, x = 1; d <= 9; d++, x = x * 10 + 1) {
            ans += std::min(9, n / x);
        }
        std::cout << ans << "\n";
    }
    return 0;
}
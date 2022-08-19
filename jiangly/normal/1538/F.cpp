#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int l, r;
        std::cin >> l >> r;
        i64 ans = 0;
        for (int i = 0, p = 1; i <= 9; i++, p *= 10) {
            ans += r / p - l / p;
        }
        std::cout << ans << "\n";
    }
    return 0;
}
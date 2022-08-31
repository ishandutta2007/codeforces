#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n + 2);
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
        }
        i64 ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += std::abs(a[i] - a[i + 1]);
        }
        for (int i = 1; i <= n; i++) {
            ans -= std::max(0, a[i] - std::max(a[i + 1], a[i - 1]));
        }
        std::cout << ans << "\n";
    }
    return 0;
}
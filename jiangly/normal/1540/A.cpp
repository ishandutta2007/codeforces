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
        std::vector<int> d(n);
        for (int i = 0; i < n; i++) {
            std::cin >> d[i];
        }
        std::sort(d.begin(), d.end());
        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            ans += i64(d[i]) * (std::max(0, n - i - 2) - std::max(0, i - 1));
        }
        std::cout << ans << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, l, r;
        std::cin >> n >> l >> r;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end());
        i64 ans = 0;
        for (int i = 0, L = n, R = n; i < n; i++) {
            while (L && a[L - 1] + a[i] >= l) {
                L--;
            }
            while (R && a[R - 1] + a[i] > r) {
                R--;
            }
            ans += std::min(i, R) - std::min(i, L);
        }
        std::cout << ans << "\n";
    }
    return 0;
}
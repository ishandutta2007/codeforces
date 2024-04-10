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
        int n, k;
        std::cin >> n >> k;
        int l = 0, r = 0;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            int h;
            std::cin >> h;
            if (i == 0) {
                l = r = h;
            } else {
                l = std::max(l - k + 1, h);
                r = std::min(r + k - 1, h + k - 1);
            }
            if (l > r) {
                ok = false;
            }
            if (i == n - 1 && l != h) {
                ok = false;
            }
        }
        if (ok) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
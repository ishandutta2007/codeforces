#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int l, r;
        std::cin >> l >> r;
        int64_t m;
        std::cin >> m;
        int a = -1, b = -1, c = -1;
        for (int x = l; x <= r; ++x) {
            int64_t y = m % x;
            if (x > m || 2 * y > x)
                y -= x;
            if (std::abs(y) <= r - l) {
                a = x;
                if (y < 0) {
                    b = l;
                    c = l - y;
                } else {
                    b = r;
                    c = r - y;
                }
                break;
            }
        }
        std::cout << a << " " << b << " " << c << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int x, y, a, b;
        std::cin >> x >> y >> a >> b;
        if (a == b) {
            std::cout << std::min(x, y) / a << "\n";
            continue;
        }
        if (a < b) {
            std::swap(a, b);
        }
        int l = 0, r = (x + y) / (a + b);
        while (l < r) {
            int k = (l + r + 1) / 2;
            int L = std::max(0, (k * a - y + a - b - 1) / (a - b));
            int R = std::min(k, (x - k * b + a - b) / (a - b) - 1);
            if (L <= R) {
                l = k;
            } else {
                r = k - 1;
            }
        }
        std::cout << l << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cout << ((1ll * (i & 1)) << (i + j)) << " \n"[j == n - 1];
    int q;
    std::cin >> q;
    while (q--) {
        int64_t k;
        std::cin >> k;
        std::cout << 1 << " " << 1 << "\n";
        int x = 0, y = 0;
        for (int t = 1; t <= 2 * n - 2; ++t) {
            if ((k >> t & 1) != (x & 1)) {
                ++x;
            } else {
                ++y;
            }
            std::cout << x + 1 << " " << y + 1 << "\n";
        }
    }
    return 0;
}
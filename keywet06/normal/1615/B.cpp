#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        int l, r;
        std::cin >> l >> r;
        auto Get = [](int x, int c) {
            return (x >> c + 1 << c) +
                   (x & (1 << c) ? x - (x >> c << c) + 1 : 0);
        };
        int Max = 0;
        for (int i = 0; 1 << i <= r; ++i) {
            Max = std::max(Max, Get(r, i) - Get(l - 1, i));
        }
        std::cout << r - l + 1 - Max << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>

int T, a, b, l, r;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> a >> b;
        if ((a + b) & 1) {
            l = std::min(std::abs(a - (a + b) / 2), std::abs(b - (a + b) / 2));
            r = a + b - l;
            std::cout << r - l + 1 << '\n';
            for (int i = l; i <= r; ++i) std::cout << i << " \n"[i == r];
        } else {
            l = std::min(std::abs(a - (a + b) / 2), std::abs(b - (a + b) / 2));
            r = a + b - l;
            std::cout << (r - l) / 2 + 1 << '\n';
            for (int i = l; i <= r; ++++i) std::cout << i << " \n"[i == r];
        }
    }
    return 0;
}
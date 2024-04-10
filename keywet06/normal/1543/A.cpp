#include <bits/stdc++.h>

using int64 = long long;

int64 T, a, b, c, d;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> a >> b;
        std::cout << (c = std::abs(a - b)) << ' ';
        if (c == 0) {
            std::cout << 0 << std::endl;
            continue;
        }
        std::cout << std::min(a % c, c - a % c) << std::endl;
    }
    return 0;
}
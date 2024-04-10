#include <bits/stdc++.h>

int T, n, x, y, z;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        x = y = n / 3;
        if (n % 3 == 1) ++x;
        if (n % 3 == 2) ++y;
        std::cout << x << ' ' << y << '\n';
    }
    return 0;
}
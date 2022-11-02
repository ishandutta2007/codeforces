#include <bits/stdc++.h>

int T, x, y;

int main() {
    std::cin >> T;
    while (T--) {
        std::cin >> x >> y;
        std::cout << (x ^ y) << '\n';
    }
    return 0;
}
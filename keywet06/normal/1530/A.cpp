#include <bits/stdc++.h>

int T, n, c;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        c = 0;
        while (n) c = std::max(n % 10, c), n /= 10;
        std::cout << c << std::endl;
    }
    return 0;
}
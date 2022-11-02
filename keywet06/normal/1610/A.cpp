#include <bits/stdc++.h>

int T, n, m;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        std::cout << (n > 1 && m > 1) + (n + m > 2) << '\n';
    }
    return 0;
}
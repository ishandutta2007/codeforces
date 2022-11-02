#include <bits/stdc++.h>

int T, n, x, s;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n, s = 0;
        for (int i = 1; i <= n; ++i) std::cin >> x, s += x;
        std::cout << (s < n ? 1 : s - n) << std::endl;
    }
    return 0;
}
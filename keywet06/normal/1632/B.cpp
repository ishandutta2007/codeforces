// Luogu Remote

#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        int t = 1 << 31 - __builtin_clz(n - 1);
        for (int i = 1; i < t; ++i) std::cout << i << ' ';
        std::cout << 0;
        for (int i = t; i < n; ++i) std::cout << ' ' << i;
        std::cout << '\n';
    }
    return 0;
}
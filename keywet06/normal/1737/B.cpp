#include <bits/stdc++.h>

using uint64 = unsigned long long;

uint64 Solve(uint64 x) {
    uint64 l = 1, r = 1e9, m;
    while (l < r) m = l + r + 1 >> 1, m* m <= x ? l = m : r = m - 1;
    return (l - 1) * 3 + (l * l <= x) + (l * l + l <= x) + (l * l + l + l <= x);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        uint64 l, r;
        std::cin >> l >> r;
        std::cout << Solve(r) - Solve(l - 1) << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>

using int64 = long long;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        int64 Sum = 0;
        for (int i = 1, x; i <= n; ++i) std::cin >> x, Sum += x;
        std::cout << bool(Sum % n) << '\n';
    }
    return 0;
}
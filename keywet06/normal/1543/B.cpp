#include <bits/stdc++.h>

using int64 = long long;

int64 T, n, x, s;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n, s = 0;
        for (int i = 1; i <= n; ++i) std::cin >> x, s += x;
        s %= n;
        std::cout << s * (n - s) << std::endl;
    }
    return 0;
}
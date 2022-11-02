#include <bits/stdc++.h>

using int64 = long long;

int T;

int64 n;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        n = (n + 1) / 2;
        if (n < 3) n = 3;
        std::cout << n * 5 << std::endl;
    }
    return 0;
}
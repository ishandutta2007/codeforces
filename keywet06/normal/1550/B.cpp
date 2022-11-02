#include <bits/stdc++.h>

const int N = 1000005;

int T, n, x, y, p;

std::string s;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> y >> x;
        std::cin >> s;
        if (x >= 0) {
            std::cout << n * (x + y) << '\n';
        } else {
            p = 0;
            for (int i = 1; i < n; ++i) p += s[i] != s[i - 1];
            std::cout << (p + 3) / 2 * x + n * y << '\n';
        }
    }
    return 0;
}
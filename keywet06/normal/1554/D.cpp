#include <bits/stdc++.h>

int T, n;

inline void out(char c, int x) {
    while (x--) std::cout << c;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        if (n == 1) {
            out('a', 1);
        } else if (n & 1) {
            out('a', n / 2), out('b', 1), out('c', 1), out('a', n / 2 - 1);
        } else {
            out('a', n / 2), out('b', 1), out('a', n / 2 - 1);
        }
        std::cout << std::endl;
    }
    return 0;
}
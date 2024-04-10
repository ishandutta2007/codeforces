#include <bits/stdc++.h>

const int N = 1005;

int T, n, c, x;
int d[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        c = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> x;
            if (x == 1) {
                d[++c] = 1;
            } else {
                while (d[c] != x - 1) --c;
                ++d[c];
            }
            for (int i = 1; i < c; ++i) std::cout << d[i] << '.';
            std::cout << d[c] << std::endl;
        }
    }
    return 0;
}
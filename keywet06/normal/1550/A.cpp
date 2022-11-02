#include <bits/stdc++.h>

const int N = 1000005;

int T, n, x, y, c;
int a[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        x = 1, y = c = 0;
        while (++c) {
            y += x, x += 2;
            if (y >= n) break;
        }
        std::cout << c << '\n';
    }
    return 0;
}
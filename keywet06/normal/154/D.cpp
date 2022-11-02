#include <bits/stdc++.h>

using int64 = long long;

int64 c1, c2, a, b, d;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> c1 >> c2 >> a >> b;
    if (c2 >= c1 + a && c2 <= c1 + b) {
        std::cout << "FIRST" << '\n';
        std::cout << c2 << '\n';
    } else {
        d = c2 - c1;
        if (d > 0 && b < 0) {
            std::cout << "DRAW" << '\n';
        } else if (d < 0 && b > 0) {
            std::cout << "DRAW" << '\n';
        } else if (a <= 0 && 0 <= b) {
            std::cout << "DRAW" << '\n';
        } else {
            a = abs(a), b = abs(b);
            if (a > b) std::swap(a, b);
            d = abs(d) % (a + b);
            if (d == 0) {
                std::cout << "SECOND" << '\n';
            } else if (d < a || d > b) {
                std::cout << "DRAW" << '\n';
            } else {
                std::cout << "FIRST" << '\n';
                if (c1 < c2) {
                    std::cout << c1 + d << '\n';
                } else {
                    std::cout << c1 - d << '\n';
                }
            }
        }
    }
    return 0;
}
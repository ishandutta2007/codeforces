#include <bits/stdc++.h>

using int64 = long long;

int64 T, x, p;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> x, p = 2;
        while (p < x) p *= 4;
        std::cout << (p == x || x % 2 == 1 ? "Bob\n" : "Alice\n");
    }
    return 0;
}
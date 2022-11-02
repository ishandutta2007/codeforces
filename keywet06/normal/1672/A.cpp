#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        int s = 0, x;
        while (n--) std::cin >> x, s += x - 1;
        std::cout << (s & 1 ? "errorgorn" : "maomao90") << '\n';
    }
    return 0;
}
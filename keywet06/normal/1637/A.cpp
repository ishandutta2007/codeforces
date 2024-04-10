#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        int l = 0, x;
        bool Ans = true;
        while (n--) std::cin >> x, Ans &= x >= l, l = x;
        std::cout << (Ans ? "NO" : "YES") << '\n';
    }
    return 0;
}
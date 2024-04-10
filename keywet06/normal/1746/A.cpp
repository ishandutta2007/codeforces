#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n, k, a = 0, x;
        std::cin >> n >> k;
        while (n--) std::cin >> x, a |= x;
        std::cout << (a ? "YES" : "NO") << '\n';
    }
    return 0;
}
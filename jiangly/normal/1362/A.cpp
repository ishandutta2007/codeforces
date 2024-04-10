#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b;
        std::cin >> a >> b;
        if (a < b)
            std::swap(a, b);
        if (a % b) {
            std::cout << -1 << "\n";
        } else {
            a /= b;
            if (a & (a - 1)) {
                std::cout << -1 << "\n";
            } else {
                std::cout << (std::__lg(a) + 2) / 3 << "\n";
            }
        }
    }
    return 0;
}
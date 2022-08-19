#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int l, r;
        std::cin >> l >> r;
        if (r >= 2 * l) {
            std::cout << l << " " << 2 * l << "\n";
        } else {
            std::cout << -1 << " " << -1 << "\n";
        }
    }
    return 0;
}
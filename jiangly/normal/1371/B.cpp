#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, r;
        std::cin >> n >> r;
        if (r < n) {
            std::cout << 1ll * r * (r + 1) / 2 << "\n";
        } else {
            std::cout << 1ll * n * (n - 1) / 2 + 1 << "\n";
        }
    }
    return 0;
}
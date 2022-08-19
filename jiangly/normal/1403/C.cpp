#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, x, y, n;
        std::cin >> a >> b >> x >> y >> n;
        int m = std::min(std::max(a - n, x), std::max(b - n, y));
        std::cout << 1ll * m * (std::max(a + b - n, x + y) - m) << "\n";
    }
    return 0;
}
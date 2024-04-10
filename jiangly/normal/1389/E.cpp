#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int m, d, w;
        std::cin >> m >> d >> w;
        int g = std::gcd(d - 1, w);
        w /= g;
        int n = std::min(m, d);
        int x = n / w;
        std::cout << 1ll * x * (x - 1) / 2 * w + 1ll * (n % w) * x << "\n";
    }
    return 0;
}
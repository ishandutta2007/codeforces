#include <bits/stdc++.h>

int n, a, b, c, d, e, f, g, h;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a >> b >> c >> d;
        e = std::min(a, b);
        f = std::max(a, b);
        g = std::min(c, d);
        h = std::max(c, d);
        std::cout << (f > g && h > e ? "YES" : "NO") << std::endl;
    }
    return 0;
}
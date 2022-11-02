#include <bits/stdc++.h>

using int64 = long long;

int x, c, m, n, T, s;

int64 ans;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n, m = c = s = 0;
        while (n--) {
            std::cin >> x;
            while (!(x & 1)) x >>= 1, ++c;
            m = std::max(m, x), s += x;
        }
        ans = m;
        while (c--) ans <<= 1;
        ans += s - m;
        std::cout << ans << '\n';
    }
    return 0;
}
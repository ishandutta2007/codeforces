#include <bits/stdc++.h>

const int N = 200005;

int n, c, x, y, min, ca, cb, l, u, ans;
int a[N], f[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> x >> y;
        if (c = x > y) std::swap(x, y);
        if (x <= n && y <= n || x > n && y > n) return std::cout << "-1\n", 0;
        a[x] = y - n, f[x] = c;
    }
    min = ca = cb = n + 1, ++cb, c = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > ca && a[i] > cb) return std::cout << "-1\n", 0;
        c += (u = ca < cb && a[i] < ca) ^ f[i], (u ? ca : cb) = a[i], ++l;
        if (n - i + 1 != (min = std::min(min, a[i]))) continue;
        ans += std::min(c, l - c), l = c = 0;
    }
    std::cout << ans << std::endl;
    return 0;
}
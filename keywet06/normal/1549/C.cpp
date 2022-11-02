#include <bits/stdc++.h>

const int N = 200005;

int o, x, y, n, m, q, ans;

int a[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m, ans = n;
    for (int i = 1; i <= m; ++i) {
        std::cin >> x >> y;
        if (x > y) std::swap(x, y);
        if (!a[x]++) --ans;
    }
    std::cin >> q;
    while (q--) {
        std::cin >> o;
        if (o == 1) {
            std::cin >> x >> y;
            if (x > y) std::swap(x, y);
            if (!a[x]++) --ans;
        } else if (o == 2) {
            std::cin >> x >> y;
            if (x > y) std::swap(x, y);
            if (!--a[x]) ++ans;
        } else {
            std::cout << ans << '\n';
        }
    }
    return 0;
}
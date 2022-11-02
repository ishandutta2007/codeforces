#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n), b(n), c(n), d(n), e(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
        }
        int r = 0;
        auto Cmp = [&](int x, int y) {
            return (a[x] <= a[y]) + (b[x] <= b[y]) + (c[x] <= c[y]) +
                       (d[x] <= d[y]) + (e[x] <= e[y]) >
                   2;
        };
        for (int i = 1; i < n; ++i) r = Cmp(r, i) ? r : i;
        int Ans = 0;
        for (int i = 0; i < n; ++i) Ans += Cmp(r, i);
        std::cout << (Ans == n ? r + 1 : -1) << std::endl;
    }
    return 0;
}
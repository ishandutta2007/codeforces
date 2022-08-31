#include <bits/stdc++.h>
int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    auto query = [&](int l, int r) {
        if (r - l == 1 && a[l])
            return std::make_pair(a[l], 1);
        std::cout << "? " << l << " " << r - 1 << std::endl;
        int x, f;
        std::cin >> x >> f;
        if (r - l == 1)
            a[l] = x;
        return std::make_pair(x, f);
    };
    std::function<void(int, int)> work = [&](int l, int r) {
        if (l == r)
            return;
        auto [x, f] = query(l, r);
        int k = std::__lg(f);
        int p = -1, q = -1;
        for (int i = ((l - 1) >> k) + 1; (i << k) < r; ++i) {
            if (query(i << k, (i << k) + 1).first == x) {
                if (p == -1) {
                    p = i << k;
                } else {
                    q = i << k;
                }
            }
        }
        int u = -1, v = -1;
        if (q == -1) {
            auto [x1, f1] = query(p - (1 << k) + 1, p + 1);
            auto [x2, f2] = query(p, std::min(n + 1, p + (1 << k)));
            if (x == x1) {
                u = p + 1 - f1;
                v = u + f;
            } else if (x == x2) {
                v = p + f2;
                u = v - f;
            } else {
                assert(false);
            }
        } else {
            auto [x1, f1] = query(p - (1 << k) + 1, q + 1);
            u = q + 1 - f1;
            v = u + f;
        }
        for (int i = u; i < v; ++i)
            a[i] = x;
        work(l, u);
        work(v, r);
    };
    work(1, n + 1);
    std::cout << "!";
    for (int i = 1; i <= n; ++i)
        std::cout << " " << a[i];
    std::cout << std::endl;
    return 0;
}
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::string s, t;
    std::cin >> s >> t;
    std::vector<int> a(n + 1), b(n + 1);
    std::vector<int> u(n), v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> u[i] >> v[i];
        --u[i], --v[i];
    }
    auto work = [&](auto &a, auto s) {
        std::vector<int> p(k);
        std::iota(p.begin(), p.end(), 0);
        for (int i = n; i >= 0; --i) {
            if (i < n) std::swap(p[u[i]], p[v[i]]);
            for (int j = 0; j < k; ++j) a[i] |= (s[j] - '0') << p[j];
        }
    };
    work(a, s);
    work(b, t);
    std::vector<int> mn(1 << k, n + 1), mx(1 << k, -1);
    for (int i = n; i >= 0; --i) mn[a[i]] = i;
    for (int i = 0; i <= n; ++i) mx[b[i]] = i;
    for (int i = (1 << k) - 1; i; --i) {
        for (int j = 0; j < k; ++j) {
            if (i >> j & 1) {
                mn[i ^ 1 << j] = std::min(mn[i ^ 1 << j], mn[i]);
                mx[i ^ 1 << j] = std::max(mx[i ^ 1 << j], mx[i]);
            }
        }
    }
    int ans = -1, l = 0, r = 0;
    for (int i = 0; i < (1 << k); ++i) {
        if (__builtin_popcount(i) > ans && mx[i] - mn[i] >= m) {
            l = mn[i], r = mx[i], ans = __builtin_popcount(i);
        }
    }
    std::cout << 2 * ans - std::count(s.begin(), s.end(), '1') -
                     std::count(t.begin(), t.end(), '1') + k
              << "\n";
    std::cout << l + 1 << " " << r << "\n";
    return 0;
}
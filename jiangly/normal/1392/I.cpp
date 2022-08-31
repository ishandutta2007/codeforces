#include <bits/stdc++.h>
constexpr double PI = std::atan2(0, -1);
std::vector<int> rev;
std::vector<std::complex<double>> roots {0, 1};
void dft(std::vector<std::complex<double>> &a) {
    int n = a.size();
    if (int(rev.size()) != n) {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);
        for (int i = 0; i < n; ++i)
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
    }
    for (int i = 0; i < n; ++i)
        if (rev[i] < i)
            swap(a[i], a[rev[i]]);
    if (int(roots.size()) < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1 << k) < n) {
            std::complex<double> e = {cos(PI / (1 << k)), sin(PI / (1 << k))};
            for (int i = 1 << (k - 1); i < (1 << k); ++i) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = roots[i] * e;
            }
            ++k;
        }
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; ++j) {
                auto u = a[i + j], v = a[i + j + k] * roots[k + j];
                a[i + j] = u + v;
                a[i + j + k] = u - v;
            }
        }
    }
}
void idft(std::vector<std::complex<double>> &a) {
    int n = a.size();
    reverse(a.begin() + 1, a.end());
    dft(a);
    for (int i = 0; i < n; ++i)
        a[i] /= n;
}
std::vector<int64_t> operator*(std::vector<int64_t> a, std::vector<int64_t> b) {
    int sz = 1, tot = a.size() + b.size() - 1;
    while (sz < tot)
        sz *= 2;
    std::vector<std::complex<double>> ca(sz), cb(sz);
    copy(a.begin(), a.end(), ca.begin());
    copy(b.begin(), b.end(), cb.begin());
    dft(ca);
    dft(cb);
    for (int i = 0; i < sz; ++i)
        ca[i] *= cb[i];
    idft(ca);
    a.resize(tot);
    for (int i = 0; i < tot; ++i)
        a[i] = std::floor(ca[i].real() + 0.5);
    return a;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int i = 0; i < m; ++i)
        std::cin >> b[i];
    auto solve = [&]() {
        std::vector<int64_t> f(1e5 + 1), g(1e5 + 1);
        for (int i = 0; i < n; ++i)
            ++f[a[i]];
        for (int i = 0; i < n - 1; ++i)
            --f[std::max(a[i], a[i + 1])];
        for (int i = 0; i < m; ++i)
            ++g[b[i]];
        for (int i = 0; i < m - 1; ++i)
            --g[std::max(b[i], b[i + 1])];
        f = f * g;
        std::vector<int64_t> s(2e5 + 1);
        for (int i = 0; i < 2e5; ++i)
            s[i + 1] = s[i] + f[i];
        return s;
    };
    auto f = solve();
    for (int i = 0; i < n; ++i)
        a[i] = 1e5 - a[i];
    for (int i = 0; i < m; ++i)
        b[i] = 1e5 - b[i];
    auto g = solve();
    while (q--) {
        int x;
        std::cin >> x;
        std::cout << g[200000 - x + 1] - f[x] << "\n";
    }
    return 0;
}
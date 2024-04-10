#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> x(n), y(n), a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
        int g = std::abs(std::gcd(x[i], y[i]));
        if (g) {
            a[i] = x[i] / g;
            b[i] = y[i] / g;
        }
    }
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) {
        return a[i] < a[j] || (a[i] == a[j] && b[i] < b[j]);
    });
    std::vector<double> f, d(n);
    f.reserve(n);
    f.push_back(0);
    for (int i = 0; i < n;) {
        if (!a[p[i]] && !b[p[i]]) {
            ++i;
            continue;
        }
        int j = i;
        while (j < n && a[p[i]] == a[p[j]] && b[p[i]] == b[p[j]]) ++j;
        std::sort(p.begin() + i, p.begin() + j, [&](int i, int j) {
            return std::abs(x[i]) > std::abs(x[j]) ||
                   std::abs(y[i]) > std::abs(y[j]);
        });
        for (int v = 0; v < j - i; ++v) {
            double d = std::sqrt(1ll * x[p[i + v]] * x[p[i + v]] +
                                 1ll * y[p[i + v]] * y[p[i + v]]);
            f.push_back((k - 2 * v - 1) * d);
        }
        i = j;
    }
    std::cout << std::fixed << std::setprecision(10);
    double ans = 0;
    std::sort(f.begin(), f.end(), std::greater<>());
    for (int i = 0; i < k; ++i) ans += f[i];
    double f0 = 0, f1 = -1e30;
    for (int i = 0; i < n;) {
        if (!a[p[i]] && !b[p[i]]) {
            ++i;
            continue;
        }
        int j = i;
        while (j < n && a[p[i]] == a[p[j]] && b[p[i]] == b[p[j]]) ++j;
        double g0 = 0, g1 = 0;
        for (int v = 0; v < j - i; ++v) {
            double d = std::sqrt(1ll * x[p[i + v]] * x[p[i + v]] +
                                 1ll * y[p[i + v]] * y[p[i + v]]);
            g0 += d * (k - 2 * v - 1);
            if (v < k / 2) g1 += d * (k - 2 * v - 1);
            if (v >= k / 2 + n - k) g1 += d * (2 * (n - v) - k - 1);
        }
        if (n - k + k / 2 > j - i) {
            f1 += g0;
            f0 += g0;
        } else {
            f1 = std::max(f1 + g0, f0 + g1);
            f0 += g0;
        }
        i = j;
    }
    ans = std::max(ans, f1);
    std::cout << ans << "\n";
    return 0;
}
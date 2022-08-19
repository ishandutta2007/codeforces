#include <iostream>
#include <vector>
#include <complex>
#include <deque>
#include <algorithm>
using Point = std::complex<long long>;
auto dot(const Point &lhs, const Point &rhs) {
    return (std::conj(lhs) * rhs).real();
}
auto cross(const Point &lhs, const Point &rhs) {
    return (std::conj(lhs) * rhs).imag();
}
int n, m, p;
std::vector<int> d, a;
std::vector<long long> dp, sum;
std::deque<Point> q;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> p;
    d.resize(n);
    for (int i = 1; i < n; ++i)
        std::cin >> d[i];
    for (int i = 1; i < n; ++i)
        d[i] += d[i - 1];
    a.resize(m);
    for (int i = 0; i < m; ++i) {
        int h, t;
        std::cin >> h >> t;
        --h;
        a[i] = t - d[h];
    }
    std::sort(a.begin(), a.end());
    sum.resize(m + 1);
    for (int i = 0; i < m; ++i)
        sum[i + 1] = sum[i] + a[i];
    dp.resize(m + 1);
    for (int i = 1; i <= m; ++i)
        dp[i] = 1ll * a[i - 1] * i - sum[i];
    for (int t = 1; t < p; ++t) {
        q.clear();
        for (int i = 0; i <= m; ++i) {
            Point p(i, dp[i] + sum[i]);
            while (int(q.size()) >= 2 && cross(q.back() - q[q.size() - 2], p - q.back()) <= 0)
                q.pop_back();
            q.push_back(p);
            if (i == 0)
                continue;
            p = Point(-a[i - 1], 1);
            while (int(q.size()) >= 2 && dot(p, q[0]) >= dot(p, q[1]))
                q.pop_front();
            dp[i] = dot(p, q[0]) + 1ll * a[i - 1] * i - sum[i];
        }
    }
    std::cout << dp[m] << "\n";
    return 0;
}
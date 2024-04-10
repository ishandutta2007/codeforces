#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <chrono>
#include <queue>
#include <set>
#include <cassert>
#include <random>
#include <chrono>
#include <complex>
#include <cstring>
#include <map>
#include <iomanip>
using Point  = std::complex<long double>;
#define x real
#define y imag
const Point rot(std::cos(1), std::sin(1));
constexpr long double EPS = 1e-8;
long double cross(const Point &a, const Point &b) {
    return (std::conj(a) * b).y();
}
int sgn(long double x) {
    if (std::abs(x) < EPS)
        return 0;
    return x > 0 ? 1 : -1;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<Point> s(n), v(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        s[i] = rot * Point(x, y);
        int dx, dy, s;
        std::cin >> dx >> dy >> s;
        long double t = s / std::sqrt(dx * dx + dy * dy);
        v[i] = rot * Point(dx * t, dy * t);
    }
    auto check = [&](long double l) {
        std::vector<Point> a(n), b(n);
        std::vector<std::pair<long double, int>> q;
        q.reserve(2 * n);
        for (int i = 0; i < n; ++i) {
            a[i] = s[i];
            b[i] = s[i] + l * v[i];
            if (a[i].x() > b[i].x())
                std::swap(a[i], b[i]);
            q.emplace_back(a[i].x(), i);
            q.emplace_back(b[i].x(), i);
        }
        const long double eps = l * EPS;
        auto sgn = [&](long double x) {
            if (std::abs(x) < eps)
                return 0;
            return x > 0 ? 1 : -1;
        };
        auto intersect = [&](int i, int j) {
            if (a[i].x() > b[j].x() + eps || a[j].x() > b[i].x() + eps)
                return false;
            if (std::max(a[i].y(), b[i].y()) + l * eps < std::min(a[j].y(), b[j].y()))
                return false;
            if (std::max(a[j].y(), b[j].y()) + eps < std::min(a[i].y(), b[i].y()))
                return false;
            if (sgn(cross(a[j] - a[i], b[i] - a[i])) * sgn(cross(b[i] - a[i], b[j] - a[i])) == -1)
                return false;
            if (sgn(cross(a[i] - a[j], b[j] - a[j])) * sgn(cross(b[j] - a[j], b[i] - a[j])) == -1)
                return false;
            return true;
        };
        std::sort(q.begin(), q.end());
        std::set<int, std::function<bool(int, int)>> s([&](int i, int j) {
            long double x = std::max(a[i].x(), a[j].x());
            long double yi = a[i].y() + (x - a[i].x()) * (b[i].y() - a[i].y()) / (b[i].x() - a[i].x());
            long double yj = a[j].y() + (x - a[j].x()) * (b[j].y() - a[j].y()) / (b[j].x() - a[j].x());
            return yi < yj;
        });
        for (auto [x, i] : q) {
            if (x == a[i].x()) {
                auto g = s.insert(i);
                if (!g.second)
                    return true;
                auto it = g.first;
                if (it != s.begin() && intersect(*it, *std::prev(it)))
                    return true;
                if (std::next(it) != s.end() && intersect(*it, *std::next(it)))
                    return true;
            } else {
                auto it = s.erase(s.find(i));
                if (it != s.end() && it != s.begin() && intersect(*it, *std::prev(it)))
                    return true;
            }
        }
        return false;
    };
    if (!check(1e10)) {
        std::cout << "No show :(" << std::endl;
        return 0;
    }
    long double l = 0, r = 1e10;
    for (int i = 0; i < 100; ++i) {
        long double m = (l + r) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    std::cout << std::fixed << std::setprecision(10) << double(l) << std::endl;
    return 0;
}
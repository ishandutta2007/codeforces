#include <bits/stdc++.h>

struct Frac {
    int64_t x, y;
    Frac(int64_t x = 0, int64_t y = 1) : x(x), y(y) {norm();}
    void norm() {
        if (y < 0) {
            y = -y;
            x = -x;
        }
    }
};

bool operator<(const Frac &lhs, const Frac &rhs) {
    return 1ll * lhs.x * rhs.y < 1ll * rhs.x * lhs.y;
}

std::ostream &operator<<(std::ostream &lhs, const Frac &rhs) {
    int g = std::gcd(rhs.x, rhs.y);
    return lhs << rhs.x / g << "/" << rhs.y / g;
}

using Point = std::complex<int64_t>;

int64_t dot(const Point &lhs, const Point &rhs) {
    return (std::conj(lhs) * rhs).real();
}

int64_t cross(const Point &lhs, const Point &rhs) {
    return (std::conj(lhs) * rhs).imag();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> xl(n), xr(n), y(n);
    for (int i = 0; i < n; ++i)
        std::cin >> xl[i] >> xr[i] >> y[i];
    std::vector<std::pair<Frac, Frac>> intervals;
    intervals.reserve(n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (y[i] == y[j])
                continue;
            Frac l(xl[i] - xr[j], y[j] - y[i]), r(xr[i] - xl[j], y[j] - y[i]);
            if (r < l)
                std::swap(l, r);
            intervals.emplace_back(l, r);
        }
    }
    
    std::vector<Point> upp, low;
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) {
        return y[i] < y[j] || (y[i] == y[j] && xl[i] < xl[j]);
    });
    for (auto i : p) {
        Point pt(y[i], xr[i]);
        while (upp.size() >= 2 && cross(pt - upp.back(), pt - upp[upp.size() - 2]) <= 0)
            upp.pop_back();
        if (!upp.empty() && upp.back().real() == pt.real()) {
            upp.back() = pt;
        } else {
            upp.push_back(pt);
        }
    }
    for (auto i : p) {
        Point pt(y[i], xl[i]);
        if (!low.empty() && low.back().real() == pt.real())
            continue;
        while (low.size() >= 2 && cross(pt - low.back(), pt - low[low.size() - 2]) >= 0)
            low.pop_back();
        low.push_back(pt);
    }
    for (int i = 0; i + 1 < int(upp.size()); ++i) {
        auto pt = upp[i + 1] - upp[i];
        Frac x(-pt.imag(), pt.real());
        intervals.emplace_back(x, x);
    }
    for (int i = 0; i + 1 < int(low.size()); ++i) {
        auto pt = low[i + 1] - low[i];
        Frac x(-pt.imag(), pt.real());
        intervals.emplace_back(x, x);
    }
    
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::pair<Frac, Frac>> good;
    good.reserve(intervals.size() + 1);
    Frac curl(-2e6), curr(-2e6);
    for (auto [l, r] : intervals) {
        if (l < curr) {
            if (curr < r)
                curr = r;
        } else {
            good.emplace_back(curr, l);
            curl = l;
            curr = r;
        }
    }
    good.emplace_back(curr, 2e6);
    Frac ans(9e12);
    int i = 0, j = low.size() - 1;
    for (auto [l, r] : good) {
        Point pt(l.x, l.y);
        while (i + 1 < int(upp.size()) && dot(upp[i], pt) <= dot(upp[i + 1], pt))
            ++i;
        while (j > 0 && dot(low[j], pt) >= dot(low[j - 1], pt))
            --j;
        Point g = upp[i] - low[j];
        Frac res;
        if (g.real() < 0) {
            pt = Point(r.x, r.y);
            res = Frac(dot(pt, g), r.y);
        } else {
            res = Frac(dot(pt, g), l.y);
        }
        if (res < ans)
            ans = res;
    }
    std::cerr << ans << std::endl;
    std::cout << std::fixed << std::setprecision(10) << 1.0 * ans.x / ans.y << std::endl;
    return 0;
}
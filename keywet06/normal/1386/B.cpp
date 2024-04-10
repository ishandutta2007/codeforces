#include <bits/stdc++.h>

using Point = std::complex<__int128>;

__int128 cross(const Point &lhs, const Point &rhs) {
    return (std::conj(lhs) * rhs).imag();
}

int sgn(Point p) {
    if (p.imag() > 0 || (p.imag() == 0 && p.real() > 0)) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int need[3];
    for (int i = 0; i < 3; ++i) std::cin >> need[i];
    int p[3] = {0, 1, 2};
    std::sort(p, p + 3, [&](int i, int j) { return need[i] < need[j]; });
    int n;
    std::cin >> n;
    std::vector<Point> vec;
    int cnt0 = 0, cntneg = 0, cntopp = 0;
    std::map<Point, int, std::function<bool(Point, Point)>> cnt(
        [&](Point lhs, Point rhs) {
            if (sgn(lhs) != sgn(rhs)) return sgn(lhs) == 0;
            return cross(lhs, rhs) > 0;
        });
    auto add = [&](Point v) {
        if (v.real() == 0 && v.imag() == 0) {
            ++cnt0;
            return;
        }
        if (cnt[v]++ == 0) {
            auto it = cnt.find(v);
            if (cnt.count(-v)) ++cntopp;
            if (cnt.size() == 1) {
                ++cntneg;
            } else {
                auto l = std::prev((it == cnt.begin()) ? cnt.end() : it);
                auto r = std::next(it);
                if (r == cnt.end()) r = cnt.begin();
                cntneg -= cross(l->first, r->first) <= 0;
                cntneg += cross(l->first, v) <= 0;
                cntneg += cross(v, r->first) <= 0;
            }
        }
    };
    auto del = [&](Point v) {
        if (v.real() == 0 && v.imag() == 0) {
            --cnt0;
            return;
        }
        if (--cnt[v] == 0) {
            auto it = cnt.find(v);
            if (cnt.count(-v)) --cntopp;
            if (cnt.size() == 1) {
                --cntneg;
            } else {
                auto l = std::prev((it == cnt.begin()) ? cnt.end() : it);
                auto r = std::next(it);
                if (r == cnt.end()) r = cnt.begin();
                cntneg += cross(l->first, r->first) <= 0;
                cntneg -= cross(l->first, v) <= 0;
                cntneg -= cross(v, r->first) <= 0;
            }
            cnt.erase(v);
        }
    };
    for (int i = 0; i < n; ++i) {
        char op;
        std::cin >> op;
        if (op == 'A') {
            int g[3];
            for (int j = 0; j < 3; ++j) std::cin >> g[j];
            int64_t x, y;
            if (need[p[0]] > 0) {
                x = 1ll * g[p[0]] * need[p[1]] * need[p[2]] -
                    1ll * g[p[2]] * need[p[0]] * need[p[1]];
                y = 1ll * g[p[1]] * need[p[0]] * need[p[2]] -
                    1ll * g[p[2]] * need[p[0]] * need[p[1]];
            } else if (need[p[1]] > 0) {
                x = g[p[0]];
                y = 1ll * need[p[2]] * g[p[1]] - 1ll * need[p[1]] * g[p[2]];
            } else {
                x = g[p[0]];
                y = g[p[1]];
            }
            int64_t d = std::gcd(x, y);
            if (d > 0) {
                x /= d;
                y /= d;
            }
            vec.emplace_back(x, y);
            add(vec.back());
        } else {
            int x;
            std::cin >> x;
            --x;
            del(vec[x]);
        }
        if (cnt0 > 0) {
            std::cout << 1 << "\n";
        } else if (cntopp > 0) {
            std::cout << 2 << "\n";
        } else if (!cnt.empty() && cntneg == 0) {
            std::cout << 3 << "\n";
        } else {
            std::cout << 0 << "\n";
        }
    }
    return 0;
}
// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class P, class T = ll>
T det(const P& a, const P& b, const P& c) {
    return (a-b).template vp<T>(a-c);
}

template<class T>
T sgn(T x) {
    return x < 0 ? -1 : !!x;
}

template<class T>
struct point {
    T x, y;
    point operator- (const point& b) const { return {x-b.x, y-b.y}; }
    point& operator-= (const point& b) { x -= b.x; y -= b.y; return *this; }
    strong_ordering operator<=> (const point& b) const = default;
    bool operator== (const point& b) const = default;
    template<class R = ll> R sp(const point& b) const { return (R)x*b.x + (R)y*b.y; }
    template<class R = ll> R vp(const point& b) const { return (R)x*b.y - (R)y*b.x; }
};

using pti = point<int>;
using ptll = point<ll>;

template<class T>
struct segment {
    point<T> a, b;

    segment(const point<T>& u, const point<T>& v) : a(u), b(v) {
        if (b < a) swap(a, b);
    }

    template<class R = ll> R len2() { auto x = a-b; return x.template sp<R>(x); }

    template<class R = ll>
    bool contains(const point<T>& c) const {
        return !det(a, b, c) && a <= c && c <= b;
    }

    // Whether insides intersect at a nonzero angle
    template<class R = ll>
    bool intersect_strict(const segment& o) const {
        R p = sgn(det(a, b, o.a)), q = sgn(det(a, b, o.b));
        R r = sgn(det(o.a, o.b, a)), s = sgn(det(o.a, o.b, b));
        return p && q && r && s && p != q && r != s;
    }

    // Whether insides intersect in any way
    template<class R = ll>
    bool intersect(const segment& o) const {
        return intersect_strict(o) || contains(o.a) || contains(o.b)
            || o.contains(a) || o.contains(b);
    }
};

istream& operator>> (istream& in, ptll& a) {
    return in >> a.x >> a.y;
}

struct triangle {
    ptll a, b, c;
};

int n;
triangle a[105];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i : ra(0, n)) {
        cin >> a[i].a >> a[i].b >> a[i].c;

        if (det(a[i].a, a[i].b, a[i].c) < 0) {
            swap(a[i].b, a[i].c);
        }
    }

    double sol = 0.0;

    auto sec = [&](ptll a, ptll b, ptll c, ptll d) -> pair<int, double> {
        if (sgn(det(a, b, c)) * sgn(det(a, b, d)) != -1) {
            return {0, 0.0};
        }

        double p = -c.y*d.x + a.y*(d.x-c.x) + a.x*(c.y-d.y) + c.x*d.y;
        double q = -(a.y-b.y) * (c.x - d.x) + (a.x - b.x) * (c.y - d.y);

        return {sgn(det(a, b, c)), p / q};
    };

    auto solve = [&](ptll a, ptll b, int skip_i) {
        vector<pair<double, double>> blocked;
        for (int j : ra(0, n)) {
            if (j == skip_i) continue;

            auto [e, d, c] = ::a[j];

            double r[3] = {1, 0, 0};

            auto put = [&](ptll c, ptll d) {
                auto [s, z] = sec(a, b, c, d);
                r[s+1] = z;
            };

            put(c, d);
            put(d, e);
            put(e, c);

            if (a == c || a == d || a == e) r[0] = 0;
            if (b == c || b == d || b == e) r[2] = 1;

            r[0] = max(r[0], 0.0);
            r[2] = min(r[2], 1.0);
            if (r[0] <= r[2]) {
                blocked.emplace_back(r[0], r[2]);
            }
        }
        R::sort(blocked);
        double fre = 0.0, upto = 0.0;
        for (auto [l, r] : blocked) {
            if (upto < l) {
                fre += l - upto;
            }
            upto = max(upto, r);
        }
        fre += 1 - upto;

        sol += fre * sqrt(segment(a, b).len2());
    };

    for (int i : ra(0, n)) {
        solve(a[i].a, a[i].b, i);
        solve(a[i].b, a[i].c, i);
        solve(a[i].c, a[i].a, i);
    }

    cout << setprecision(14) << fixed << sol << '\n';
}
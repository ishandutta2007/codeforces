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

struct point {
    int x, y;
    ld factor;

    point(int x, int y, ld factor = 1.0) : x(x), y(y), factor(factor) {}

    point operator- (const point& b) const { return {x-b.x, y-b.y}; }
    point operator+ (const point& b) const { return {x+b.x, y+b.y}; }
    point& operator-= (const point& b) { x -= b.x; y -= b.y; return *this; }
    point& operator+= (const point& b) { x += b.x; y += b.y; return *this; }

    bool operator< (const point& b) const {
        return ll(x) * b.y < ll(y) * b.x;
    }
};

struct ptd {
    ld x, y;

    ptd& operator+= (const point& b) { x += b.x * b.factor; y += b.y * b.factor; return *this; }
    ptd& operator-= (const point& b) { x -= b.x * b.factor; y -= b.y * b.factor; return *this; }

    ptd operator- (const point& b) const { return {x - b.x * b.factor, y - b.y * b.factor}; }
    ptd operator+ (const point& b) const { return {x + b.x * b.factor, y + b.y * b.factor}; }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cout << setprecision(14) << fixed;

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        ptd first = {ld(a), ld(b)};
        ptd last = first;

        multiset<point> s;

        auto insert_pt = [&](point p) {
            if (p.factor < 1e-12) {
                return;
            }
            s.insert(p);
        };

        vector<int> p(n), q(n);
        for (int& x : p) cin >> x;
        for (int& x : q) cin >> x;

        for (int i : ra(0, n)) {
            point d(p[i], -q[i], 1.0);

            // extend
            {
                auto d2 = d;
                d2.factor = 2.0;
                insert_pt(d2);
            }

            first -= d;
            last += d;

            // crop
            while (last.y < 0) {
                if ((last - *prev(s.end())).y <= 0) {
                    // freely remove entire thing
                    last -= *prev(s.end());
                    s.erase(prev(s.end()));
                } else {
                    auto pe = *prev(s.end());
                    s.erase(prev(s.end()));

                    ptd last_without = last - pe;
                    ld new_factor = -last_without.y / pe.y;

                    pe.factor = new_factor;
                    insert_pt(pe);

                    last = last_without + pe;
                    break;
                }
            }

            while (first.x < 0) {
                if ((first + *s.begin()).x <= 0) {
                    // freely remove entire thing
                    first += *s.begin(); 
                    s.erase(s.begin());
                } else {
                    auto pe = *s.begin();
                    s.erase(s.begin());

                    ptd first_without = first + pe;
                    ld new_factor = first_without.x / pe.x;

                    pe.factor = new_factor;
                    insert_pt(pe);

                    first = first_without - pe;
                    break;
                }
            }

            cout << last.x << '\n';
        }
    }
}
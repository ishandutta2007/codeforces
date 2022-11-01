#ifndef LOCAL
#pragma GCC optimize("O3")
#endif

#include <bits/stdc++.h>

using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim>typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim>
struct rge {
    c b, e;
};

sim> rge<c> range(c i, c j) { return rge<c>{i, j}; }

sim> auto dud(c *r) -> decltype(cerr << *r);

sim> char dud(...);

struct muu {
#ifdef LOCAL
    stringstream a;

    ~muu() { cerr << a.str() << endl; }

    R22(<) a << boolalpha << g;
        ris; }

    R22(==) ris << range(begin(g), end(g)); }

    sim mor rge<c> u) {
        a << "[";
        for (c i = u.b; i != u.e; ++i)
            *this << ", " + 2 * (i == u.b) << *i;
        ris << "]";
    }

    sim, class m mor pair<m, c> r) { ris << "(" << r.first << ", " << r.second << ")"; }

#else
    sim mor const c&){ris;}
#endif
};

#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r...) "[" #r ": " << (r) << "] "
#define range(a, b) "[[" #a ", " #b "): " << range(a, b) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
using pii = pair<int, int>;
using ld = long double;
using ll = long long;

bool zajete[3][100007];

int main() {
    ll x0, y0, ax, ay, bx, by;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    ll xs, ys, t;
    cin >> xs >> ys >> t;
    vector<pair<ll, ll>> points;
    for (int i = 0; i < 100; i++) {
        debug << imie(x0) imie(y0);
        if (abs(xs - x0) + abs(ys - y0) <= t)
            points.push_back({x0, y0});
        x0 = x0 * ax + bx;
        y0 = y0 * ay + by;
        if (x0 > xs + t || y0 > ys + t)
            break;
    }
    int maxi = 0;
    for (int i = 0; i < points.size(); i++) {
        ll odl = abs(xs - points[i].first) + abs(ys - points[i].second);
        for (int w = 0; w < points.size(); w++) {
            ll odl2 = abs(points[w].first - points[i].first) + abs(points[w].second - points[i].second);
            if (odl + odl2 <= t)
                maxi = max(maxi, abs(w - i) + 1);
        }
    }
    printf("%d", maxi);
    return 0;
}
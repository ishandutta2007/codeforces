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

struct Vec {
    long double x, y;

    bool up() const {
        return y > 0 or (y == 0 and x >= 0);
    }

    bool operator<(Vec const &rhs) const {
        return !(up() == rhs.up() ? x * rhs.y > y * rhs.x : up() < rhs.up());
    }
};

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

    sim, class m mor pair<m, c> r) {
        ris << "(" << r.first << ", " << r.second << ")";
    }

    muu& operator<<(Vec x) {
        ris << "(" << x.x << ", " << x.y << ")";
    }

#else

    sim mor const c &) { ris; }

#endif
};

#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r) "[" #r ": " << (r) << "] "
#define range(a, b) "[[" #a ", " #b "): " << range(a, b) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
using pii = pair<int, int>;
using ld = long double;
using ll = long long;

std::multiset<Vec> vecs;

void check_ok(ld sx, ld sy) {
#ifdef LOCAL
    ld real_sx = 0, real_sy = 0;
    for (auto it: vecs) {
        real_sx += it.x, real_sy += it.y;
    }
    assert(abs(real_sx - sx) < 0.0001);
    assert(abs(real_sy - sy) < 0.0001);
#endif
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, aa, bb;
        scanf("%d%d%d", &n, &aa, &bb);
        ld a = aa, b = bb;
        ld y0 = b, x0 = 0;
        ld sx = a, sy = -b;
        vecs.insert({a, 0.});
        vecs.insert({0., -b});
        vector<int> xx, yy;
        for (int i = 1; i <= n; i++) {
            int a;
            scanf("%d", &a);
            xx.push_back(a);
        }
        for (int i = 1; i <= n; i++) {
            int a;
            scanf("%d", &a);
            yy.push_back(a);
        }
        for (int i = 0; i < n; i++) {
            ld x = xx[i], y = yy[i];
            vecs.insert({2 * x, 2 * -y});
            sx += 2 * x, sy += 2 * -y;
            x0 -= x, y0 += y;
            debug << imie(vecs);
            while (x0 < 0) {
                Vec f = *vecs.begin();
                vecs.erase(vecs.begin());
                sx -= f.x, sy -= f.y;
                debug << "Usuwam " imie(f);
                if (f.x + x0 <= 0) {
                    x0 += f.x, y0 += f.y;
                    check_ok(sx, sy);
                    continue;
                } else {
                    ld yf = y0 - (x0 * f.y) / f.x;
                    ld kx = x0 + f.x, ky = y0 + f.y;
                    x0 = 0, y0 = yf;
                    Vec nowy = {kx - x0, ky - y0};
                    debug << "Naprawiam przez " imie(nowy);
                    sx += nowy.x, sy += nowy.y;
                    vecs.insert(nowy);
                    check_ok(sx, sy);
                }
            }
            while (y0 + sy < 0) {
                Vec f = *(--vecs.end());
                vecs.erase(--vecs.end());
                debug << "Usuwam y " imie(f);
                if (y0 + sy - f.y <= 0) {
                    sx -= f.x, sy -= f.y;
                    check_ok(sx, sy);
                    continue;
                } else {
                    ld xf = (x0 + sx) - (y0 + sy) * f.x / f.y;
                    ld kx = x0 + sx - f.x, ky = y0 + sy - f.y;
                    sx = xf - x0, sy = 0 - y0;
                    Vec nowy = {x0 + sx - kx, y0 + sy - ky};
                    debug << "Naprawiam przez " imie(nowy);
                    vecs.insert(nowy);
                    check_ok(sx, sy);
                }
            }
            check_ok(sx, sy);
            debug << "Po zmianach" imie(x0) imie(y0) imie(vecs);
            printf("%Lf\n", x0 + sx);
        }
        vecs.clear();
    }
    return 0;
}
// Retired?
#include <bits/stdc++.h>
using namespace std;

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
    bool operator< (const point& b) const { return tie(x, y) < tie(b.x, b.y); }
    bool operator== (const point& b) const { return tie(x, y) == tie(b.x, b.y); }
    bool operator<= (const point& b) const { return tie(x, y) <= tie(b.x, b.y); }
    template<class R = ll> R sp(const point& b) const { return (R)x*b.x + (R)y*b.y; }
    template<class R = ll> R vp(const point& b) const { return (R)x*b.y - (R)y*b.x; }
};

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

using pti = point<int>;
using ptll = point<ll>;

int n, start, off;
ptll a[200005];

double len(ptll x, ptll y) {
    return sqrt(segment(x, y).len2());
}

double len(int i, int j) {
    return len(a[i], a[j]);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));
    cout << setprecision(20) << fixed;

    cin >> n >> start;
    start--;
    for (int i=0; i<n; i++) {
        cin >> a[i].x >> a[i].y;
    }

    auto ps = a[start];

    for (int i=0; i<3; i++) {
        for (int j=i+1; j<3; j++) {
            int l = 0, f = -1;
            for (int k=0; k<n; k++) {
                if (det(a[i], a[j], a[k]) == 0) {
                    l++;
                } else {
                    f = k;
                }
            }

            if (l == n-1) {
                off = f;
            }
        }
    }

    swap(a[off], a[0]);
    sort(a+1, a+n);
    start = find(a+1, a+n, ps) - a;

    if (start == 0) {
        cout << min(len(0, 1), len(0, n-1)) + len(1, n-1) << '\n';
        return 0;
    }

    double sol = 1e27;

    auto go = [&]() {
        // idemo direktno gore
        {
            double l = 0;
            // setnja
            l += len(start, 0);
            // range ostatak
            int rx = start == 1 ? 2 : 1;
            int ry = start == n-1 ? n-2 : n-1;
            l += len(rx, ry);
            // trougao
            l += min(len(0, rx), len(0, ry));
            sol = min(sol, l);
        }

        // idemo do levog kraja
        {
            double l = 0;
            // setnja
            l += len(start, 1);
            l += len(1, 0);
            // range ostatak
            if (start != n-1) {
                int rx = start + 1, ry = n-1;
                l += len(rx, ry);
                // trougao
                l += min(len(0, rx), len(0, ry));
            }
            sol = min(sol, l);
        }

        // idemo do levog kraja pa se vracamo do i, pre desnog kraja
        for (int i=start+1; i<n-1; i++) {
            double l = 0;
            // setnja
            l += len(start, 1);
            l += len(1, i);
            l += len(i, 0);
            // range ostatak
            int rx = i+1, ry = n-1;
            l += len(rx, ry);
            // trougao
            l += min(len(0, rx), len(0, ry));
            sol = min(sol, l);
        }

        // idemo do levog pa do desnog kraja, zavrsavamo u desnom kraju
        {
            double l = 0;
            // setnja
            l += len(start, 1);
            l += len(1, n-1);
            l += len(n-1, 0);
            sol = min(sol, l);
        }
    };
    
    go();
    reverse(a+1, a+n);
    start = n - start;
    go();

    cout << sol << '\n';
}
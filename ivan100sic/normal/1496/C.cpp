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

bool origindist(ptll a, ptll b) {
    return abs(a.x) + abs(a.y) < abs(b.x) + abs(b.y);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));
    cout << setprecision(14) << fixed;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ptll> a(n), b(n);
        for (int i=0, j=0, k=0; i<2*n; i++) {
            ll x, y;
            cin >> x >> y;
            if (x == 0) a[j++] = {x, y};
            else b[k++] = {x, y};
        }

        sort(begin(a), end(a), origindist);
        sort(begin(b), end(b), origindist);

        double z1 = 0, z2 = 0;

        for (int i=0; i<n; i++) {
            z1 += sqrt(segment(a[i], b[i]).len2());
            z2 += sqrt(segment(a[i], b[n-1-i]).len2());
        }
        

        cout << min(z1, z2) << '\n';

    }
}
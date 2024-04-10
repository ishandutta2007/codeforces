// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<int m>
struct modint {
    unsigned x;

    modint() : x(0) {}
    modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

    modint operator+ (const modint& b) const {
        auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
    }

    modint operator- (const modint& b) const {
        auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
    }

    modint operator* (const modint& b) const {
        auto t = *this; t.x = ll(t.x) * b.x % m; return t;
    }

    modint operator/ (const modint& b) const {
        return *this * b.inv();
    }

    template<class T> modint operator^ (T n) const {
        modint t;
        if (n == 0) return t.x = 1, t;
        if (n == 1) return t.x = x, t;
        t = *this ^ (n >> 1); t *= t;
        return n & 1 ? *this * t : t;
    }

    modint& operator+= (const modint& b) { return *this = *this + b; }
    modint& operator-= (const modint& b) { return *this = *this - b; }
    modint& operator*= (const modint& b) { return *this = *this * b; }
    modint& operator/= (const modint& b) { return *this = *this / b; }
    modint& operator++ () { if (++x == m) x = 0; return *this; }
    modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
    modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
    modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
    bool operator== (const modint& other) const { return x == other.x; }
    bool operator!= (const modint& other) const {	return x != other.x; }
    int operator() () const { return x; }
    template<class T> modint operator^= (T n) { return *this = *this ^ n; }
    modint inv() const { return *this ^ (m-2); }
};

const int mod = 1'000'000'007;
typedef modint<mod> mint;

template<class R>
struct matrix {
    inline static constexpr int n = 2;
    inline static constexpr int m = 2;
    array<R, 4> a;

    static matrix eye() {
        matrix t;
        for (int i=0; i<n; i++)
            t[i][i] = 1;
        return t;
    }

    matrix operator* (const matrix& b) const {
        matrix c;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                for (int k=0; k<b.m; k++)
                    c[i][k] += a[m*i+j] * b[j][k];
        return c;
    }

    matrix& operator+= (const matrix& b) {
        for (int i=0; i<n*m; i++)
            a[i] += b.a[i];
        return *this;
    }

    matrix& operator-= (const matrix& b) {
        for (int i=0; i<n*m; i++)
            a[i] += b.a[i];
        return *this;
    }

    R* operator[] (int x) { return a.data() + m*x; }
    const R* operator[] (int x) const { return a.data() + m*x; }
    matrix operator+ (const matrix& b) const { auto t = *this; t += b; return t; }
    matrix operator- (const matrix& b) const { auto t = *this; t -= b; return t; }
    matrix& operator*= (const matrix& b) { return *this = *this * b; }
    template<class U> matrix operator^= (U arg) { return *this = *this ^ arg; }

    template<class U>
    matrix operator^ (U arg) const {
        if (arg == 0)
            return matrix::eye();
        if (arg == 1)
            return *this;
        auto t = *this ^ (arg >> 1);
        t *= t;
        if (arg & 1)
            t *= *this;
        return t;
    }

    matrix T() const {
        matrix b(m, n);
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                b[j][i] = a[i][j];
        return b;
    }
};

using minimat = matrix<mint>;
const minimat fib = []() {
    minimat a;
    a[0][1] = a[1][0] = a[1][1] = 1;
    return a;
}();

const minimat fib_inv = []() {
    minimat a;
    a[0][0] = -1;
    a[0][1] = a[1][0] = 1;
    return a;
}();

template<class T, class U, class F, class G, class H>
struct segtreelazy {
    struct node { T v; U u; };
    int maxn;
    vector<node> a;
    T e; U eu;
    F f; G g; H h;
    // Add two elements
    // Add two updaters
    // Add an element and an update
    // Neutral element
    // Neutral update
    // Bottom level element
    segtreelazy(int n, F f, G g, H h, T e = T(), U eu = U(), T v = T()) :
        e(e), eu(eu), f(f), g(g), h(h)
    {
        maxn = 1;
        while (maxn < n)
            maxn <<= 1;
        a.assign(2*maxn, node{v, eu});
        for (int i=maxn-1; i; i--)
            a[i].v = f(a[2*i].v, a[2*i+1].v);
    }

    void push(int x) {
        a[x].v = h(a[x].v, a[x].u);
        if (x < maxn) {
            a[2*x  ].u = g(a[2*x  ].u, a[x].u);
            a[2*x+1].u = g(a[2*x+1].u, a[x].u);
        }
        a[x].u = eu;
    }

    void set(int p, const T& v) {
        int x = 1, xl = 0, xr = maxn;
        while (xr-xl > 1) {
            push(x);
            int xm = (xl+xr) >> 1;
            (p < xm ? xr : xl) = xm;
            x = 2*x + (p >= xm);
        }
        a[x] = {v, eu};
        do {
            push(x^1);
            x >>= 1;
            a[x].v = f(a[2*x].v, a[2*x+1].v);
        } while (x > 1);
    }

    void update(int l, int r, const U& u, int x, int xl, int xr) {
        if (r <= xl || xr <= l)
            return push(x);
        if (l <= xl && xr <= r)
            return a[x].u = g(a[x].u, u), push(x);
        push(x);
        int xm = (xl+xr) >> 1;
        update(l, r, u, 2*x  , xl, xm);
        update(l, r, u, 2*x+1, xm, xr);
        a[x].v = f(a[2*x].v, a[2*x+1].v);
    }

    T get(int l, int r, int x, int xl, int xr) {
        push(x);
        if (r <= xl || xr <= l)
            return e;
        if (l <= xl && xr <= r)
            return a[x].v;
        int xm = (xl+xr) >> 1;
        return f(get(l, r, 2*x, xl, xm), get(l, r, 2*x+1, xm, xr));
    }

    void update(int l, int r, const U& u) { update(l, r, u, 1, 0, maxn); }
    T operator() (int l, int r) { return get(l, r, 1, 0, maxn); }
};

segtreelazy stlz(
    50005,
    plus<minimat>(),
    plus<ll>(),
    [](minimat a, ll b) {
        if (b == 0) return a;
        if (b > 0) return a * (fib ^ b);
        return a * (fib_inv ^ (-b));
    },
    minimat{},
    0ll,
    minimat::eye()
);

template<class CB>
struct segtreebeats {
    struct node {ll lo, hi, lz; };
    int maxn;
    vector<node> a;
    CB cb;

    segtreebeats(int n, CB cb) : cb(cb) {
        maxn = 1;
        while (maxn < n)
            maxn <<= 1;
        a.assign(2*maxn, node{0, 0, 0});
    }

    void push(int x) {
        a[x].lo += a[x].lz;
        a[x].hi += a[x].lz;
        if (x < maxn) {
            a[2*x  ].lz += a[x].lz;
            a[2*x+1].lz += a[x].lz;
        }
        a[x].lz = 0;
    }

    void pull(int x) {
        a[x].lo = min(a[2*x].lo, a[2*x+1].lo);
        a[x].hi = max(a[2*x].hi, a[2*x+1].hi);
    }

    void add_delta(int l, int r, ll u, int x, int xl, int xr) {
        if (r <= xl || xr <= l)
            return push(x);
        if (l <= xl && xr <= r)
            return a[x].lz += u, push(x), cb(xl, xr, u);
        push(x);
        int xm = (xl+xr) >> 1;
        add_delta(l, r, u, 2*x  , xl, xm);
        add_delta(l, r, u, 2*x+1, xm, xr);
        pull(x);
    }

    void max_set(int l, int r, ll u, int x, int xl, int xr) {
        if (r <= xl || xr <= l)
            return push(x);

        if (l <= xl && xr <= r && a[x].hi == a[x].lo) {
            push(x);
            ll d = max(u, a[x].hi) - a[x].hi; 
            return a[x].lz += d, push(x), cb(xl, xr, d);
        }
        
        push(x);
        int xm = (xl+xr) >> 1;
        max_set(l, r, u, 2*x  , xl, xm);
        max_set(l, r, u, 2*x+1, xm, xr);
        pull(x);
    }

    void min_set(int l, int r, ll u, int x, int xl, int xr) {
        if (r <= xl || xr <= l)
            return push(x);

        if (l <= xl && xr <= r && a[x].hi == a[x].lo) {
            push(x);
            ll d = min(u, a[x].hi) - a[x].hi; 
            return a[x].lz += d, push(x), cb(xl, xr, d);
        }
        
        push(x);
        int xm = (xl+xr) >> 1;
        min_set(l, r, u, 2*x  , xl, xm);
        min_set(l, r, u, 2*x+1, xm, xr);
        pull(x);
    }

    void add_delta(int l, int r, ll u) { add_delta(l, r, u, 1, 0, maxn); }
    void max_set(int l, int r, ll u) { max_set(l, r, u, 1, 0, maxn); }
    void min_set(int l, int r, ll u) { min_set(l, r, u, 1, 0, maxn); }

};

void cb(int l, int r, ll d) {
    stlz.update(l, r, d);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, q;
    cin >> n >> q;

    segtreebeats stb1(n+1, cb), stb2(n+1, cb);

    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        stb1.add_delta(i, i+1, x);
    }

    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        stb2.add_delta(i, i+1, x);
    }
    
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, l, r, x;
            cin >> k >> l >> r >> x;
            (k == 1 ? stb1 : stb2).min_set(l, r+1, x);
        } else if (t == 2) {
            int k, l, r, x;
            cin >> k >> l >> r >> x;
            (k == 1 ? stb1 : stb2).max_set(l, r+1, x);
        } else if (t == 3) {
            int k, l, r, x;
            cin >> k >> l >> r >> x;
            (k == 1 ? stb1 : stb2).add_delta(l, r+1, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << stlz(l, r+1)[0][1]() << '\n';
        }
    }
}
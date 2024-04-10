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

const int mod = 998'244'353;
typedef modint<mod> mint;

template<class T = mint>
struct binomial {
    vector<T> f, finv;

    binomial(int n) : f(n), finv(n) {
        f[0] = finv[0] = 1;
        for (int i=1; i<n; i++) {
            f[i] = f[i-1] * i;
            finv[i] = T(1) / f[i];
        }
    }

    T mix(int a, int b) {
        if (a < 0 || b < 0)
            return 0;
        return f[a+b] * finv[a] * finv[b];
    }

    T choose(int n, int k) {
        return mix(n-k, k);
    }
};

template<class T>
struct treap {
    struct node : T {
        unsigned p;
        int l, r;
        
        template<class... A>
        node(A&&... a) : T(forward<A>(a)...) {}
    };

    ranlux48 re;
    vector<node> b;

    treap() : re(chrono::high_resolution_clock::now().time_since_epoch().count()) {}
    
    template<class... A>
    int create(A&&... a) {
        b.emplace_back(forward<A...>(a)...);
        b.back().l = b.back().r = -1;
        b.back().p = re();
        return b.size() - 1;
    }

    void enter(int x) {
        if (x != -1) b[x].enter(b, x);
    }

    void pull(int x) {
        b[x].pull(b, x);
    }

    int join(int x, int y) {
        enter(x); enter(y);
        if (x == -1) return y;
        if (y == -1) return x;
        if (b[x].p > b[y].p) {
            b[y].l = join(x, b[y].l);
            pull(y);
            return y;
        } else {
            b[x].r = join(b[x].r, y);
            pull(x);
            return x;
        }
    }

    template<class S>
    pair<int, int> split(int x, S&& s) {
        enter(x);
        if (x == -1) return {-1, -1};
        if (s(b, x)) {
            auto [y, z] = split(b[x].r, s);
            b[x].r = y;
            pull(x);
            return {x, z};
        } else {
            auto [y, z] = split(b[x].l, s);
            b[x].l = z;
            pull(x);
            return {y, x};
        }
    }

    template<class E>
    void enumerate(int x, E&& e) {
        if (x == -1) return;
        enter(x);
        enumerate(b[x].l, e);
        e(b, x);
        enumerate(b[x].r, e);
    }

    // Splits using sl first, then sr on the right piece
    template<class F, class SL, class SR>
    int run(int x, SL&& sl, SR&& sr, F&& f) {
        auto [p, q] = split(x, sl);
        auto [r, s] = split(q, sr);
        f(b, r);
        return join(p, join(r, s));
    }

    template<class S, class... A>
    int emplace(int x, S&& s, A&&... a) {
        int y = create(forward<A>(a)...);
        auto [p, q] = split(x, s);
        return join(p, join(y, q));
    }
};

// Inherit to implement sum of subtree trait
template<class T>
struct treap_sum {
    T m_sum_root;
    T m_sum_total;

    template<class N>
    void pull(vector<N>& a, int x) {
        m_sum_total = a[x].l == -1 ? a[x].m_sum_root : a[a[x].l].m_sum_total + a[x].m_sum_root;
        if (a[x].r != -1) m_sum_total = m_sum_total + a[a[x].r].m_sum_total;
    }

    struct splitter {
        T s;

        splitter(T s) : s(s) {}

        template<class N>
        bool operator() (vector<N>& a, int x) {
            T w = a[x].l == -1 ? a[x].m_sum_root : a[a[x].l].m_sum_total + a[x].m_sum_root;
            return s >= w ? (s -= w, true) : false;
        }
    };
};

// Inherit to implement simple data storage trait
template<class T>
struct treap_data {
    T m_data;
};

// Inherit to implement single-element lazy updates trait
template<class T>
struct treap_update {
    T m_update;

    treap_update(T u = T()) : m_update(u) {}

    template<class N>
    void enter(vector<N>& a, int x) {
        N& n = a[x];
        n.m_data = n.m_data + m_update;
        if (n.l != -1) a[n.l].m_update = a[n.l].m_update + n.m_update;
        if (n.r != -1) a[n.r].m_update = a[n.r].m_update + n.m_update;
        n.m_update = T();
    }
};

template<class T, class F = less<T>>
struct treap_compare_splitter {
    T v; F f;
    treap_compare_splitter(const T& v, F f = {}) : v(v), f(f) {}

    template<class N>
    bool operator() (vector<N>& a, int x) {
        return f(a[x].m_data, v);
    }
};

// Inherit to implement reverse trait
struct treap_reverser {
    bool m_reversed;

    template<class N>
    void enter(vector<N>& a, int x) {
        N& n = a[x];
        if (n.m_reversed) {
            swap(n.l, n.r);
            if (n.l != -1) a[n.l].m_reversed ^= 1;
            if (n.r != -1) a[n.r].m_reversed ^= 1;
        }
        n.m_reversed = false;
    }

    struct runner {
        template<class N>
        void operator() (vector<N>& a, int x) {
            if (x != -1) a[x].m_reversed ^= 1;
        }
    };
};

// Inherit to implement size trait
struct treap_size {
    int m_size;

    treap_size() : m_size(1) {}

    template<class N>
    void pull(vector<N>& a, int x) {
        m_size = 1;
        if (a[x].l != -1) m_size += a[a[x].l].m_size;
        if (a[x].r != -1) m_size += a[a[x].r].m_size;
    }

    struct splitter {
        int s;

        splitter(int s) : s(s) {}

        template<class N>
        bool operator() (vector<N>& a, int x) {
            int w = 1;
            if (a[x].l != -1) w += a[a[x].l].m_size;
            return s >= w ? (s -= w, true) : false;
        }
    };
};

// Implement your treap policy here 
struct treap_policy : treap_data<int>, treap_update<int> {
    treap_policy(int x) {
        m_data = x;
    }

    template<class N>
    void enter(vector<N>& a, int x) {
        treap_update<int>::enter(a, x);
    }

    template<class N>
    void pull(vector<N>& a, int x) {

    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;

    binomial bk(400005);

    while (t--) {
        int n, k;
        cin >> n >> k;

        treap<treap_policy> tr;
        int root = -1;

        for (int i=0; i<k; i++) {
            int x, y;
            cin >> x >> y;
            auto [r1, r2] = tr.split(root, treap_compare_splitter(y));
            auto [r11, r12] = tr.split(r1, treap_compare_splitter(y-1));
            if (r2 != -1) tr.b[r2].m_update += 1;
            int r13 = tr.create(y);
            root = tr.join(tr.join(r11, r13), r2);
        }

        int cuts = 0;
        tr.enumerate(root, [&](auto& v, int x) { cuts++; });
        cout << bk.choose(2*n-1-cuts, n)() << '\n';
    }
}
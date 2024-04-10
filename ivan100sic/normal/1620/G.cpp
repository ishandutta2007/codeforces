// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

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
    bool operator!= (const modint& other) const { return x != other.x; }
    int operator() () const { return x; }
    template<class T> modint operator^= (T n) { return *this = *this ^ n; }
    modint inv() const { return *this ^ (m-2); }
};

const int mod = 998'244'353;
typedef modint<mod> mint;

template<class T>
struct bit_lattice {
    int N, n;
    vector<T> a;

    bit_lattice(const vector<T>& a) : N(a.size()), n(__builtin_ctz(N)), a(a) {}
    bit_lattice(int n) : N(1 << n), n(n), a(N) {}
    T& operator[] (int x) { return a[x]; }
    const T& operator[] (int x) const { return a[x]; }

    template<int Up, class F, class G>
    static void loop(int N, F f, G g) {
        for (int i=1; i<N; i<<=1)
            for (int j=(Up?0:N-1); j!=(Up?N:-1); j+=(Up?1:-1))
                if (j & i) f(g(j - i), g(j));
    }

    template<int Up, class F>
    void loop(F f) {
        loop<Up>(N, f, [this](int x) -> T& { return a[x]; });
    }

    void mul(const bit_lattice& b) { for (int i=0; i<N; i++) a[i] *= b[i]; }
    void mul(T b) { for (int i=0; i<N; i++) a[i] *= b; }

    void sos() { loop<1>([](T& l, T& h) { h += l; }); }
    void sos_inv() { loop<0>([](T& l, T& h) { h -= l; }); }
    void sos_zero() { loop<1>([](T& l, T& h) { l += h; }); }
    void sos_zero_inv() { loop<0>([](T& l, T& h) { l -= h; }); }
    void fft2n() { loop<1>([](T& l, T& h) { T s = l + h, d = l - h; l = s; h = d; }); }

    void operator|= (bit_lattice b) { sos(); b.sos(); mul(b); sos_inv(); }
    void operator&= (bit_lattice b) { sos_zero(); b.sos_zero(); mul(b); sos_zero_inv(); }
    void operator^= (bit_lattice b) { fft2n(); b.fft2n(); mul(b); fft2n(); mul(T(1) / T(N)); }

    // Subset convolution
    void add_sc(T* a, T* b) const {
        for (int i=0; i<=n; i++) a[i] += b[i]; 
    }

    void sub_sc(T* a, T* b) const {
        for (int i=0; i<=n; i++) a[i] -= b[i]; 
    }

    void mul_sc(T* a, T* b) const {
        for (int i=n; i>=0; i--) {
            T t = 0;
            for (int j=0; j<=i; j++) t += a[j] * b[i-j];
            a[i] = t;
        }
    }

    vector<T> sos_sc() const {
        vector<T> b(N*(n+1));
        for (int i=0; i<N; i++) b[i*(n+1)+__builtin_popcount(i)] = a[i];
        loop<1>(N, [this](T* a, T* b) { add_sc(b, a); }, [&, this](int i) { return b.data()+i*(n+1); });
        return b;
    }

    void sos_inv_sc(vector<T>& b) const {
        loop<0>(N, [this](T* a, T* b) { sub_sc(b, a); }, [&, this](int i) { return b.data()+i*(n+1); });
    }

    [[nodiscard]] bit_lattice subset_conv(const bit_lattice& b) const {
        auto c = sos_sc();
        auto d = b.sos_sc();
        for (int i=0; i<N*(n+1); i+=n+1) mul_sc(c.data()+i, d.data()+i);
        sos_inv_sc(c);
        bit_lattice e(n);
        for (int i=0; i<N; i++) e[i] = c[i*(n+1) + __builtin_popcount(i)];
        return e;
    }
};

struct bitmask {
    int m;

    bitmask(int m = 0) : m(m) {}
    operator int() const { return m; }
    int operator() () const { return m; }
    bitmask operator& (bitmask b) const { return m & b.m; }
    bitmask operator| (bitmask b) const { return m | b.m; }
    bitmask operator^ (bitmask b) const { return m ^ b.m; }
    bitmask& operator&= (bitmask b) { return *this = *this & b; }
    bitmask& operator|= (bitmask b) { return *this = *this | b; }
    bitmask& operator^= (bitmask b) { return *this = *this ^ b; }
    bitmask& set(int i) { m |= 1 << i; return *this; }
    bitmask& reset(int i) { m &= ~(1 << i); return *this; }
    bitmask& flip(int i) { m ^= 1 << i; return *this; }
    int operator[](int i) const { return 1 & (m >> i); }
    int popcnt() { return __builtin_popcount(m); }

    struct iterator {
        int n, i, m, v;
        void mv() { while (i < n && v != ((m >> i) & 1)) i++; }
        int operator*() const { return i; }
        bool operator== (const iterator& b) const { return i == b.i; }
        bool operator!= (const iterator& b) const { return !(*this == b); }
        iterator& operator++() { i++; mv(); return *this; }
    };

    struct iterable {
        int n, m, v;
        iterator begin() const { iterator i{n, 0, m, v}; i.mv(); return i; }
        iterator end() const { iterator i{n, n, m, v}; i.mv(); return i; }
    };

    iterable on(int n) const { return {n, m, 1}; }
    iterable off(int n) const { return {n, m, 0}; }
};

struct mask_loop {
    int f, t;

    // size of mask, number of items to skip from start and end
    mask_loop(int n, int f = 0, int t = 0) : f(f), t((1 << n) - t) {
        t = max(t, f);
    }

    struct iterator {
        int m;
        bitmask operator*() const { return m; }
        bool operator== (const iterator& b) const { return m == b.m; }
        bool operator!= (const iterator& b) const { return !(*this == b); }
        iterator& operator++() { m++; return *this; }
    };

    iterator begin() const { return {f}; }
    iterator end() const { return {t}; }
};

struct submask_loop {
    int m;

    submask_loop(int m) : m(m) {}

    struct iterator {
        int i, m;
        bitmask operator*() const { return m - i; }
        bool operator== (const iterator& b) const { return i == b.i; }
        bool operator!= (const iterator& b) const { return !(*this == b); }
        iterator& operator++() { i = i ? (i-1) & m : -1; return *this; }
    };

    iterator begin() const { return {m, m}; }
    iterator end() const { return {-1, m}; }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;
    vector<array<int, 26>> a(n);
    for (auto& b : a) {
        string s;
        cin >> s;
        for (char c : s) {
            b[c-'a']++;
        }
    }

    bit_lattice<mint> la(n);
    for (auto m : mask_loop(n, 1)) {
        array<int, 26> b;
        R::fill(b, 123123123);
        for (int i : m.on(n)) {
            for (int j : ra(0, 26)) b[j] = min(b[j], a[i][j]);
        }

        mint p = m.popcnt() % 2 ? 1 : -1;
        for (int x : b) p *= x + 1;
        la[m] = p;
    }

    la.sos();
    ll sol = 0;
    for (auto m : mask_loop(n)) {
        ll k = 0, f = 0;
        for (int i : m.on(n)) {
            k += 1;
            f += i + 1;
        }

        sol ^= la[m]() * k * f;
    }

    cout << sol << '\n';
}
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

void tournament(int* a, bitmask mask, int n, int l, bool win) {
    int b[32];
    for (int i=0; i<n; i++) {
        b[i+n] = i;
        a[i] = -1;
    }

    for (int i=n-1, j=0; i; i--, j++) {
        b[i] = b[2 * i + mask[j]];
    }

    for (int layer=0; layer<l; layer++) {
        for (int x=(1<<layer); x<(2<<layer); x++) {
            if (a[b[x]] == -1) {
                a[b[x]] = layer == 0 ? (win ? 1 : 2) : (1 << layer) + 1;
            }
        }
    }
}

mint pw[64];

mint thash(int* a, int n, int b) {
    mint z = 0;
    for (int i=0; i<n; i++) {
        z += pw[a[i]] * (i + b);
    }
    return z;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, base, target;
    cin >> n >> base >> target;

    int h = 1 << (n-1);
    pw[0] = 1;
    for (int i=1; i<64; i++) pw[i] = pw[i-1] * base;

    for (bool win_left : {true, false}) {
        map<int, bitmask> mp;
        for (auto mask : mask_loop(h-1)) {
            int a[16];
            tournament(a, mask, h, n, win_left);
            mp[thash(a, h, 1)()] = mask;
        }

        for (auto mask : mask_loop(h-1)) {
            int a[16];
            tournament(a, mask, h, n, !win_left);
            if (auto it = mp.find((mint(target) - thash(a, h, h+1))()); it != mp.end())
            {
                int b[16];
                tournament(b, it->second, h, n, win_left);
                for (int i=0; i<h; i++) {
                    cout << b[i] << ' ';
                }
                for (int i=0; i<h; i++) {
                    cout << a[i] << " \n"[i == h-1];
                }
                return 0;
            }
        }
    }

    cout << "-1\n";
    return 0;
}
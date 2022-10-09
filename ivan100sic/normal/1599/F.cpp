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

template<ll m>
struct modll {
    ull x;

    modll() : x(0) {}
    modll(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

    modll operator+ (const modll& b) const {
        auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
    }

    modll operator- (const modll& b) const {
        auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
    }

    modll operator* (const modll& b) const {
        auto t = *this; t.x = (__int128)(t.x) * b.x % m; return t;
    }

    modll operator/ (const modll& b) const {
        return *this * b.inv();
    }

    template<class T> modll operator^ (T n) const {
        modll t;
        if (n == 0) return t.x = 1, t;
        if (n == 1) return t.x = x, t;
        t = *this ^ (n >> 1); t *= t;
        return n & 1 ? *this * t : t;
    }

    modll& operator+= (const modll& b) { return *this = *this + b; }
    modll& operator-= (const modll& b) { return *this = *this - b; }
    modll& operator*= (const modll& b) { return *this = *this * b; }
    modll& operator/= (const modll& b) { return *this = *this / b; }
    modll& operator++ () { if (++x == m) x = 0; return *this; }
    modll& operator-- () { if (x-- == 0) x = m-1; return *this; }
    modll operator++ (int) { modll tmp = *this; ++*this; return tmp; }
    modll operator-- (int) { modll tmp = *this; --*this; return tmp; }
    bool operator== (const modll& other) const { return x == other.x; }
    bool operator!= (const modll& other) const {	return x != other.x; }
    int operator() () const { return x; }
    template<class T> modll operator^= (T n) { return *this = *this ^ n; }
    modll inv() const { return *this ^ (m-2); }
};

const ll mod_small = 1'000'000'007;
typedef modint<mod_small> mint;

const ll mod_big = 728ll * mod_small + 1;
typedef modll<mod_big> mll;
const mll base = 544'176'307'788ll;

int n, q;
int a[200005];
mll zb[200005];
mint zs[200005];

// {1+x+x2+x3+...x^(n-1), x^n}
pair<mll, mll> find_sum_pows(mll x, int n) {
    if (n == 0) return {0, 1};
    
    auto [s, p] = find_sum_pows(x, n/2);
    
    mll p2 = p * p;
    mll s2 = s + p * s;

    if (n % 2) {
        s2 += p2;
        p2 *= x;
    }

    return {s2, p2};
}

// base^first + base^(first + d) + ... n terms
mll find_sum_pows(int first, int d, int n) {
    mll t = find_sum_pows(base ^ d, n).first;
    t *= base ^ first;
    return t;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> q;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        zb[i+1] = zb[i] + (mll(base) ^ a[i]);
        zs[i+1] = zs[i] + a[i];
    }

    while (q--) {
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        mint mean = (zs[r] - zs[l]) / (r-l);
        int first = (mean - mint(d) * (r-l-1)/2)();

        mll tgt = find_sum_pows(first, d, r-l);
        if (tgt == zb[r] - zb[l]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
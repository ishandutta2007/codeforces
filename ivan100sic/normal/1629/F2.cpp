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

const int mod = 1000 * 1000 * 1000 + 7;
typedef modint<mod> mint;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        mint v;
        if (m == 0) v = 0;
        else if (m == 1) v = 2;
        else if (m == 2) v = 2*n+4;
        else {
            mint x = 2, y = 2*n+4;
            for (int i : ra(3, m+1)) {
                mint z = (y*(n+2) - x*(n+1-i)) / (i-1);
                x = y;
                y = z;
            }
            v = y;
        }

        v *= mint(k) / (mint(2) ^ n);
        cout << v() << '\n';
    }
}

/*
y13[1] := 2; y13[2] := 30; 
y13[n_] := 1/(n - 1) (15 y13[n - 1] - (14 - n) y13[n - 2]);
*/
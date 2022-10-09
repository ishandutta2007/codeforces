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

int n, k;
mint d[505][505];

mint bk[505][505];
mint pw[505][505];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    for (int i=0; i<505; i++) bk[i][0] = bk[0][i] = pw[i][0] = 1;
    for (int i : ra(1, 505)) {
        for (int j : ra(1, 505)) {
            bk[i][j] = bk[i-1][j] + bk[i][j-1];
            pw[i][j] = pw[i][j-1] * i;
        }
    }

    cin >> n >> k;

    for (int i : ra(1, k+1)) d[2][i] = i;

    for (int i : ra(3, n+1)) {
        for (int j : ra(1, k+1)) {
            mint z = 0;
            for (int x : ra(0, i+1)) {
                mint w = bk[x][i-x];
                w *= pw[min(i-1, j)][x];
                if (i-x == 0) {
                    // ok, 1
                } else {
                    if (j-(i-1) < 0) {
                        w = 0;
                    } else {
                        w *= d[i-x][j-(i-1)];
                    }
                }
                z += w;
            }
            d[i][j] = z;
        }
    }

    cout << d[n][k]() << '\n';
}
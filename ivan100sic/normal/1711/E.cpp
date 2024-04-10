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

mint d[2][8][8];

int btype(int x) {
    switch (x) {
        case 0: case 7: return 0;
        case 1: case 6: return 1;
        case 2: case 5: return 2;
        case 3: case 4: return 4;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    string s;
    cin >> s;

    const int n = ssize(s);

    d[0][0][0] = 1;
    for (int i : ra(0, n)) {
        char c = s[i];
        auto ol = d[i%2];
        auto nu = d[(i+1)%2];
        memset(nu, 0, sizeof(d[0]));

        for (int i : ra(0, 8)) {
            for (int j : ra(0, 8)) {
                for (int k : ra(0, 8)) {
                    int i2 = i | btype(k);
                    // forbidden?
                    if (c == '0' && (k & ~j)) continue;

                    int j2 = j | ((c == '1' ? 7 : 0) & ~k);

                    nu[i2][j2] += ol[i][j];
                }
            }
        }
    }

    auto z = d[n % 2][7];
    cout << accumulate(z, z+8, mint{})() << '\n';
}
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

int n;
int a[100005];

const int LIMIT = 200;

mint gcdsum(vector<int> a) {
    int n = a.size();
    if (n <= LIMIT) {
        mint sol = 0;
        for (int i : ra(0, n)) {
            sol += a[i];
            for (int j : ra(i+1, n)) {
                sol += 2 * gcd(a[i], a[j]);
            }
        }
        return sol;
    } else {
        vector<mint> z(100005);
        for (int x : a) {
            z[x]++;
        }

        for (int i : ra(1, 100001)) {
            for (int j=2*i; j<=100000; j+=i) {
                z[i] += z[j];
            }
        }

        for (mint& x : z) {
            x *= x;
        }

        for (int i = 100000; i>=1; i--) {
            for (int j=2*i; j<=100000; j+=i) {
                z[i] -= z[j];
            }
        }

        mint sol = 0;
        for (int i : ra(1, 100001)) {
            sol += z[i] * i;
        }

        return sol;
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    vector<mint> g(n+1);
    for (int i=1; i<=n; i++) {
        vector<int> b;
        for (int j=i; j<=n; j+=i) {
            b.push_back(a[j]);
        }
        g[i] = gcdsum(b);
    }

    for (int i = n; i>=1; i--) {
        for (int j=2*i; j<=n; j+=i) {
            g[i] -= g[j];
        }
    }

    mint sol = 0;
    for (int i : ra(1, n+1)) {
        sol += g[i] * i;
    }

    cout << sol() << '\n';
}
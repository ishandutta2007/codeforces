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

binomial bk(200005);

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        mint vece, manje, jednako;
        for (int i=0; i<=n; i++) {
            int a = i == n;
            int x = i % 2;
            if (a > x) vece += bk.choose(n, i);
            else if (a == x) jednako += bk.choose(n, i);
            else manje += bk.choose(n, i);
        }

        mint gr = 0, eq = 1;
        for (int i=1; i<=k; i++) {
            mint gr2 = gr * (vece + manje + jednako) + eq * vece;
            mint eq2 = eq * jednako;
            gr = gr2;
            eq = eq2;
        }

        cout << (gr + eq)() << '\n';
    }
}
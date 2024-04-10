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

int n, m;
int l[55], r[55];
mint sol[100005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> l[i] >> r[i];

    for (int g=1; g<=100000; g++) {
        int w = m / g;
        vector<mint> dp(w+1);
        dp[0] = 1;
        for (int i=0; i<n; i++) {
            vector<mint> nu(w+1);
            int lb = (l[i]+g-1)/g;
            int ub = r[i]/g;
            for (int u=0; u<=w; u++) {
                if (u + lb <= w) {
                    nu[u+lb] += dp[u];
                }
                if (u + ub + 1 <= w) {
                    nu[u + ub + 1] -= dp[u];
                }
            }

            for (int i=1; i<=w; i++) nu[i] += nu[i-1];
            swap(dp, nu);
        }

        sol[g] = accumulate(begin(dp), end(dp), mint(0));
    }

    for (int i=100000; i; i--) {
        for (int j=2*i; j<=100000; j+=i) {
            sol[i] -= sol[j];
        }
    }

    cout << sol[1]() << '\n';
}
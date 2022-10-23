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

    modint operator-() const {
        auto t = *this; t.x = x ? m-x : 0; return t; 
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

/*
Index i is pseudowinner -> i is 1 and (j-1)/2 + 1 .. i-1 are zeros
*/

// num ways to have j pseudowinners in digits starting from ith
// dp runs backwards
mint dp[1000015][24];
mint pw2[1000015];
mint pw2inv[1000015];

void calc_dp(int n) {
    pw2[0] = 1;
    for (int i : ra(1, n+2)) {
        pw2[i] = pw2[i-1] + pw2[i-1];
        pw2inv[i] = pw2[i].inv();
    }

    for (int i : ra(0, n+5)) {
        R::fill(dp[i], mint{});
    }
    dp[n][0] = 1;

    for (int i=n-1; i>=1; i--) {
        for (int j : ra(0, 21)) {
            dp[i][j] += dp[i+1][j];

            if (2*i <= n) {
                if (2*i == n) {
                    dp[i][j+1] += dp[2*i][j] * pw2inv[i-1];
                } else {
                    dp[i][j+1] += dp[2*i][j] * pw2inv[i];
                }
            }

            if (2*i+1 <= n) {
                if (2*i+1 == n) {
                    dp[i][j+1] += dp[2*i+1][j] * pw2inv[i];
                } else {
                    dp[i][j+1] += dp[2*i+1][j] * pw2inv[i+1];
                }
            }
        }
    }
}

void solve(int n) {
    if (n == 2) {
        cout << "0\n1\n";
        return;
    }

    if (n == 1) {
        cout << "1\n";
        return;
    }

    calc_dp(n);

    for (int i : ra(0, n)) {
        mint good = 0;

        if (i == n-1) {
            good = 1;
        } else {
            good = pw2[n-2-i];

            for (int j : ra(1, 21)) {
                mint sgn = j % 2 ? -1 : 1;
                mint p = pw2[n-2-i];
                p *= dp[i+1][j];
                good += p * sgn;
            }
        }

        good *= 2;

        mint sol = good * pw2[(i+1)/2];

        sol *= pw2inv[n];

        cout << sol() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
}
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

array<mint, 6> dp[66];
set<ll> special;
map<ll, int> target;

array<mint, 6> solve(ll x, int k) {
    if (!special.count(x)) return dp[k];

    int tgt = target.count(x) ? target[x] : -1;
    if (k == 1) {
        if (tgt != -1) {
            array<mint, 6> ret;
            ret[tgt] = 1;
            return ret;
        } else {
            array<mint, 6> ret = {1, 1, 1, 1, 1, 1};
            return ret;
        }
    }

    auto sl = solve(2*x, k-1);
    auto sr = solve(2*x+1, k-1);
    array<mint, 6> ret;
    for (int c=0; c<6; c++) {
        if (tgt != -1 && c != tgt) continue;

        for (int l=0; l<6; l++) {
            for (int r=0; r<6; r++) {
                if (l % 3 != c % 3 && r % 3 != c % 3) {
                    ret[c] += sl[l] * sr[r];
                }
            }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int k;
    cin >> k;

    for (int i=0; i<6; i++) dp[1][i] = 1;
    
    for (int i=1; i<k; i++) {
        for (int j=0; j<6; j++) {
            for (int k=0; k<6; k++) {
                for (int l=0; l<6; l++) {
                    if (l % 3 != j % 3 && l % 3 != k % 3) {
                        dp[i+1][l] += dp[i][j] * dp[i][k];
                    }
                }
            }
        }
    }

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        ll x;
        string c;
        cin >> x >> c;
        int y = string("wgrybo").find(c[0]);
        target[x] = y;
        for (ll t=x; t; t>>=1) special.insert(t);
    }

    auto c1 = solve(1, k);
    cout << accumulate(c1.begin(), c1.end(), mint(0))() << '\n';
}
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

const int prod = 720720;

int n, a0, x, y, k, M;

mint dp[16][140];
mint take, dont;

void calc_fall(int r, mint* out) {
    if (k == 1) {
        out[0] = 0;
        return;
    }

    out[0] = out[1] = 0;

    if (k == 2) {
        return;
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    int last_hi = 0;
    for (int i : ra(0, k-2)) {
        for (int j : ra(0, last_hi + 1)) {
            dp[i+1][j] += dp[i][j] * dont;
            int j2 = j + (r-j) % (i+2);
            dp[i+1][j2] += dp[i][j] * take;
            last_hi = max(last_hi, j2);
        }

        mint tz = 0;
        for (int j : ra(0, last_hi + 1)) {
            tz += dp[i+1][j] * j;
        }
        out[i+2] = tz;
    }
}

mint fall[prod][17];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> a0 >> x >> y >> k >> M;

    take = mint(n).inv();
    dont = mint(1) - take;

    for (int i : ra(0, prod)) {
        calc_fall(i, fall[i]);
    }

    mint sol = 0;

    auto go = [&](int x) {
        for (int i : ra(0, k)) {
            sol += (mint(x) - fall[x % prod][i]);
        }
    };

    int ai = a0;
    for (int i : ra(0, n)) {
        go(ai);
        ai = (ai * 1ll * x + y) % M;
    }

    cout << (sol * (mint(n) ^ (k - 1)))() << '\n';
}
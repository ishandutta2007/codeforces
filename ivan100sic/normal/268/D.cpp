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

const int mod = 1000 * 1000 * 1000 + 9;
typedef modint<mod> mint;

mint dp[2][33][33][33][33];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, h;
    cin >> n >> h;
    dp[0][0][0][0][0] = 1;

    for (int i=1; i<=n; i++) {
        auto ol = dp[1-i%2];
        auto nu = dp[i%2];
        memset(nu, 0, sizeof(dp[0]));
        
        for (int a1 : ra(0, h+2))
        for (int a2 : ra(a1, h+2))
        for (int a3 : ra(a2, h+2))
        for (int a4 : ra(a3, h+2))
        {
            auto olv = ol[a1][a2][a3][a4];
            if (olv == 0) continue;

            array<int, 4> a = {a1, a2, a3, a4};
            for (int j : ra(0, 4)) {
                auto b = a;
                for (int k : ra(0, 4)) {
                    if (k != j) {
                        b[k] = min(a[k] + 1, h + 1);
                    } else {
                        b[k] = a[k] >= h ? h + 1 : 0;
                    }
                }

                R::sort(b);
                nu[b[0]][b[1]][b[2]][b[3]] += olv;
            }
        }
    }

    mint sol = 0;

    for (int a1 : ra(0, h))
    for (int a2 : ra(a1, h+2))
    for (int a3 : ra(a2, h+2))
    for (int a4 : ra(a3, h+2))
    {
        sol += dp[n%2][a1][a2][a3][a4];
    }

    cout << sol() << '\n';
}
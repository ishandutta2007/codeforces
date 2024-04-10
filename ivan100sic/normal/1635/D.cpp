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

    int n, p;
    cin >> n >> p;
    vector<int> a(n), b;
    for (int& x : a) {
        cin >> x;
    }

    auto bhas = [&](int x) {
        auto it = R::lower_bound(b, x);
        return it != end(b) && *it == x;
    };

    R::sort(a);
    for (int x : a) {
        int y = x, f = 0;
        while (y > 0) {
            if (bhas(y)) {
                f = 1;
                break;
            } else {
                if (y % 2) {
                    y >>= 1;
                } else if (y % 4 == 0) {
                    y >>= 2;
                } else {
                    break;
                }
            }
        }
        if (!f) {
            b.push_back(x);
        }
    }

    vector<int> c(200005);
    for (int x : b) {
        c[bit_width(1u * x)]++;
    }

    vector<mint> dp(200005);
    for (int i : ra(0, p+1)) {
        if (i) dp[i] += dp[i-1];
        if (i > 1) dp[i] += dp[i-2];
        dp[i] += c[i];
    }

    cout << accumulate(begin(dp), begin(dp) + p + 1, mint{})() << '\n';
}
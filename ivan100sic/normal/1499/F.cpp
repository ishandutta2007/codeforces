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

int n, k;
vector<mint> dp[5005];
basic_string<int> e[5005];

void dfs(int x, int p) {
    vector<mint> w = {1};
    for (int y : e[x]) {
        if (y == p) continue;
        dfs(y, x);
        vector<mint> u = std::move(w);
        w = {};
        const vector<mint>& v = dp[y];

        auto add = [&](int idx, mint val) {
            while (idx >= (int)w.size()) w.emplace_back();
            w[idx] += val;
        };

        for (int i=0; i<(int)u.size(); i++) {
            for (int j=0; j<(int)v.size(); j++) {
                // take v
                if (i + j + 1 <= k) {
                    add(max(i, j+1), u[i] * v[j]);
                }

                // don't
                if (i <= k) {
                    add(max(i, 0), u[i] * v[j]);
                }
            }
        }
    }

    dp[x] = std::move(w);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> k;
    for (int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        e[x] += y;
        e[y] += x;
    }

    dfs(1, 1);

    cout << accumulate(begin(dp[1]), end(dp[1]), mint())() << '\n';
}
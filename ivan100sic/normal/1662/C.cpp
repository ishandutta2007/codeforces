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

int n_glob;

struct mat {
    vector<mint> a;
    int n, m;

    mat() {
        n = m = n_glob;
        a.resize(m*n);
    }

    static mat eye() {
        mat t;
        for (int i=0; i<t.n; i++)
            t[i][i] = 1;
        return t;
    }

    mat operator* (const mat& b) const {
        mat c;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                for (int k=0; k<b.m; k++)
                    c[i][k] += a[m*i+j] * b[j][k];
        return c;
    }

    mat& operator+= (const mat& b) {
        for (int i=0; i<n*m; i++)
            a[i] += b.a[i];
        return *this;
    }

    mat& operator-= (const mat& b) {
        for (int i=0; i<n*m; i++)
            a[i] -= b.a[i];
        return *this;
    }

    mat operator- () const {
        mat b = *this;
        for (int i=0; i<n*m; i++)
            b.a[i] = mint{}-b.a[i];
        return b;
    }

    mint* operator[] (int x) { return a.data() + m*x; }
    const mint* operator[] (int x) const { return a.data() + m*x; }
    mat operator+ (const mat& b) const { auto t = *this; t += b; return t; }
    mat operator- (const mat& b) const { auto t = *this; t -= b; return t; }
    mat& operator*= (const mat& b) { return *this = *this * b; }
    template<class U> mat operator^= (U arg) { return *this = *this ^ arg; }
};

struct megamat {
    array<mat, 4> a;
    constexpr static int n = 2;
    constexpr static int m = 2;

    megamat() {
    }

    static megamat eye() {
        megamat m;
        m[0][0] = m[1][1] = mat::eye();
        return m;
    }

    megamat operator* (const megamat& b) const {
        megamat c;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                for (int k=0; k<b.m; k++)
                    c[i][k] += a[m*i+j] * b[j][k];
        return c;
    }

    megamat& operator+= (const megamat& b) {
        for (int i=0; i<n*m; i++)
            a[i] += b.a[i];
        return *this;
    }

    mat* operator[] (int x) { return a.data() + m*x; }
    const mat* operator[] (int x) const { return a.data() + m*x; }
    megamat operator+ (const megamat& b) const { auto t = *this; t += b; return t; }
    megamat& operator*= (const megamat& b) { return *this = *this * b; }
    template<class U> megamat operator^= (U arg) { return *this = *this ^ arg; }

    template<class U>
    megamat operator^ (U arg) const {
        if (arg == 0)
            return megamat::eye();
        if (arg == 1)
            return *this;
        auto t = *this ^ (arg >> 1);
        t *= t;
        if (arg & 1)
            t *= *this;
        return t;
    }
};


void debug(mat a) {
    cerr << "~~\n";
    for (int i : ra(0, a.n)) {
        for (int j : ra(0, a.m)) {
            cout << a[i][j]() << ' ';
        }
        cerr << '\n';
    }
    cerr << "~~\n";
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, m, k;
    cin >> n >> m >> k;

    n_glob = n;

    auto dp = [&]() {
        vector<array<int, 105>> a(105);
        for (int i : ra(0, m)) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            a[x][y]++;
            a[y][x]++;
        }

        vector<array<array<array<mint, 105>, 105>, 105>> dp(2);
        for (int i : ra(0, n)) {
            for (int j : ra(0, n)) {
                dp[1][i][i][j] += a[i][j];
            }
        }

        for (int i : ra(2, k+1)) {
            memset(&dp[i%2], 0, sizeof(dp[0]));
            for (int x : ra(0, n)) {
                for (int y : ra(0, n)) {
                    for (int z : ra(0, n)) {
                        for (int t : ra(0, n)) {
                            if (y != t) {
                                dp[i%2][x][z][t] += dp[1-i%2][x][y][z] * a[z][t];
                            }
                        }
                    }
                }
            }
        }

        mint sol = 0;
        for (int i : ra(0, n)) {
            for (int j : ra(0, n)) {
                sol += dp[k%2][i][j][i];
            }
        }

        cout << sol() << "\n";
        return 0;
    };

    // int tp;
    // cin >> tp;
    // if (tp == 0) {
    //     return dp();
    // }

    mat a, b;
    for (int i : ra(0, m)) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x][y]++;
        a[y][x]++;
        b[x][x]++;
        b[y][y]++;
    }

    if (k <= 2) {
        cout << "0\n";
        return 0;
    }

    map<int, megamat> cache;

    megamat pw;
    pw[0][0] = mat{};
    pw[0][1] = mat::eye();
    pw[1][0] = -b+mat::eye();
    pw[1][1] = a;
    auto pw0 = pw;
    pw ^= k-1;

    auto result = a * pw[0][0] + (a*a-b) * pw[0][1];

    // debug((pw0 ^ 1)[0][0]);
    // debug((pw0 ^ 2)[0][0]);
    // debug((pw0 ^ 3)[0][0]);
    // debug((pw0 ^ 4)[0][0]);
    // debug(result);

    mint z = 0;
    for (int i : ra(0, n)) {
        // cerr << i << ' ' << result[i][i]() << '\n';
        z += result[i][i];
    }

    cout << z() << '\n';
}

/*
4 5 4
1 3
4 2
4 1
2 1
3 4
*/
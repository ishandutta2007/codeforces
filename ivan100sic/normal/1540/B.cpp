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

int n;
basic_string<int> e[205];

int d[205], par[205], l[205], r[205], dt;
int lca[205][205];

void dfs(int x, int p) {
    par[x] = p;
    l[x] = ++dt;
    for (int y : e[x]) {
        if (y == p) continue;
        d[y] = d[x] + 1;
        dfs(y, x);
    }
    r[x] = ++dt;
}

void svelca() {
    memset(lca, 0, sizeof lca);
    vector<int> vd(n);
    iota(begin(vd), end(vd), 1);
    sort(begin(vd), end(vd), [&](int x, int y) { return d[x] < d[y]; });
    for (int x : vd) {
        for (int y : vd) {
            if (d[x] > d[y]) {
                continue;
            }
            if (l[x] <= l[y] && r[y] <= r[x]) {
                lca[x][y] = x;
            } else {
                lca[x][y] = lca[par[x]][y];
            }
        }
    }

    for (int x : vd) {
        for (int y : vd) {
            if (lca[x][y] == 0) {
                lca[x][y] = lca[y][x];
            }
        }
    }
}

mint z;
mint kf[205][205];

void koef() {
    mint half = mint(1) / 2;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            if (i == 0 && j == 0) continue;
            if (i == 0) {
                kf[i][j] = 0;
            } else if (j == 0) {
                kf[i][j] = 1;
            } else {
                kf[i][j] = (kf[i-1][j] + kf[i][j-1]) * half;
            }
        }
    }
}

void resi() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<i; j++) {
            int l = lca[i][j];
            z += kf[d[j] - d[l]][d[i] - d[l]];
        }
    }
}

// sorry arugo

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;

    koef();

    for (int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        e[x] += y;
        e[y] += x;
    }

    for (int i=1; i<=n; i++) {
        d[i] = 0;
        dt = 0;
        dfs(i, 0);
        svelca();
        resi();
    }

    cout << (z / n)() << '\n';
}
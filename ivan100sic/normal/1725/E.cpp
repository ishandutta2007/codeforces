// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct sieve {
    const int maxn;
    vector<int> f, primes;

    sieve(int maxn) : maxn(maxn), f(maxn) {
        for (int i=2; i<maxn; i++) {
            if (f[i] == 0) {
                f[i] = i;
                primes.push_back(i);
            }

            for (int p : primes) {
                if (p > f[i] || i * p >= maxn) {
                    break;
                }

                f[i*p] = p;
            }
        }
    }

     vector<pair<int, int>> factor_small(int x) const {
        vector<pair<int, int>> v;
        while (x > 1) {
            int p = f[x], c = 0;
            while (x % p == 0) {
                x /= p;
                c++;
            }
            v.emplace_back(p, c);
        }
        return v;
    }

    template<class T>
    vector<pair<T, int>> factor(T x) const {
        vector<pair<T, int>> v;
        for (int p : primes) {
            if ((ll)p*p > x) {
                break;
            }

            if (x % p == 0) {
                int c = 0;
                while (x % p == 0) {
                    x /= p;
                    c++;
                }
                v.emplace_back(p, c);
            }
        }

        if (x > 1) {
            v.emplace_back(x, 1);
        }

        return v;
    }
};


struct tree_topology {
    int n;
    vector<int> p, d, l, r;
    vector<vector<int>> e;

    void dfs(int x, int& t) {
        l[x] = t++;
        for (int y : e[x]) {
            if (y == p[x]) continue;
            d[y] = d[x] + 1;
            p[y] = x;
            dfs(y, t);
        }
        r[x] = t;
    }

    tree_topology(const vector<pair<int, int>>& b) {
        n = b.size() + 1;
        p.resize(n);
        e.resize(n);
        d = l = r = p;
        for (auto l : b) {
            int x, y;
            tie(x, y) = l;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        p[0] = -1;
        int t = 0;
        dfs(0, t);
    }

    bool above(int x, int y) {
        return l[x] <= l[y] && r[y] <= r[x];
    }

    int size(int x) {
        return r[x] - l[x];
    }
};

struct tree_topology_ex : tree_topology {
    int logd;
    vector<vector<int>> a;

    tree_topology_ex(const vector<pair<int, int>>& b, int logd) : tree_topology(b), logd(logd) {
        a.resize(logd);
        a[0] = p;
        for (int i=1; i<logd; i++) {
            a[i].resize(n);
            for (int j=0; j<n; j++) {
                a[i][j] = a[i-1][j] == -1 ? -1 : a[i-1][a[i-1][j]];
            }
        }
    }

    int lift(int x, int k) {
        for (int i=0; i<logd; i++) {
            if (x == -1) return -1;
            if (k & (1 << i)) x = a[i][x];
        }
        return x;
    }

    int lca(int x, int y) {
        if (d[x] > d[y]) swap(x, y);
        y = lift(y, d[y] - d[x]);
        if (x == y) return x;
        for (int i=logd-1; i>=0; i--) {
            int u = a[i][x], v = a[i][y];
            if (u != v) x = u, y = v;
        }
        return p[x];
    }

    int distance(int x, int y) {
        int z = lca(x, y);
        return d[x] + d[y] - 2*d[z];
    }

    int kth(int x, int y, int k) {
        int z = lca(x, y);
        if (k <= d[x] - d[y]) {
            return lift(x, k);
        } else {
            return lift(y, d[x] + d[y] - 2*d[z] - k);
        }
    }
};

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

const int mod = 998'244'353;
typedef modint<mod> mint;

sieve sv(200005);
int n;
int a[200005];
vector<int> g[200005];
vector<pair<int, int>> e;

struct upedge {
    int p, l;
};

int sts[200005];

mint solve(tree_topology_ex& tte, vector<int> g) {
    R::sort(g, [&](int x, int y) { return tte.l[x] < tte.l[y]; });

    vector<int> st;
    map<int, upedge> up;

    for (int x : g) {
        if (st.empty()) {
            st.push_back(x);
            continue;
        }

        int z = tte.lca(x, st.back());
        while (z != st.back()) {
            if (st.size() >= 2 && tte.above(z, st[st.size() - 2])) {
                st.pop_back();
                continue;
            }

            // Must split edge
            if (st.size() >= 2) {
                int b = st.back();
                int p = st[st.size() - 2];
                upedge lower = {z, tte.d[b] - tte.d[z]};
                upedge upper = {p, tte.d[z] - tte.d[p]};
#ifdef LOCAL
                cerr << "splitting " << b << ' ' << z << ' ' << p << '\n';
                cerr << b << ' ' << lower.p << ' ' << lower.l << '\n';
                cerr << z << ' ' << upper.p << ' ' << upper.l << '\n';
#endif
                up[b] = lower;
                up[z] = upper;
                st.pop_back();
                st.push_back(z);
                continue;
            }

            // Must insert edge above
            {
                int b = st.back();
                up[b] = {z, tte.d[b] - tte.d[z]};
#ifdef LOCAL
                cerr << "extending " << b << ' ' << z << ' ' << tte.d[b] - tte.d[z] << '\n';
#endif
                st.pop_back();
                st.push_back(z);
            }
        }

        // x-z edge if needed
        if (x != z) {
            up[x] = {z, tte.d[x] - tte.d[z]};
            st.push_back(x);
        }
    }

    // Sum of distances
    mint sd = 0;
    
    vector<int> h; // Extended tree nodes
    for (auto [k, v] : up) {
        h.push_back(k);
    }
    h.push_back(st[0]); // st[0] = lca of entire tree (no up)

    R::sort(h, [&](int x, int y) { return tte.d[x] > tte.d[y]; });

    for (int x : h) sts[x] = 0;
    for (int x : g) sts[x] = 1;

    for (int x : h) {
        auto it = up.find(x);
        if (it != up.end()) {
            sts[it->second.p] += sts[x];
            sd += 1ll * it->second.l * sts[x] * (ssize(g) - sts[x]);
#ifdef LOCAL
            cerr << "term " << x << ' ' << it->second.p << ' ' << it->second.l << ' ' << sts[x] << ' ' << ssize(g) - sts[x] << "\n";
#endif
        }
    }

    mint ret = sd * (ssize(g) - 2) / 2;
#ifdef LOCAL
    cerr << ret() << '\n';
#endif
    return ret;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i : ra(0, n)) {
        cin >> a[i];
    }

    e.resize(n-1);
    for (auto& [x, y] : e) {
        cin >> x >> y;
        x--, y--;
    }

    tree_topology_ex tte(e, 19);

    for (int i : ra(0, n)) {
        for (auto [p, e] : sv.factor_small(a[i])) {
            g[p].push_back(i);
        }
    }

    mint sol = 0;
    for (int i : ra(2, 200000)) {
        if (g[i].size() >= 3) {
            sol += solve(tte, move(g[i]));
        }
    }

    cout << sol() << '\n';
}
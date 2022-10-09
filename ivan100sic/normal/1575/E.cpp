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

int a[200005], k;

void prefsum(vector<int>& a) {
    int n = a.size();
    for (int i : ra(1, n)) {
        a[i] += a[i-1];
    }
}

int pget(vector<int>& a, int p) {
    if (p < 0) return 0;
    if (p >= a.size()) return a.back();
    return a[p];
}

struct centroid_decomposition {
    int n;
    vector<vector<pair<int, int>>> e;
    string b;
    vector<int> s;

    mint sol;

    centroid_decomposition(const vector<tuple<int, int, int>>& g) {
        int n = g.size() + 1;
        e.resize(n);
        s.resize(n);
        b = string(n, 0);
        for (auto l : g) {
            int x, y, c;
            tie(x, y, c) = l;
            e[x].emplace_back(y, c);
            e[y].emplace_back(x, c);
        }
        sol = 0;
        solve(0);
    }

    void dfs_size(int x, int p) {
        s[x] = 1;
        for (auto [y, _c] : e[x]) {
            if (y == p || b[y]) continue;
            dfs_size(y, x);
            s[x] += s[y];
        }
    }

    void dfs_centroid(int x, int p, int w, int& c) {
        bool ok = 1;
        for (auto [y, _c] : e[x]) {
            if (y == p || b[y]) continue;
            dfs_centroid(y, x, w, c);
            if (2*s[y] > w) ok = false;
        }
        if (x != p && 2*(w-s[x]) > w) ok = false;
        if (ok) c = x;
    }

    void solve(int x) {
        dfs_size(x, x);
        int c = x, szx = s[x] + 2;
        dfs_centroid(x, x, s[x], c);
        b[c] = 1;
        // Prepare for dfs
        vector<int> f0(szx), f1(szx);

        vector<pair<int, vector<pair<mint, int>>>> vv;

        for (auto [y, color] : e[c]) {
            if (b[y]) continue;

            // Gather subtree info
            vector<pair<mint, int>> v;
            dfs(y, c, mint(0), 0, color, v);

            // Process info
            vv.emplace_back(color, v);

            // Add to fw
            for (auto [suma, cost] : v) {
                (color ? f1 : f0)[cost] += 1;

                // Add to root
                if (cost <= k) {
                    sol += suma + a[c];
                }
            }
        }

        prefsum(f0);
        prefsum(f1);

        ll root_paths = 0;

        for (const auto& [color, v] : vv) {
            for (auto [suma, cost] : v) {
                int c0 = pget(f0, k - cost - (color != 0));
                int c1 = pget(f1, k - cost - (color != 1));
                sol += suma * (c0 + c1);
                root_paths += c0 + c1;
            }
        }

        // remove yourself
        for (const auto& [color, v] : vv) {
            int vs = v.size() + 2;
            vector<int> f(vs);
            for (auto [suma, cost] : v) {
                f[cost]++;
            }

            prefsum(f);

            for (auto [suma, cost] : v) {
                int cc = pget(f, k - cost);
                sol -= suma * cc;
                root_paths -= cc;
            }
        }

        sol += mint(a[c]) * (1 + root_paths / 2);

        for (auto [y, _c] : e[c]) {
            if (!b[y]) solve(y);
        }
    }

    void dfs(int x, int p, mint suma, int cost, int lastcolor, vector<pair<mint, int>>& v) {
        // Enter node
        suma += a[x];
        v.emplace_back(suma, cost);

        for (auto [y, color] : e[x]) {
            if (b[y] || y == p) continue;
            // Process and recurse
            dfs(y, x, suma, cost + (color != lastcolor), color, v);
        }
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n >> k;
    for (int i : ra(0, n)) cin >> a[i];

    vector<tuple<int, int, int>> eg(n-1);
    for (auto& [x, y, z] : eg) {
        cin >> x >> y >> z;
        x--, y--;
    }

    centroid_decomposition cd(eg);
    cout << cd.sol() << '\n';
}
// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

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

template<class F>
struct diameter_tracker {
    F f;
    int x, y, d;

    diameter_tracker(F f) : f(f), x(-1), y(-1), d(-123123123) {}

    void add(int u) {
        if (x == -1) {
            x = u;
            d = 0;
        } else if (y == -1) {
            y = u;
            d = f(x, y);
        } else {
            int dx = f(x, u);
            int dy = f(y, u);
            int mx = max({d, dx, dy});
            if (mx == dx) {
                y = u;
            } else if (mx == dy) {
                x = u;
            }
            d = mx;
        }
    }

    int get() {
        return d;
    }
};

template<class T = int>
struct minval {
    T x;
    minval(T x = numeric_limits<T>::max()) : x(x) {}
    T operator() () const { return x; }
    minval operator+ (const minval& b) const { return min(x, b.x); }
    minval& operator+= (const minval& b) { x = min(x, b.x); return *this; }
};

using mni = minval<int>;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> e(n-1);
        for (auto& [x, y] : e) {
            cin >> x >> y;
            x--, y--;
        }

        tree_topology_ex tte(e, 20);
        vector<vector<int>> atd(n+1);
        for (int i : ra(0, n)) {
            atd[tte.d[i]].push_back(i);
        }

        diameter_tracker dt([&](int x, int y) {
            return tte.distance(x, y);
        });

        vector<mni> ans(n+1);

        for (int u=n-1; u>=0; u--) {
            for (int i : atd[u+1]) {
                dt.add(i);
            }
            int g = dt.get();
            g = (g+1)/2;
            ans[clamp(u-g, 0, n)] += u;
        }

        for (int i=n-1; i>=1; i--) {
            ans[i] += ans[i+1];
        }

        for (int i : ra(1, n+1)) {
            cout << ans[i]() << " \n"[i == n];
        }
    }
}
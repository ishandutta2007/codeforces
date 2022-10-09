// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T = int>
struct max_flow {
    struct edge {
        int next, v;
        T cap, flow;
    };

    int s, t;
    vector<int> start, level, used, q;
    vector<edge> g;

    max_flow(int n, int s, int t) : s(s), t(t), start(n, -1), level(n, -1), used(n, -1), q(n) {}

    void add_edge(int u, int v, T cap, T rev = T()) {
        g.push_back({start[u], v, cap, T()});
        start[u] = g.size() - 1;
        g.push_back({start[v], u, rev, T()});
        start[v] = g.size() - 1;
    }

    bool bfs(int s, int t) {
        size_t qs = 0, qe = 1;
        fill(level.begin(), level.end(), -1);
        q[0] = s;
        level[s] = 0;
        while (qs != qe) {
            int x = q[qs++];
            for (int i = start[x]; i != -1; i = g[i].next) {
                if (g[i].flow < g[i].cap && level[g[i].v] == -1) {
                    level[g[i].v] = level[x] + 1;
                    q[qe++] = g[i].v;
                }
            }
        }
        return level[t] != -1;
    }

    T dfs(int x, int t, T f) {
        if (x == t)
            return f;
        for (int& i = used[x]; i != -1; i = g[i].next) {
            int v = g[i].v;
            if (level[v] == level[x] + 1 && g[i].flow < g[i].cap) {
                T z = dfs(v, t, min(f, g[i].cap - g[i].flow));
                if (z > 0) {
                    g[i].flow += z;
                    g[i^1].flow -= z;
                    return z;
                }
            }
        }
        return T();
    }

    T operator() () {
        T f = T();
        while (bfs(s, t)) {
            used = start;
            while (1) {
                T z = dfs(s, t, numeric_limits<T>::max());
                f += z;
                if (!z) break;
            }
        }
        return f;
    }

    vector<pair<int, int>> min_cut() {
        (*this)();
        vector<pair<int, int>> r;
        for (int x = 0; x < (int)start.size(); x++) {
            if (level[x] == -1) continue;
            for (int i = start[x]; i != -1; i = g[i].next) {
                if (level[g[i].v] == -1) {
                    r.emplace_back(x, g[i].v);
                }
            }
        }
        return r;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;

        max_flow<int> mf(2*n+2, 2*n, 2*n+1);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (a[i] == b[j] || a[i] + 1 == b[j]) {
                    mf.add_edge(i, n+j, 1);
                }
            }
            mf.add_edge(2*n, i, 1);
            mf.add_edge(i+n, 2*n+1, 1);
        }

        cout << (mf() == n ? "YES\n" : "NO\n");
    }
    
}
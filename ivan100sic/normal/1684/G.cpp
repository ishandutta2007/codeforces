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

int n, m;
int a[1005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    for (int i : ra(0, n)) {
        cin >> a[i];
    }

    max_flow e(n+2, n, n+1);
    int ft = 0;

    for (int i : ra(0, n)) {
        if (2*a[i] >= m) {
            cout << "-1\n";
            return 0;
        }

        if (3*a[i] > m) {
            // must flow
            ft += 1;
            e.add_edge(n, i, 1);
            for (int j : ra(0, n)) {
                if (a[i] % a[j] == 0 && a[i] + a[i] + a[j] <= m) {
                    e.add_edge(i, j, 1);
                }
            }
        } else {
            // can be used as a sink
            e.add_edge(i, n+1, 1);
        }
    }

    if (e() != ft) {
        cout << "-1\n";
        return 0;
    }

    vector<int> used(n);
    vector<pair<int, int>> sol;
    for (int x : ra(0, n)) {
        if (3*a[x] <= m) continue;
        for (int i = e.start[x]; i != -1; i = e.g[i].next) {
            if (e.g[i].flow == 1) {
                int y = e.g[i].v;
                used[x] = 1;
                used[y] = 1;
                sol.emplace_back(a[x] + a[x] + a[y], a[x] + a[y]);
                break;
            }
        }
    }

    for (int i : ra(0, n)) {
        if (!used[i]) {
            sol.emplace_back(3*a[i], 2*a[i]);
        }
    }

    cout << ssize(sol) << '\n';
    for (auto [x, y] : sol) {
        cout << x << ' ' << y << '\n';
    }
}
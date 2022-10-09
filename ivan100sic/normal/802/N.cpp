// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T = int>
struct min_cost_max_flow {
    constexpr static T inf() { return numeric_limits<T>::max(); };

    struct edge {
        int v, t;
        T c, w, f;
    };

    vector<vector<edge>> g;
    int n, s, t;
    T f, w;

    min_cost_max_flow(int n, int s, int t) : g(n), n(n), s(s), t(t), f(T()), w(T()) {}

    void add_edge(int u, int v, T c, T w, T f = T()) {
        edge e1 = {v, (int)g[v].size(), c, w, f};
        edge e2 = {u, (int)g[u].size(), 0, -w, -f};
        g[u].push_back(e1);
        g[v].push_back(e2);
    }

    void step(T h = inf()) {
        string l(n, 0);
        vector<T> d(n, inf());
        vector<int> p(n), q(n), pe(n);
        int qs = 0, qe = 0;
        q[qe++] = s;
        d[s] = T();
        while (qs != qe) {
            int u = q[qs++];
            if (qs == n) qs = 0;
            l[u] = 2;
            for (size_t i=0; i<g[u].size(); i++) {
                edge& e = g[u][i];
                int v = e.v;
                if (e.f < e.c && d[u] + e.w < d[v]) {
                    d[v] = d[u] + e.w;
                    if (l[v] == 0) {
                        q[qe++] = v;
                        if (qe == n) qe = 0;
                    } else if (l[v] == 2) {
                        if (--qs == -1) {
                            qs = n-1;
                        }
                        q[qs] = v;
                    }
                    l[v] = 1;
                    p[v] = u;
                    pe[v] = i;
                }
            }
        }
        if (d[t] == inf()) return;
        T a = h;
        int y = t;
        while (y != s) {
            int x = p[y];
            int i = pe[y];
            a = min(a, g[x][i].c - g[x][i].f);
            y = x;
        }
        y = t;
        while (y != s) {
            int x = p[y];
            int i = pe[y];
            int j = g[x][i].t;
            g[x][i].f += a;
            g[y][j].f -= a;
            w += g[x][i].w * a;
            y = x;
        }
        f += a;
    }

    void operator()(T l = inf()) {
        while (1) {
            T o = f;
            step(l - f);
            if (o == f) return;
        }
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, k;
    cin >> n >> k;

    const int source = 2*n;
    const int sink = 2*n+1;
    min_cost_max_flow<ll> mf(sink + 1, source, sink);

    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        mf.add_edge(source, i, 1, x);
        mf.add_edge(i, n+i, n, 0);
    }

    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        mf.add_edge(n+i, sink, 1, x);
    }

    for (int i : ra(0, n-1)) {
        mf.add_edge(n+i, n+i+1, n, 0);
    }

    mf(k);
    cout << mf.w << '\n';
}
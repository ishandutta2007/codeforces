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
        int next, v, label;
        T cap, flow;
    };

    int s, t;
    vector<int> start, level, used, q;
    vector<edge> g;

    max_flow(int n, int s, int t) : s(s), t(t), start(n, -1), level(n, -1), used(n, -1), q(n) {}

    void add_edge(int u, int v, T cap, int label = -1) {
        g.push_back({start[u], v, label, cap, T()});
        start[u] = g.size() - 1;
        g.push_back({start[v], u, label, 0, T()});
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

    string min_cut_vec() {
        (*this)();
        const int n = start.size();
        string r(n, 0);
        for (int x = 0; x < n; x++) {
            r[x] = level[x] == -1;
        }
        return r;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int a, b, m, q;
    cin >> a >> b >> m >> q;

    const int source = a+b;
    const int sink = source + 1;
    max_flow mf(sink+1, source, sink);

    for (int i : ra(0, m)) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        mf.add_edge(x, a+y, 1, i+1);
    }

    for (int i : ra(0, a)) {
        mf.add_edge(source, i, 1);
    }

    for (int i : ra(0, b)) {
        mf.add_edge(a+i, sink, 1);
    }

    auto mcv = mf.min_cut_vec();

    vector<int> cov_verts;
    for (int i : ra(0, a+b)) {
        if ((i >= a) ^ mcv[i]) {
            cov_verts.push_back(i);
        }
    }

    // find matching
    vector<int> other, matching;
    vector<ll> ssum;
    for (int x : cov_verts) {
        int j = -1;
        for (int i = mf.start[x]; i != -1; i = mf.g[i].next) {
            if (mf.g[i].flow != 0 && mf.g[i].v < a+b) {
                j = i;
                break;
            }
        }
        other.push_back(mf.g[j].v);
        matching.push_back(mf.g[j].label);
    }

    ssum.resize(matching.size());
    ssum.back() = matching.back();
    for (int i=(int)matching.size()-2; i>=0; i--) {
        ssum[i] = ssum[i+1] + matching[i];
    }

    ssum.push_back(0ll);

    int rm = 0;

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            cout << "1\n";
            int idx = cov_verts[rm++];
            if (idx >= a) {
                idx = -((idx-a)+1);
            } else {
                idx += 1;
            }

            cout << idx << '\n';
            cout << ssum[rm] << '\n' << flush;
        } else {
            cout << matching.size() - rm << '\n';
            for (int i : span(matching).subspan(rm)) {
                cout << i << ' ';
            }
            cout << '\n' << flush;
        }
    }
}
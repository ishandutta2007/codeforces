#include<bits/stdc++.h>

using namespace std;

template <class T> class flow_graph {
 public:
    struct edge {
        int to;
        T c;
        T f;
        int rev;
    };
    vector<vector<edge>> g;
    vector<int> ptr;
    vector<int> d;
    int n;
    int st, fin;
    bool modified;
    T flow;
    flow_graph(int n, int st, int fin) : n(n), st(st), fin(fin) {
        modified = true;
        assert(0 <= st && st < n && 0 <= fin && fin < n && st != fin);
        g.resize(n);
        ptr.resize(n);
        d.resize(n);
    }
    void clear() {
        modified = true;
        for (int i = 0; i < n; i++) {
            for (edge& e : g[i]) {
                e.f = 0;
            }
        }
    }
    void add(int from, int to, T forward_cap, T backward_cap) {
        modified = true;
        assert(0 <= from && from < n && 0 <= to && to < n);
        int from_size = g[from].size();
        int to_size = g[to].size();
        g[from].push_back({to, forward_cap, 0, to_size});
        g[to].push_back({from, backward_cap, 0, from_size});
    }
    bool bfs() {
        queue<int> q({st});
        fill(d.begin(), d.end(), -1);
        d[st] = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (edge& e : g[i]) {
                if (e.c > e.f && d[e.to] == -1) {
                    d[e.to] = d[i] + 1;
                    if (e.to == fin) {
                        return true;
                    }
                    q.push(e.to);
                }
            }
        }
        return false;
    }
    T dfs(int v, T w) {
        if (v == fin) {
            return w;
        }
        T r = 0;
        int j = ptr[v];
        while (j > 0) {
            j--;
            edge& e = g[v][j];
            if (e.c > e.f && d[e.to] == d[v] + 1) {
                T ww = e.c - e.f;
                if (v != st) {
                    ww = min(ww, w - r);
                }
                T t = dfs(e.to, ww);
                if (t > 0) {
                    e.f += t;
                    g[e.to][e.rev].f -= t;
                    r += t;
                    if (v != st && r >= w) {
                        return r;
                    }
                }
            }
            ptr[v]--;
        }
        return r;
    }
    T max_flow() {
        if (!modified) {
            return flow;
        }
        modified = false;
        T ans = 0;
        while (bfs()) {
            for (int i = 0; i < n; i++) {
                ptr[i] = g[i].size();
            }
            ans += dfs(st, -1);
        }
        return flow = ans;
    }
    vector<bool> min_cut() {
        max_flow();
        vector<bool> ret(n);
        for (int i = 0; i < n; i++) {
            ret[i] = (d[i] != -1);
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= -1;
    }
    vector<int> v(m), u(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i] >> u[i];
        v[i]--, u[i]--;
        a[v[i]]--;
        a[u[i]]--;
    }
    int need = 0;
    for (int i = 0; i < n; i++) {
        if (s[i]) {
            if (!(a[i] <= 0 && abs(a[i]) % 2 == 0)) {
                cout << "NO";
                return 0;
            }
            need += abs(a[i]) / 2;
        }
    }
    if (need > m) {
        cout << "NO";
        return 0;
    }
    int S = n + m + 1, F = n + m + 2;
    flow_graph<int> G(n + m + 3, S, F);
    for (int i = 0; i < n; i++) {
        if (s[i]) {
            G.add(i, F, abs(a[i]) / 2, 0);
        }
    }
    G.add(n, F, m - need, 0); 
    for (int i = 0; i < m; i++) {
        G.add(S, i + n + 1, 1, 0);
        G.add(i + n + 1, (s[v[i]] ? v[i] : n), 1, 0);
        G.add(i + n + 1, (s[u[i]] ? u[i] : n), 1, 0);
    }
    if (G.max_flow() != m) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < m; i++) {
        for (auto& e : G.g[i + n + 1]) {
            if (e.c == 1 && e.f == 1) {
                if (e.to == (s[v[i]] ? v[i] : n)) {
                    cout << u[i] + 1 << " " << v[i] + 1 << '\n';
                } else {
                    cout << v[i] + 1 << " " << u[i] + 1 << '\n';
                }
            }
        }
    }
}
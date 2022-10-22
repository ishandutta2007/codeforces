#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pii pair<int, int>

template <typename T>
class graph {
public :
    struct edge {
        int from, to;
        T cost;
    };
    int n;
    vector<edge> edges;
    vector<vector<int>> g;
    graph(int n) : n(n) {
        g.resize(n);
    }
};

template <typename T>
class forest : public graph<T> {
public :
    using graph<T>::edges;
    using graph<T>::g;
    using graph<T>::n;
    forest(int n) : graph<T>(n) {};
    int add(int from, int to, T cost = 1) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = (int) edges.size();
        g[from].push_back(id);
        g[to].push_back(id);
        edges.push_back({from, to, cost});
        return id;
    }
};

template <typename T>
class dfs_forest : public forest<T> {
public :
    using forest<T>::edges;
    using forest<T>::g;
    using forest<T>::n;
    vector<int> pv; //  
    vector<int> pe; //   
    vector<int> order; //     
    vector<int> pos; //   order
    vector<int> end; //      v  order
    vector<int> sz; //  
    vector<int> root; //    v
    vector<int> depth; //   
    vector<T> dist; //   
    dfs_forest(int n) : forest<T>(n) {};
    void init() {
        pv = vector<int> (n, -1);
        pe = vector<int> (n, -1);
        order.clear();
        pos = vector<int> (n, -1);
        end = vector<int> (n, -1);
        sz = vector<int> (n, 0);
        root = vector<int> (n, -1);
        depth = vector<int> (n, -1);
        dist = vector<T> (n);
    }
    void clear() {
        pv.clear();
        pe.clear();
        order.clear();
        pos.clear();
        end.clear();
        sz.clear();
        root.clear();
        depth.clear();
        dist.clear();
    }
private :
    void do_dfs(int v) {
        pos[v] = (int) order.size();
        order.push_back(v);
        sz[v] = 1;
        for (int id : g[v]) {
            auto &e = edges[id];
            int to = e.from ^ e.to ^ v;
            if (pos[to] != -1) continue;
            depth[to] = depth[v] + 1;
            dist[to] = dist[v] + e.cost;
            pv[to] = v;
            pe[to] = id;
            root[to] = (root[v] != -1 ? root[v] : to);
            do_dfs(to);
            sz[v] += sz[to];
        }
        end[v] = (int) order.size() - 1;
    }
    void do_dfs_from(int v) {
        depth[v] = 0;
        dist[v] = T{};
        root[v] = v;
        pv[v] = pe[v] = -1;
        do_dfs(v);
    }
public :
    void dfs(int v, bool clear_order = true) {
        if (pv.empty()) {
            init();
        }
        else {
            if (clear_order) {
                order.clear();
            }
        }
        do_dfs_from(v);
    }
    void dfs_all() {
        init();
        for (int v = 0; v < n; v++) {
            if (depth[v] == -1) {
                do_dfs_from(v);
            }
        }
        assert((int) order.size() == n);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    dfs_forest<int> g(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g.add(x - 1, y - 1);
    }
    g.dfs(0);
    pii mx = {-1, -1};
    for (int i = 0; i < n; i++) mx = max(mx, {g.dist[i] + 1, i});
    if (mx.fi >= (n + 1) / 2) {
        cout << "PATH" << '\n';
        cout << mx.fi << '\n';
        int v = mx.se;
        while (v != -1) {
            cout << v + 1 << " ";
            v = g.pv[v];
        }
        cout << '\n';
        return;
    }
    vector<vector<int>> d(n + 1);
    for (int i = 0; i < n; i++) d[g.dist[i]].push_back(i);
    cout << "PAIRING" << '\n';
    vector<pii> ans;
    for (int i = 0; i < d.size(); i++) {
        for (int j = 0; j + 1 < d[i].size(); j += 2) {
            ans.push_back({d[i][j], d[i][j + 1]});
        }
    }
    cout << ans.size() << '\n';
    for (auto &[x, y] : ans) {
        cout << x + 1 << " " << y + 1 << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}
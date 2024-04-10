#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3E5;
struct Graph {
    int m, dfsnow, cnt;
    vector<pair<int, int>> e[N];
    int dfn[N], low[N], be[N];
    stack<int> stk;
    Graph() : m(0), cnt(0), dfsnow(0) {memset(dfn, -1, sizeof(dfn));}
    void addEdge(int u, int v) {
        e[u].emplace_back(v, m);
        e[v].emplace_back(u, m);
        ++m;
    }
    void tarjan(int u, int p) {
        stk.push(u);
        dfn[u] = low[u] = dfsnow++;
        for (auto _e : e[u]) {
            int v, i;
            tie(v, i) = _e;
            if (i == p)
                continue;
            if (dfn[v] == -1) {
                tarjan(v, i);
                low[u] = min(low[u], low[v]);
            } else {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (low[u] == dfn[u]) {
            int v;
            do {
                v = stk.top();
                stk.pop();
                be[v] = cnt;
            } while (v != u);
            ++cnt;
        }
    }
};
struct Tree {
    int cnt;
    vector<int> son[N];
    int parent[N], dep[N], sz[N], top[N], root[N], in[N];
    Tree() : cnt(0) {memset(parent, -1, sizeof(parent));}
    void dfsSz(int u) {
        if (parent[u] != -1)
            son[u].erase(find(son[u].begin(), son[u].end(), parent[u]));
        sz[u] = 1;
        for (int &v : son[u]) {
            root[v] = root[u];
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfsSz(v);
            sz[u] += sz[v];
            if (sz[v] >= sz[son[u][0]])
                swap(v, son[u][0]);
        }
    }
    void dfsHLD(int u) {
        in[u] = cnt++;
        for (int v : son[u]) {
            top[v] = v == son[u][0] ? top[u] : v;
            dfsHLD(v);
        }
    }
    void init(int n) {
        for (int i = 0; i < n; ++i)
            if (parent[i] == -1) {
                dep[i] = 0;
                top[i] = root[i] = i;
                dfsSz(i);
                dfsHLD(i);
            }
    }
    int lca(int u, int v) {
        assert(root[u] == root[v]);
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) {
                v = parent[top[v]];
            } else {
                u = parent[top[u]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    Graph g;
    cin >> n >> m >> q;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        edges[i] = {u, v};
        g.addEdge(u, v);
    }
    for (int i = 0; i < n; ++i)
        if (g.dfn[i] == -1)
            g.tarjan(i, -1);
    vector<int> be(g.be, g.be + n);
    Tree t;
    for (int i = 0; i < m; ++i) {
        int u, v;
        tie(u, v) = edges[i];
        u = be[u];
        v = be[v];
        if (u != v) {
            t.son[u].push_back(v);
            t.son[v].push_back(u);
        }
    }
    t.init(g.cnt);
    for (int i = 0; i < n; ++i) {
        g.e[i].clear();
        g.dfn[i] = -1;
    }
    for (int cas = 1, r = 0; cas <= q; ++cas) {
        int cntv, cnte;
        cin >> cntv >> cnte;
        vector<int> qv(cntv);
        for (int &i : qv) {
            cin >> i;
            i = be[(i - 1 + r) % n];
        }
        edges.resize(cnte);
        auto ver = qv;
        for (int i = 0; i < cnte; ++i) {
            int u, v;
            cin >> u >> v;
            u = be[(u - 1 + r) % n];
            v = be[(v - 1 + r) % n];
            edges[i] = {u, v};
            ver.push_back(u);
            ver.push_back(v);
        }
        sort(ver.begin(), ver.end());
        ver.resize(unique(ver.begin(), ver.end()) - ver.begin());
        vector<int> s;
        int tmp = ver.size();
        for (int i = 0; i < tmp; ++i) {
            if (!s.empty()) {
                int l = t.lca(ver[i], s.back());
                while (s.size() >= 2 && t.dep[l] <= t.dep[s[s.size() - 2]]) {
                    int u = s.back();
                    s.pop_back();
                    g.addEdge(s.back(), u);
                }
                if (l != s.back()) {
                    ver.push_back(l);
                    g.addEdge(l, s.back());
                    s.back() = l;
                }
            } else {
                if (ver[i] != t.root[ver[i]]) {
                    ver.push_back(t.root[ver[i]]);
                    s.push_back(t.root[ver[i]]);
                }
                s.push_back(ver[i]);
            }
            s.push_back(ver[i]);
            if (i + 1 == tmp || t.root[ver[i]] != t.root[ver[i + 1]]) {
                while (s.size() >= 2) {
                    int u = s.back();
                    s.pop_back();
                    g.addEdge(s.back(), u);
                }
                s.pop_back();
            }
        }
        for (int i = 0; i < cnte; ++i) {
            int u, v;
            tie(u, v) = edges[i];
            g.addEdge(u, v);
        }
        for (int u : ver)
            if (g.dfn[u] == -1)
                g.tarjan(u, -1);
        bool ok = true;
        for (int i = 0; i < cntv; ++i)
            if (g.be[qv[i]] != g.be[qv[0]])
                ok = false;
        for (int u : ver) {
            g.e[u].clear();
            g.dfn[u] = -1;
        }
        if (ok) {
            r = (r + cas) % n;
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}
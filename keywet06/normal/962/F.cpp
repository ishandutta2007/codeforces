#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 5;

struct edge {
    int u, v, id;
} stk[N + N];

int n, m, dft, ptr;
int dfn[N], low[N], used[N], ui[N], vi[N];

set<int> ans, in, eg;

vector<edge> adj[N];

void dfs(int u, int p) {
    dfn[u] = low[u] = ++dft;
    for (auto e : adj[u])
        if (!dfn[e.v]) {
            stk[++ptr] = e;
            dfs(e.v, u);
            low[u] = min(low[u], low[e.v]);
        } else {
            if (!used[e.id]) {
                stk[++ptr] = e;
                low[u] = min(low[u], dfn[e.v]);
            }
        }
    if (low[u] == dfn[p]) {
        in.clear();
        eg.clear();
        while (true) {
            eg.insert(stk[ptr].id);
            if (stk[ptr--].u == p) break;
        }
    }
    for (auto v : eg) {
        in.insert(ui[v]);
        in.insert(vi[v]);
        used[v] = 1;
    }
    if (in.size() == eg.size()) {
        for (auto o : eg) ans.insert(o);
    }
}

int main() {
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        tie(ui[i], vi[i]) = tie(u, v);
        adj[u].push_back((edge){u, v, i});
        adj[v].push_back((edge){v, u, i});
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) dfs(i, 0);
    }
    cout << ans.size() << '\n';
    for (auto v : ans) cout << v << ' ';
    return 0;
}
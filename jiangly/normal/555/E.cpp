#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int MAX_N = 2E5, MAX_M = 2E5;
int n, m, q;
vector<int> e[MAX_N];
int cnte;
int to[2 * MAX_M];
bool cut[2 * MAX_M];
int dfn[MAX_N], low[MAX_N];
int u[MAX_M], v[MAX_M];
int co[MAX_N];
int cntc, cnt;
int sz[MAX_N], dep[MAX_N], parent[MAX_N], top[MAX_N], a[MAX_N], r[MAX_N];
LL ans;
void addEdge(int u, int v) {
    to[cnte] = v;
    e[u].push_back(cnte++);
    to[cnte] = u;
    e[v].push_back(cnte++);
}
void tarjan(int u, int in) {
    dfn[u] = low[u] = cnt++;
    for (int i : e[u]) {
        if (i == (in ^ 1))
            continue;
        int v = to[i];
        if (dfn[v] == -1) {
            tarjan(v, i);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
                cut[i] = cut[i ^ 1] = true;
        } else
            low[u] = min(low[u], dfn[v]);
    }
}
void bfs(int s, int c) {
    queue<int> que;
    co[s] = c;
    que.push(s);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int i : e[u]) {
            if (cut[i])
                continue;
            int v = to[i];
            if (co[v] == -1) {
                co[v] = c;
                que.push(v);
            }
        }
    }
}
void dfsSz(int u) {
    sz[u] = 1;
    if (parent[u] != -1)
        e[u].erase(find(e[u].begin(), e[u].end(), parent[u]));
    for (int &v : e[u]) {
        parent[v] = u;
        dep[v] = dep[u] + 1;
        r[v] = r[u];
        dfsSz(v);
        sz[u] += sz[v];
        if (sz[v] > sz[e[u][0]])
            swap(v, e[u][0]);
    }
}
void dfsHLD(int u) {
    for (int v : e[u]) {
        top[v] = v == e[u][0] ? top[u] : v;
        dfsHLD(v);
    }
}
int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]])
            v = parent[top[v]];
        else
            u = parent[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}
void dfs(int u) {
    for (int v : e[u]) {
        dfs(v);
        a[u] += a[v];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i];
        addEdge(--u[i], --v[i]);
    }
    fill(dfn, dfn + n, -1);
    for (int i = 0; i < n; ++i)
        if (dfn[i] == -1)
            tarjan(i, -1);
    fill(co, co + n, -1);
    for (int i = 0; i < n; ++i)
        if (co[i] == -1)
            bfs(i, cntc++);
    for (int i = 0; i < n; ++i)
        e[i].clear();
    for (int i = 0; i < m; ++i) {
        u[i] = co[u[i]];
        v[i] = co[v[i]];
        if (u[i] != v[i]) {
            e[u[i]].push_back(v[i]);
            e[v[i]].push_back(u[i]);
        }
    }
    for (int i = 0; i < cntc; ++i)
        if (sz[i] == 0) {
            r[i] = i;
            parent[i] = -1;
            dfsSz(i);
            top[i] = i;
            dfsHLD(i);
        }
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        u = co[--u];
        v = co[--v];
        if (r[u] != r[v]) {
            cout << "No" << endl;
            return 0;
        }
        ++a[u];
        --a[v];
        ans += dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    for (int i = 0; i < cntc; ++i)
        if (parent[i] == -1)
            dfs(i);
    for (int i = 0; i < cntc; ++i)
        ans -= abs(a[i]);
    if (ans == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
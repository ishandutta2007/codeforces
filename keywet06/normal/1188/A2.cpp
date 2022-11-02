#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int rt;
int w[N], fa[N], dep[N], leaf[N];

vector<pair<int, int>> edge[N];
vector<tuple<int, int, int>> sol;

void add(int u, int v, int x) {
    sol.push_back({u + 1, v + 1, -x});
    while (u != v) {
        if (dep[u] > dep[v]) {
            w[u] += x;
            u = fa[u];
        } else {
            w[v] += x;
            v = fa[v];
        }
    }
}

void dfs(int u) {
    leaf[u] = -1;
    int lf = -1;
    for (auto x : edge[u]) {
        int v = x.first, l = x.second;
        if (v != fa[u]) {
            fa[v] = u;
            w[v] = l;
            dep[v] = dep[u] + 1;
            dfs(v);
            if (leaf[u] == -1) {
                leaf[u] = leaf[v];
            } else {
                lf = leaf[v];
            }
        }
    }
    if (w[u] == 0) {
        if (edge[u].size() == 1) leaf[u] = u;
        return;
    }
    if (edge[u].size() == 1) {
        add(u, rt, -w[u]);
        leaf[u] = u;
    } else if (lf != -1) {
        int x = w[u];
        add(leaf[u], rt, -x / 2);
        add(lf, rt, -x / 2);
        add(leaf[u], lf, x / 2);
    } else {
        cout << "NO" << endl;
        exit(0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w, --u, --v;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    while (edge[rt].size() != 1) ++rt;
    fa[rt] = -1;
    dfs(rt);
    cout << "YES" << endl;
    cout << sol.size() << endl;
    for (auto i : sol) {
        cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

const int maxn = 1e5 + 10;

int n, m, h;
vector<int> graph[maxn];
vector<int> gr[maxn];
int u[maxn];

char used[maxn];
vector<int> order;

void dfs1(int v) {
    if (used[v]) return;
    used[v] = true;
    for (auto to: graph[v]) {
        dfs1(to);
    }
    order.push_back(v);
}

int comp[maxn];
int cnt[maxn];
char bad[maxn];

void dfs2(int v, int root) {
    if (comp[v]) return;
    comp[v] = root;
    ++cnt[root];
    for (auto to: gr[v]) {
        dfs2(to, root);
    }
}

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> h;
    for (int i = 1; i <= n; ++i) {
        cin >> u[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if ((u[a] + 1) % h == u[b]) {
            graph[a].push_back(b);
            gr[b].push_back(a);
        }
        if ((u[b] + 1) % h == u[a]) {
            graph[b].push_back(a);
            gr[a].push_back(b);
        }
    }

    for (int v = 1; v <= n; ++v) {
        dfs1(v);
    }
    reverse(order.begin(), order.end());
    for (auto v: order) {
        if (!comp[v]) {
            dfs2(v, v);
        }
    }
    for (int v = 1; v <= n; ++v) {
        for (auto to: graph[v]) {
            if (comp[v] != comp[to]) {
                bad[comp[v]] = true;
            }
        }
    }
    int best = n + 1;
    int root = -1;
    for (int v = 1; v <= n; ++v) {
        if (v != comp[v]) continue;
        if (bad[v]) continue;
        if (cnt[v] < best) {
            best = cnt[v];
            root = v;
        }
    }
    cout << best << '\n';
    for (int i = 1; i <= n; ++i) {
        if (comp[i] == root) cout << i << ' ';
    }
}
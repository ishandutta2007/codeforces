#include <bits/stdc++.h>

using namespace std;

const int N = 3000;

int n, m;
int a[N], sz[N];

vector<int> e[2 * N];

pair<int, long long> f[N][N], g[N];

void dfs(int u, int p) {
    for (int i = 0; i < m; ++i) f[u][i] = {-1E9, -1E18};
    f[u][0] = {0, a[u]};
    sz[u] = 1;
    for (int v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int i = 0; i < min(m, sz[u] + sz[v]); ++i) g[i] = {-1E9, -1E18};
        for (int i = min(m, sz[u]) - 1; i >= 0; --i) {
            for (int j = min(m - i, sz[v]) - 1; j >= 0; --j) {
                int c = f[u][i].first;
                long long w = f[u][i].second;
                g[i + j] = max(
                    g[i + j], make_pair(c + f[v][j].first, w + f[v][j].second));
                if (i + j + 1 < m)
                    g[i + j + 1] = max(
                        g[i + j + 1],
                        make_pair(c + f[v][j].first + (f[v][j].second > 0), w));
            }
        }
        sz[u] += sz[v];
        for (int i = 0; i < min(m, sz[u]); ++i) f[u][i] = g[i];
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = x - a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(0, -1);
    cout << f[0][m - 1].first + (f[0][m - 1].second > 0) << "\n";
    for (int i = 0; i < 2 * n; ++i) e[i].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
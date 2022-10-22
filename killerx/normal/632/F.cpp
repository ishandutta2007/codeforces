#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void YES() { puts("MAGIC"); exit(0); }
void NO() { puts("NOT MAGIC"); exit(0); }

int n;
int mat[2505][2505];
vector <pair <int, pair <int, int> > > E;
vector <pair <int, int> > g[2505];
int fa[2505];
int dep[2505];
int pr[2505][15];
int mx[2505][15];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void dfs(int u, int p) {
    rep(j, 15 - 1) {
        pr[u][j + 1] = pr[pr[u][j]][j];
        mx[u][j + 1] = max(mx[u][j], mx[pr[u][j]][j]);
    }
    rep(i, g[u].size()) {
        int v = g[u][i].first;
        int w = g[u][i].second;
        if (v == p) continue;
        pr[v][0] = u;
        mx[v][0] = w;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int qry(int x, int y) {
    int ans = 0;
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 15 - 1; ~i; -- i)
        if ((dep[y] - dep[x]) >> i & 1) {
            ans = max(ans, mx[y][i]);
            y = pr[y][i];
        }
    if (x == y) return ans;
    for (int i = 15 - 1; ~i; -- i)
        if (pr[x][i] != pr[y][i]) {
            ans = max(ans, max(mx[x][i], mx[y][i]));
            x = pr[x][i];
            y = pr[y][i];
        }
    ans = max(ans, max(mx[x][0], mx[y][0]));
    return ans;
}

int main() {
    scanf("%d", &n);
    rep(i, n) rep(j, n) scanf("%d", &mat[i][j]);
    rep(i, n) {
        if (mat[i][i] != 0) NO();
        rep(j, i) if (mat[i][j] != mat[j][i]) NO();
    }
    rep(i, n) rep(j, i) E.pb(mp(mat[i][j], mp(i, j)));
    sort(E.begin(), E.end());
    rep(i, n) fa[i] = i;
    rep(i, E.size()) {
        int u = E[i].second.first;
        int v = E[i].second.second;
        int w = E[i].first;
        if (find(u) != find(v)) {
            fa[find(u)] = find(v);
            g[u].pb(mp(v, w));
            g[v].pb(mp(u, w));
        }
    }
    dfs(0, -1);
    rep(i, n) rep(j, i) {
        if (qry(i, j) != mat[i][j]) {
            NO();
        }
    }
    YES();
    return 0;
}
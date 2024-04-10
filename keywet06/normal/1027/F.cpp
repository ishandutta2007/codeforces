#include <bits/stdc++.h>

using namespace std;

const int N = (int)2e6 + 100;

int n, m;
int xs[N], par[N], sz[N], b[N];
int a[N][2], ed[N][2];

int getPar(int v) { return par[v] == -1 ? v : par[v] = getPar(par[v]); }

void unite(int v, int u) {
    v = getPar(v);
    u = getPar(u);
    ++b[v];
    if (v == u) return;
    if (sz[v] < sz[u]) swap(sz[v], sz[u]);
    par[u] = v;
    sz[v] += sz[u];
    b[v] += b[u];
    for (int i = 0; i < 2; ++i) {
        int t = a[u][i];
        for (int j = 0; j < 2; ++j) {
            if (a[v][j] < t) swap(a[v][j], t);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 2; ++j) {
            scanf("%d", &ed[i][j]);
            xs[m++] = ed[i][j];
        }
    sort(xs, xs + m);
    m = unique(xs, xs + m) - xs;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 2; ++j)
            ed[i][j] = lower_bound(xs, xs + m, ed[i][j]) - xs;
    for (int i = 0; i < m; ++i) {
        par[i] = -1;
        sz[i] = 1;
        a[i][0] = i;
        a[i][1] = -1;
        b[i] = 0;
    }
    for (int i = 0; i < n; ++i) unite(ed[i][0], ed[i][1]);
    int ans = -1;
    for (int v = 0; v < m; v++) {
        if (par[v] != -1) continue;
        if (b[v] > sz[v]) {
            printf("-1\n");
            return 0;
        }
        ans = max(ans, a[v][sz[v] - b[v]]);
    }
    printf("%d\n", xs[ans]);

    return 0;
}
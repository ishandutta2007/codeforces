#include <bits/stdc++.h>

using namespace std;

const int N = 10200;
const int M = N << 1;

bool u[N], w[N], del[N], e[N], wq[M];

int n, m, cnt, i, x, y, z, fi, fr, q[M], all[N], col[N];

vector<int> g[N], f[N], v[N];

set<int> cw[M];
set<int>::iterator it;

void add(int i) {
    if (!wq[i]) {
        wq[i] = true;
        q[++fr] = i;
    }
}

void dfs(int i, int p, int d, int c) {
    all[d] = i;
    col[d] = c;
    del[d] = false;
    if (u[i]) {
        if (w[i]) {
            for (int j = d; j == d || all[j] != i; --j) {
                del[j] = true;
                if (cw[col[j]].count(cnt))
                    e[cnt] = true;
                else
                    cw[col[j]].insert(cnt);
                v[cnt].push_back(col[j]);
            }
            if (e[cnt])
                for (int j = 0; j < v[cnt].size(); ++j) add(v[cnt][j]);
            ++cnt;
        }
        return;
    }
    u[i] = w[i] = true;
    for (int j = 0; j < g[i].size(); ++j) {
        int k = g[i][j];
        if (k != p) dfs(k, i, d + 1, f[i][j]);
    }
    w[i] = false;
    if (d > 0 && !del[d]) add(c);
}

int main() {
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; ++i) {
        scanf("%d%d%d", &x, &y, &z);
        g[x].push_back(y);
        f[x].push_back(z);
        g[y].push_back(x);
        f[y].push_back(z);
    }
    dfs(1, 0, 0, 0);
    while (true) {
        while (fi < fr) {
            x = q[++fi];
            for (it = cw[x].begin(); it != cw[x].end(); ++it) {
                y = *it;
                if (!e[y]) {
                    e[y] = true;
                    for (i = 0; i < v[y].size(); ++i) add(v[y][i]);
                }
            }
        }
        for (x = 0, i = 1; i <= m; ++i)
            if (!wq[i] && (x == 0 || cw[i].size() > cw[x].size())) x = i;
        if (cw[x].size() == 0) break;
        y = *cw[x].begin();
        cw[x].erase(cw[x].begin());
        e[y] = true;
        for (i = 0; i < v[y].size(); ++i)
            if (v[y][i] != x) add(v[y][i]);
    }
    printf("%d\n", fr);
    return 0;
}
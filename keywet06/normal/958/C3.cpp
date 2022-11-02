#include <bits/stdc++.h>

const int M = 103;
const int N = 2e6 + 5;
const int V = 5e5 + 5;
const int INF = 1e9 + 7;

bool vis[M][M][M];

int n, m, mo, he, ta, a[N], f[M][M][M], nxt[V][M];

struct poi {
    int x, y, z;
} opt[N];

void upd(int i, int j, int k, int ave) {
    if (ave > n) return;
    if (ave < f[i][j][k]) {
        f[i][j][k] = ave;
        if (vis[i][j][k]) {
            vis[i][j][k] = false;
            ta = (ta + 1) % N;
            opt[ta].x = i;
            opt[ta].y = j;
            opt[ta].z = k;
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &mo);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
        a[i] %= mo;
    }
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j < mo; ++j) {
            for (int k = 0; k <= m; ++k) {
                f[i][j][k] = n + 1;
                vis[i][j][k] = true;
            }
        }
    }
    for (int i = 0; i < mo; ++i) nxt[n + 1][i] = n + 1;
    for (int i = n; i; --i) {
        for (int j = 0; j < mo; ++j) nxt[i][j] = nxt[i + 1][j];
        nxt[i][a[i]] = i;
    }
    he = 0, ta = 0;
    upd(0, 0, 0, 0);
    for (; he != ta;) {
        he = (he + 1) % N;
        int x = opt[he].x, y = opt[he].y, z = opt[he].z;
        for (int i = 0; i < mo; ++i) {
            int xx, yy, zz;
            xx = x + 1;
            yy = i;
            zz = z + (yy >= y ? 0 : 1);
            upd(xx, yy, zz, nxt[f[x][y][z] + 1][i]);
        }
        vis[x][y][z] = true;
    }
    int ans = INF;
    for (int i = 0; i <= n; ++i) {
        if (f[m][a[n]][i] <= n) ans = std::min(ans, i * mo + a[n]);
    }
    printf("%d\n", ans);
    return 0;
}
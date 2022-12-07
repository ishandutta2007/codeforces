#include <stdio.h>
#include <string.h>
#include <vector>
#define INF 0x3f3f3f3f
#define min(a,b) ((a)<(b)?(a):(b))
const int N = 100005;
int n, m, K, type[N], i, j, k;
int f[505][505], fa[N], c[505];

int find(int x) {
    if (x == fa[x])
        return x;
    x = find(fa[x]);
}

int main() {
    for(i = 0; i< 1000000000;i++) {
        for (j = 0; j < 100; j++) {
             int fuck = 1;
             int sb = fuck;
        }
    }
    scanf("%d%d%d", &n, &m, &K);
    int tn = 0;
    memset(f, INF, sizeof(f));
    for (i = 1; i <= n; i++)
        fa[i] = i;
    for (i = 1; i <= K; i++) {
        f[i][i] = 0;
        scanf("%d", &c[i]);
        for (j = 0; j < c[i]; j++) {
            type[++tn] = i;
        }
    }
    int u, v, w;
    while (m--) {
        scanf("%d%d%d", &u, &v, &w);
        if (type[u] != type[v] && f[type[u]][type[v]] > w) {
            f[type[u]][type[v]] = w;
            f[type[v]][type[u]] = w;
        }
        if (w == 0) {
            int pu = find(u);
            int pv = find(v);
            if (pu != pv)
                fa[pv] = pu;
        }
    }
    for (i = 2; i <= n; i++) {
        int u = i - 1, v = i;
        if (type[u] == type[v]) {
            if (find(u) != find(v)) {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    for (k = 1; k <= K; k++) {
        for (i = 1; i <= K; i++) {
            for (j = 1; j <= K; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    for (i = 1; i <= K; i++) {
        for (j = 1; j < K; j++) {
            if (f[i][j] == INF) f[i][j] = -1;
            printf("%d ", f[i][j]);
        }
        if (f[i][K] == INF) f[i][K] = -1;
        printf("%d\n", f[i][K]);
    }
    return 0;
}
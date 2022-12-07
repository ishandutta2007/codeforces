#include <stdio.h>
#include <string.h>

const int N = 20005;

int n, m, k, vis[N][15], sum[15], s[N][15], ans[N];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        scanf("%d", &vis[i][j]);
    }
    int x, y;
    while (k--) {
    scanf("%d%d", &x, &y);
    x--; y--;
    sum[y]++;
    s[x][y]++;
    }
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        if (vis[i][j])
        ans[i] += (sum[j] - s[i][j]);
    }
    }
    for (int i = 0; i < n - 1; i++)
    printf("%d ", ans[i]);
    printf("%d\n", ans[n - 1]);
    return 0;
}
#include <stdio.h>
#include <string.h>

const int N = 100005;
int vis[N][2];
int n, x[N], y[N], i;

int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        vis[x[i]][0]++;
        vis[y[i]][1]++;
    }
    for (i = 0; i < n; i++) {
        printf("%d %d\n", (n - 1) + vis[y[i]][0], (n - 1) - vis[y[i]][0]);
    }
    return 0;
}
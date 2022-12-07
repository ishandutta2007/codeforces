#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int M = 50005;
const int N = 10;

int m, n, ti[M][N], vis[N], ans[M];

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
        scanf("%d", &ti[i][j]);
    }
    for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        vis[j] = max(vis[j - 1], vis[j]) + ti[i][j];
    }
    ans[i] = vis[n];
    }
    printf("%d", ans[1]);
    for (int i = 2; i <= m; i++)
    printf(" %d", ans[i]);
    printf("\n");
    return 0;
}
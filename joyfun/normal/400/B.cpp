#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 1005;
int n, m, i, j, vis[N];
char g[N][N];

int main() {
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%s", g[i]);
    for (i = 0; i < n; i++) {
        int G, S;
        for (j = 0; j < m; j++) {
            if (g[i][j] == 'G') G = j;
            if (g[i][j] == 'S') S = j;
        }
        if (S < G) {
            printf("-1\n");
            return 0;
        }
        int d = S - G;
        vis[d] = 1;
    }
    int ans = 0;
    for (int i = 0; i <= 1000; i++)
        if (vis[i]) ans++;
    printf("%d\n", ans);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 55;
int n, m, k, i, j;
struct G {
    int x, y;
} g[N * N];

bool cmp(G a, G b) {
    return a.x + a.y < b.x + b.y;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    int gn = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) {
            g[gn].x = i; g[gn++].y = j;
        }
    sort(g, g + gn, cmp);
    int ans = 0;
    for (i = 0; i < k; i++)
        ans += g[i].x + g[i].y - 1;
    printf("%d\n", ans);
    for (i = k - 1; i >= 0; i--) {
        for (j = 1; j <= g[i].y; j++)
            printf("(1,%d) ", j);
        for (j = 2; j <= g[i].x; j++)
            printf("(%d,%d) ", j, g[i].y);
        printf("\n");
    }
    return 0;
}
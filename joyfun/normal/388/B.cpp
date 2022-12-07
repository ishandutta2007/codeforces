#include <stdio.h>
#include <string.h>

const int N = 1005;
int k, g[N][N], i, j;

void make(int now1, int now2, int to1, int to2) {
    g[now1][to1] = g[now1][to2] = g[now2][to1] = g[now2][to2] = 1;
}

int main() {
    scanf("%d", &k);
    g[1][3] = g[3][4] = g[3][5] = 1;
    int now1 = 4, now2 = 5, to1 = 6, to2 = 7;
    while (to2 < 90) {
        make(now1, now2, to1, to2);
        now1 += 2; now2 += 2; to1 += 2; to2 += 2;
    }
    for (i = 100; i < 200; i++)
        g[i][i + 1] = 1;
    g[200][2] = 1;
    for (i = 0; i < 32; i++) {
        if (k&(1<<i)) {
            g[(i + 2) * 2][i + 100] = 1;
        }
    }
    printf("200\n");
    for (i = 1; i <= 200; i++) {
        for (j = 1; j <= 200; j++) {
            if (g[i][j] || g[j][i]) printf("Y");
            else printf("N");
        }
        printf("\n");
    }
    return 0;
}
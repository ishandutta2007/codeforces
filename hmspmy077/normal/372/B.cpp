#include <cstdio>
#include <cstring>

const int N = 40;

int n, m, q, sum[N + 1][N + 1], count[N + 1][N + 1][N + 1][N + 1];
char map[N][N + 1];

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++ i) {
        scanf("%s", map[i]);
    }
    memset(sum, 0, sizeof(sum));
    for (int i = n - 1; i >= 0; -- i) {
        for (int j = m - 1; j >= 0; -- j) {
            sum[i][j] = sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1] + (map[i][j] == '1');
        }
    }
    memset(count, 0, sizeof(count));
    for (int x1 = n - 1; x1 >= 0; -- x1) {
        for (int x2 = x1 + 1; x2 <= n; ++ x2) {
            for (int y1 = m - 1; y1 >= 0; -- y1) {
                for (int y2 = y1 + 1; y2 <= m; ++ y2) {
                    int &c = count[x1][y1][x2][y2];
                    c = 0;
                    c += count[x1 + 1][y1][x2][y2];
                    c += count[x1][y1 + 1][x2][y2];
                    c += count[x1][y1][x2 - 1][y2];
                    c += count[x1][y1][x2][y2 - 1];

                    c -= count[x1 + 1][y1 + 1][x2][y2];
                    c -= count[x1 + 1][y1][x2][y2 - 1];
                    c -= count[x1 + 1][y1][x2 - 1][y2];
                    c -= count[x1][y1 + 1][x2 - 1][y2];
                    c -= count[x1][y1 + 1][x2][y2 - 1];
                    c -= count[x1][y1][x2 - 1][y2 - 1];

                    c += count[x1 + 1][y1 + 1][x2 - 1][y2];
                    c += count[x1 + 1][y1 + 1][x2][y2 - 1];
                    c += count[x1 + 1][y1][x2 - 1][y2 - 1];
                    c += count[x1][y1 + 1][x2 - 1][y2 - 1];

                    c -= count[x1 + 1][y1 + 1][x2 - 1][y2 - 1];
                    if (sum[x1][y1] - sum[x1][y2] - sum[x2][y1] + sum[x2][y2] == 0) {
                        c ++;
                    }
                }
            }
        }
    }
    while (q --) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        a --, b --;
        printf("%d\n", count[a][b][c][d]);
    }
    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int N = 100;
const int Q = 10000;

int t[Q], r[Q], c[Q], x[Q], board[N][N];

int main()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < q; ++ i) {
        scanf("%d", t + i);
        if (t[i] == 1) {
            scanf("%d", r + i);
            r[i] --;
        } else if (t[i] == 2) {
            scanf("%d", c + i);
            c[i] --;
        } else if (t[i] == 3) {
            scanf("%d%d%d", r + i, c + i, x + i);
            r[i] --;
            c[i] --;
        }
    }
    memset(board, 0, sizeof(board));
    for (int i = q - 1; i >= 0; -- i) {
        if (t[i] == 1) {
            if (m > 1) {
                int tmp = board[r[i]][m - 1];
                for (int j = m - 2; j >= 0; -- j) {
                    board[r[i]][j + 1] = board[r[i]][j];
                }
                board[r[i]][0] = tmp;
            }
        } else if (t[i] == 2) {
            if (n > 1) {
                int tmp = board[n - 1][c[i]];
                for (int j = n - 2; j >= 0; -- j) {
                    board[j + 1][c[i]] = board[j][c[i]];
                }
                board[0][c[i]] = tmp;
            }
        } else if (t[i] == 3) {
            board[r[i]][c[i]] = x[i];
        }
    }
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            printf("%d%c", board[i][j], " \n"[j == m - 1]);
        }
    }
}
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;
const int M = 10005;
int n, m, q;

struct OP {
    int tp, r, c, x;

    void read() {
        scanf("%d", &tp);
        if (tp == 1) scanf("%d", &r);
        if (tp == 2) scanf("%d", &c);
        if (tp == 3) scanf("%d%d%d", &r, &c, &x);
    }
} op[M];

int ans[N][N];
int x[N][N], y[N][N];

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            x[i][j] = i;
            y[i][j] = j;
        }
    }
    for (int i = 0; i < q; i++) op[i].read();
    for (int i = q - 1; i >= 0; i--) {

        if (op[i].tp == 1) {
            int tmp = ans[op[i].r][m];
            for (int j = m; j > 1; j--)
                ans[op[i].r][j] = ans[op[i].r][j - 1];
            ans[op[i].r][1] = tmp;
        } else if (op[i].tp == 2) {
            int tmp = ans[n][op[i].c];
            for (int j = n; j > 1; j--)
                ans[j][op[i].c] = ans[j - 1][op[i].c];
            ans[1][op[i].c] = tmp;
        } else {
            ans[op[i].r][op[i].c] = op[i].x;
        }

    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
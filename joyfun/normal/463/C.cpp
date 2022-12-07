#include <cstdio>
#include <cstring>

const int N = 2005;

typedef long long ll;

int n;
ll g[N][N], zhu[N + N], fu[N + N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lld", &g[i][j]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            zhu[i - j + n] += g[i][j];
            fu[i + j] += g[i][j];
        }
    }
    ll b = -1, w = -1;
    int bx, by, wx, wy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll sum = zhu[i - j + n] + fu[i + j] - g[i][j];
            if ((i + j) % 2 == 0) {
                if (b < sum) {
                    b = sum;
                    bx = i + 1;
                    by = j + 1;
                }
            }
            else {
                if (w < sum) {
                    w = sum;
                    wx = i + 1;
                    wy = j + 1;
                }
            }
        }
    }
    printf("%lld\n", b + w);
    printf("%d %d %d %d\n", bx, by, wx, wy);
    return 0;
}
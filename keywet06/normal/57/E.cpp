#include <bits/stdc++.h>
using namespace std;
#define P make_pair
#define F first
#define S second
#define pi pair<int, int>
const int N = 1203, M = 1e9 + 7;
typedef long long ll;
pi q[2][1000003];
int x, y, xx, yy, b[8][2] = {{-2, -1}, {-2, 1}, {-1, 2}, {-1, -2},
                             {2, 1},   {2, -1}, {1, 2},  {1, -2}},
                  tim, cnt, i, n, j, a[2], fl, vis[N * 2][N * 2];
ll k, tmp, kk, d;
int main() {
    scanf("%I64d%d", &k, &n);
    for (i = 1; i <= n; i++) scanf("%d%d", &x, &y), vis[x + N][y + N] = 1;
    q[0][0] = P(0, 0);
    vis[N][N] = 1;
    a[0] = 1;
    tmp = min(k, 500ll);
    for (tim = 0; tim < tmp; tim++, fl ^= 1) {
        cnt += a[fl];
        d = a[fl] - a[fl ^ 1];
        a[fl ^ 1] = 0;
        for (i = 0; i < a[fl]; i++) {
            x = q[fl][i].F, y = q[fl][i].S;
            for (j = 0; j < 8; j++) {
                xx = x + b[j][0], yy = y + b[j][1];
                if (!vis[xx + N][yy + N]) {
                    q[fl ^ 1][a[fl ^ 1]++] = P(xx, yy);
                    vis[xx + N][yy + N] = 1;
                }
            }
        }
    }
    if (k > tmp) kk = (k - tmp) % M;
    printf("%I64d\n",
           (cnt + a[fl] + a[fl] * kk + kk * (kk + 1) / 2 % M * d) % M);
}
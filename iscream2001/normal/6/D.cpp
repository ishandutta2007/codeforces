#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

void file() {
    freopen("std.in", "r", stdin);
    freopen("wa.out", "w", stdout);
}

const int N = 1e6 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int n, a, b, rem, f[21][201][201], pre[21][201][201][2], hp[100];

int main() {
    n = read(); a = read(); b = read();
    for (int i = 1; i <= n; i++) hp[i] = read();
    memset(f, 0x3f, sizeof(f));
    for (int k = hp[1] / b + 1; k <= 20; k++) f[2][0][k] = k;
    for (int i = 2; i <= n - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            for (int k = 0; k <= 20; k++) {
                if (f[i][j][k] == inf) continue;
                rem = hp[i] - j * b - k * a;
                rem < 0 ? rem = 0 : rem = rem / b + 1;
                for (int l = rem; l <= 20; l++) {
                    if (l + f[i][j][k] < f[i + 1][k][l]) {
                        f[i + 1][k][l] = l + f[i][j][k];
                        pre[i + 1][k][l][0] = j;
                        pre[i + 1][k][l][1] = k;
                    }
                }
            }
        }
    }
    int x, y;
    int ans = inf, j0, k0, r0;
    for (int j = 0; j <= 20; j++) {
        for (int k = 0; k <= 20; k++) {
            if (f[n - 1][j][k] == inf) continue;
            if (k * b <= hp[n]) rem = (hp[n] - b * k) / b + 1;
            else {
                rem = hp[n] - j * b - k * a;
                if (rem < 0) rem = 0; else rem = rem / b + 1;
            }
            if (rem + f[n - 1][j][k] < ans) {
                ans = rem + f[n - 1][j][k];
                x = j; y = k; r0 = rem;
            }
        }
    }
    printf("%d\n", ans);
    while (r0--) printf("%d ", n - 1);
    for (int i = n - 1; i >= 2; i--) {
        int tx = x, ty = y;
        x = pre[i][tx][ty][0];
        y = pre[i][tx][ty][1];
        while (ty--) printf("%d ", i);
    }
    return 0;
}
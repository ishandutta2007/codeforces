#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k, ans1, ans2;
long long a[1010][1010];
long long c[1010], x, y, s, t, temp;

int main() {
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%lld", &a[i][j]);
            c[i] += a[i][j];
        }
    }
    x = (c[m - 1] - c[0]) / (m - 1);
    for (i = 1; i < m; i++) {
        if ((c[i] - c[0]) != x * i) {
            ans1 = i;
            y = c[i] - c[0] - x * i;
            break;
        }
    }
    for (i = 1; i < m - 1; i++) {
        if (i - 1 != ans1 && i != ans1 && i + 1 != ans1) {
            x = 0;
            for (j = 1; j <= n; j++) {
                x += a[i - 1][j] * a[i - 1][j] + a[i + 1][j] * a[i + 1][j] -
                     a[i][j] * a[i][j] * 2;
            }
            break;
        }
    }
    i = ans1;
    t = s = 0;
    for (j = 1; j <= n; j++) {
        s += a[i - 1][j] * a[i - 1][j] + a[i + 1][j] * a[i + 1][j];
        t += a[i][j] * a[i][j] * 2;
    }
    s -= x;
    for (j = 1; j <= n; j++) {
        temp = t - a[i][j] * a[i][j] * 2 + (a[i][j] - y) * (a[i][j] - y) * 2;
        if (temp == s) {
            ans2 = a[i][j] - y;
            break;
        }
    }
    cout << ans1 << ' ' << ans2 << endl;
}
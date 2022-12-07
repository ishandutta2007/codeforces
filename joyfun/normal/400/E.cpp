#include <stdio.h>
#include <string.h>

const int N = 100005;
const int M = 20;
int n, m, i, j, b;
int a[N][M];
__int64 sum, mi[32];

int main() {
    mi[0] = 1;
    for (i = 1; i < 32; i++)
        mi[i] = mi[i - 1] * 2;
    sum = 0;
    scanf("%d%d", &n, &m);
    int num;
    for (i = 1; i <= n; i++) {
        scanf("%d", &num);
        for (b = 0; b <= 18; b++) {
            if (num&mi[b]) {
                a[i][b] = 1;
            }
        }
    }
    __int64 k = 0;
    for (b = 0; b <= 18; b++) {
        for (i = 1; i <= n; i++) {
            if (a[i][b]) k++;
            else {
                sum += mi[b] * k * (k + 1) / 2;
                k = 0;
            }
        }
        if (k != 0) {
            sum += mi[b] * k * (k + 1) / 2;
                k = 0;
        }
    }
    int p;
    __int64 v;
    while (m--) {
        scanf("%d%I64d", &p, &v);
        __int64 ans1 = 0, ans2 = 0;
        for (b = 0; b <= 18; b++) {
            if (a[p][b]) sum -= mi[b];
            if (a[p][b] && (v&mi[b]) == 0) {
                __int64 l = p, r = p;
                while (a[l - 1][b]) {
                    l--;
                }
                while (a[r + 1][b]) {
                    r++;
                }
                ans1 += mi[b] * ((p - l) * (r - p) + (p - l) + (r - p));
                a[p][b] = 0;
            }
            else if ((v&mi[b]) && a[p][b] == 0) {
                int l = p, r = p;
                while (a[l - 1][b]) {
                    l--;
                }
                while (a[r + 1][b]) {
                    r++;
                }
                ans2 += mi[b] * ((p - l) * (r - p) + (p - l) + (r - p));
                a[p][b] = 1;
            }
        }
        sum = sum - ans1 + ans2 + v;
        printf("%I64d\n", sum);
    }
    return 0;
}
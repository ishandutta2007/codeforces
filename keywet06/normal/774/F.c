#include <stdio.h>

typedef long long int64;

#define N 50005

int mi;
int a[N], t[N], m[N];

int64 n, d, r, mm;
int64 c[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) {
        if (i % 7 != 0) {
            t[i] = i, m[i] = i % 7;
        } else if (n % 7 != 0) {
            t[i] = n + i, m[i] = (n + i) % 7;
        } else {
            t[i] = m[i] = -1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (m[i] == -1) {
            c[i] = -1;
        } else if (a[i] == 1) {
            c[i] = t[i];
        } else {
            d = (a[i] - 2) / 6;
            r = (a[i] - 1) % 6;
            if (r == 0) r = 6;
            c[i] = t[i] + d * 7 * n;
            while (r > 0) {
                m[i] = (m[i] + n) % 7;
                c[i] = c[i] + n;
                r -= m[i] != 0;
            }
        }
    }
    mm = c[1], mi = 1;
    for (int i = 1; i <= n; ++i) {
        if (mm > c[i] && c[i] != -1) mm = c[i], mi = i;
    }
    printf("%d\n", mi);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 42;

int a[N];
double f[N][N], nf[N][N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            f[i][j] = (a[i] > a[j]);
        }
    }
    int segs = n * (n + 1) / 2;
    for (int step = 1; step <= k; step++) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                nf[i][j] = 0.0;
                for (int ll = 0; ll < n; ll++) {
                    for (int rr = ll; rr < n; rr++) {
                        int ni = i, nj = j;
                        if (ll <= i && i <= rr) ni = ll + rr - i;
                        if (ll <= j && j <= rr) nj = ll + rr - j;
                        if (ni < nj) {
                            nf[i][j] += f[ni][nj] / segs;
                        } else {
                            nf[i][j] += (1.0 - f[nj][ni]) / segs;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                f[i][j] = nf[i][j];
            }
        }
    }
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += f[i][j];
        }
    }
    printf("%.17f\n", ans);
    return 0;
}
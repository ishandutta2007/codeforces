#include <bits/stdc++.h>

const int N = 205;

double p[N];

double a[N][N], b[N][N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) scanf("%lf", &p[i]);
    for (int i = 0; i <= 2 * n; ++i) {
        for (int j = 0; j <= 2 * n; ++j) a[i][j] = -100;
    }
    for (int i = 0; i <= 2 * n; ++i) {
        for (int j = 0; j <= i && j <= n; ++j) a[i][n + i - j - j] = p[j];
    }
    for (int t = 0; t <= 30; ++t) {
        for (int i = 0; i <= 2 * n; ++i) {
            for (int j = 0; j <= 2 * n; ++j) b[i][j] = -100;
        }
        for (int i = 0; i <= 2 * n; ++i) {
            for (int j = 0; j <= 2 * n; ++j) {
                for (int k = 0; k <= 2 * n; ++k) {
                    double t = a[i][k] + a[k][j];
                    if (t > b[i][j]) b[i][j] = t;
                }
            }
        }
        for (int i = 0; i <= 2 * n; ++i) {
            for (int j = 0; j <= 2 * n; ++j) {
                if (b[i][j] < 0) {
                    a[i][j] = -100;
                } else {
                    a[i][j] = b[i][j] / 2;
                }
            }
        }
    }
    double res = 0.0;
    for (int i = 0; i <= 2 * n; ++i) {
        for (int j = 0; j <= 2 * n; ++j) res = std::max(a[i][j], res);
    }
    printf("%.20lf\n", res);
    return 0;
}
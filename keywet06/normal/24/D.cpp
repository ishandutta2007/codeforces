#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int M = N << 1;

int n, m, in, im;

double c[N], b[N];

double e[M][N];

int main() {
    scanf("%d %d %d %d", &n, &m, &in, &im);
    if (m == 1) {
        e[n][1] = 0.0;
        for (int i = n - 1; i >= in; --i) e[i][1] = 2 + e[i + 1][1];
        printf("%.9lf\n", e[in][1]);
        return 0;
    }
    if (im > m / 2) im = m + 1 - im;
    int g = (m + 1) / 2;
    for (int i = 1; i <= g; ++i) e[n][i] = 0.0;
    for (int r = n - 1; r >= in; --r) {
        c[1] = 1.5 + e[r + 1][1] * 0.5;
        b[1] = 0.5;
        for (int i = 2; i <= g; ++i) {
            double w = 1.0 - 0.25 - b[i - 1] * 0.25;
            c[i] = (1.0 + 0.25 * e[r + 1][i] + 0.25 * c[i - 1]) / w;
            b[i] = (0.25) / w;
        }
        if (m % 2 == 0) {
            e[r][g] = c[g] / (1.0 - b[g]);
        } else {
            e[r][g] = (c[g] + b[g] * c[g - 1]) / (1.0 - b[g] * b[g - 1]);
        }
        for (int i = g - 1; i >= 1; --i) e[r][i] = c[i] + b[i] * e[r][i + 1];
    }
    printf("%.9lf\n", e[in][im]);
    return 0;
}
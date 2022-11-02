#include <bits/stdc++.h>

const int N = 5005;

double p[N];
double prob[N][N];

int t[N];
int n, r;

int main() {
    scanf("%d%d", &n, &r);
    for (int i = 0; i < n; ++i) {
        scanf("%lf%d", &p[i], &t[i]);
        p[i] *= 0.01;
    }
    prob[0][0] = 1;
    double ans = 0, cur = 0, tmp = 0, q;
    for (int i = 1; i <= n; ++i) {
        cur = 0;
        tmp = 0;
        q = pow(1 - p[i - 1], t[i - 1] - 1);
        for (int k = 0; k <= r; ++k) {
            cur = cur * (1 - p[i - 1]) + prob[i - 1][k];
            if (k >= t[i - 1] - 1) {
                cur -= prob[i - 1][k - t[i - 1] + 1] * q;
                prob[i][k] += prob[i - 1][k - t[i - 1]] * q;
            }
            if (k >= r - t[i - 1] && k < r) {
                tmp = prob[i - 1][k + 1] + (1 - p[i - 1]) * tmp;
            }
            prob[i][k + 1] = cur * p[i - 1];
        }
        ans += tmp * (i - 1);
    }
    for (int k = 0; k <= r; ++k) ans += n * prob[n][k];
    printf("%.12lf\n", ans);
    return 0;
}
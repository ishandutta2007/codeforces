#include <bits/stdc++.h>

const double Eps = 1e-9;
const int N = 1005;

bool used[N];

double dp[N], sum[N], prob[N];
double p[N][N];

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%lf", &p[j][i]);
            p[j][i] /= 100.0;
        }
    }
    for (int i = 0; i < n; ++i) dp[i] = 1e100, prob[i] = 1.0;
    dp[n - 1] = 0;
    for (int i = 0; i < n; ++i) {
        int v = -1;
        if (i == 0) {
            v = n - 1;
        } else {
            for (int j = 0; j < n; ++j) {
                if (!used[j]) {
                    if (fabs(prob[j] - 1.0) < Eps) {
                        dp[j] = 1e100;
                    } else {
                        dp[j] = (sum[j] + prob[j]) / (1.0 - prob[j]);
                    }
                    if (v == -1 || dp[j] < dp[v]) v = j;
                }
            }
        }
        used[v] = true;
        if (dp[v] > 1e50) continue;
        for (int j = 0; j < n; ++j) {
            if (used[j]) continue;
            sum[j] += prob[j] * p[v][j] * (dp[v] + 1.0);
            prob[j] *= (1 - p[v][j]);
        }
    }
    printf("%.18lf\n", dp[0]);
    return 0;
}
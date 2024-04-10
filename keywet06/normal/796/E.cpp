#include <bits/stdc++.h>

const int B = 2;
const int C = 55;
const int N = 1005;

int ra[N], rb[N];
int dp[B][N][C][C];

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n, p, k;
    scanf("%d %d %d", &n, &p, &k);
    if (k == 0) {
        printf("0");
        return 0;
    }
    if (p > B * ((n + k - 1) / k)) p = B * ((n + k - 1) / k);
    int r;
    scanf("%d", &r);
    for (int i = 0; i < r; ++i) {
        int x;
        scanf("%d", &x);
        ra[x] = 1;
    }
    int s;
    scanf("%d", &s);
    for (int i = 0; i < s; ++i) {
        int x;
        scanf("%d", &x);
        rb[x] = 1;
    }
    for (int i = 0; i < B; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < C; ++k) {
                for (int p = 0; p < C; ++p) dp[i][j][k][p] = -1e9;
            }
        }
    }
    dp[0][0][0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        int cur = i & 1, prev = !cur;
        for (int j = 1; j <= p; ++j) {
            dp[cur][j][k - 1][0] =
                max(dp[cur][j][k - 1][0], dp[prev][j - 1][0][0] + ra[i]);
        }
        for (int j = 1; j <= p; ++j) {
            for (int a = 0; a < k - 1; ++a) {
                dp[cur][j][a][0] =
                    max(dp[cur][j][a][0], dp[prev][j][a + 1][0] + ra[i]);
            }
        }
        for (int j = 1; j <= p; ++j) {
            dp[cur][j][0][k - 1] =
                max(dp[cur][j][0][k - 1], dp[prev][j - 1][0][0] + rb[i]);
        }
        for (int j = 1; j <= p; ++j) {
            for (int b = 0; b < k - 1; ++b) {
                dp[cur][j][0][b] =
                    max(dp[cur][j][0][b], dp[prev][j][0][b + 1] + rb[i]);
            }
        }
        for (int j = 1; j <= p; ++j) {
            for (int a = 0; a < k - 1; ++a) {
                dp[cur][j][a][k - 1] =
                    max(dp[cur][j][a][k - 1],
                        dp[prev][j - 1][a + 1][0] + (ra[i] | rb[i]));
            }
        }
        for (int j = 1; j <= p; ++j) {
            for (int b = 0; b < k - 1; ++b) {
                dp[cur][j][k - 1][b] =
                    max(dp[cur][j][k - 1][b],
                        dp[prev][j - 1][0][b + 1] + (ra[i] | rb[i]));
            }
        }
        for (int j = B; j <= p; ++j) {
            for (int a = 0; a < k - 1; ++a) {
                for (int b = 0; b < k - 1; ++b) {
                    dp[cur][j][a][b] =
                        max(dp[cur][j][a][b],
                            dp[prev][j][a + 1][b + 1] + (ra[i] | rb[i]));
                }
            }
        }
        for (int j = 0; j <= p; ++j) {
            dp[cur][j][0][0] = max(dp[cur][j][0][0], dp[prev][j][0][0]);
        }
        for (int j = 0; j <= p; ++j) {
            for (int a = 0; a < k; ++a) {
                for (int b = 0; b < k; ++b) dp[prev][j][a][b] = -1e9;
            }
        }
    }
    int res = -1e9;
    for (int i = 0; i <= p; ++i) {
        for (int j = 0; j < k; ++j) {
            for (int a = 0; a < k; ++a) res = max(res, dp[n & 1][i][j][a]);
        }
    }
    printf("%d\n", res);
    return 0;
}
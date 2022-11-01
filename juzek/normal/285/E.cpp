#include <cstdio>
#include <algorithm>

const int mod = 1000000007;

long long dp[1007][1007][4];
long long s[1007];
long long wyn[1007];
long long npok[1007][1007];

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    dp[1][1][1] = 1;
    dp[1][1][3] = 1;
    for (int i = 2; i <= N; i++) {
        for (int w = 0; w < 4; w++) dp[i][1][w] = 1;

        for (int w = 2; w <= N; w++) {
            dp[i][w][2] = (s[w - 1] - dp[i - 2][w - 1][1] + dp[i - 1][w - 1][2] + mod) % mod;
            dp[i][w][0] = (dp[i][w][2] + dp[i - 1][w - 1][3]) % mod;
            dp[i][w][3] = (s[w - 1] + dp[i - 1][w - 1][0]) % mod;
            dp[i][w][1] = (dp[i][w][3] + dp[i - 1][w - 1][1]) % mod;
            s[w - 1] += dp[i - 1][w - 1][0] + dp[i - 1][w - 1][1];
            s[w - 1] %= mod;
        }
    }
    npok[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        npok[i][0] = 1;
        for (int w = 1; w <= N; w++)
            npok[i][w] = (npok[i - 1][w - 1] + npok[i - 1][w]) % mod;
    }
    int q = 1;
    long long silnia = 1;
    dp[N][0][0] = 1;
    for (int i = N; i >= K; i--) {
        wyn[i] = (dp[N][i][0] + s[i]) * silnia;
        wyn[i] %= mod;
        for (int w = i + 1; w <= N; w++) {
            wyn[i] -= (wyn[w] * npok[w][i]) % mod - mod;
            wyn[i] %= mod;
        }
        silnia *= q++;
        silnia %= mod;
    }
    printf("%I64d", wyn[K]);
    return 0;
}
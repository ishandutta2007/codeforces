#include <stdio.h>
#include <string.h>

const int MOD = 1000000007;
const int N = 2005;
const int M = 8050;
int n, k, num[N], dp[N][M][2], vis[N][M][2];

int solve(int len, int s, int flag) {
    if (s>=(1<<k)) flag = 1;
    if (vis[len][s][flag])
        return dp[len][s][flag];
    vis[len][s][flag] = 1;
    dp[len][s][flag] = 0;
    if (len == n) {
        return dp[len][s][flag] = flag;
    }
    if (num[len] == 0) {
        dp[len][s][flag] = (dp[len][s][flag] + solve(len + 1, s + 2, flag)) % MOD;
        if ((s&(1<<1)) == 0) {
            dp[len][s][flag] = (dp[len][s][flag] + solve(len + 1, s + 4, flag)) % MOD;
        }
        else {
            dp[len][s][flag] = (dp[len][s][flag] + solve(len + 1, 4, flag)) % MOD;
        }
    }
    else {
        if (num[len] == 2)
            dp[len][s][flag] = (dp[len][s][flag] + solve(len + 1, s + num[len], flag)) % MOD;
        else {
            if ((s&(1<<1)) == 0) {
                dp[len][s][flag] = (dp[len][s][flag] + solve(len + 1, s + num[len], flag)) % MOD;
            }
            else {
                dp[len][s][flag] = (dp[len][s][flag] + solve(len + 1, num[len], flag)) % MOD;
            }
        }
    }
    return dp[len][s][flag];
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    printf("%d\n", solve(0, 0, 0));
    return 0;
}
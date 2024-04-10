#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 4005;
const int MOD = 1000000007;

int dp[N][N], C[N][N];

int main() {
    int n;
    scanf("%d", &n);
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + (long long)C[i - 1][j] * j % MOD) % MOD;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i][j] = (long long)dp[i - 1][j] * (j + 1) % MOD;
            if (i) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            dp[i][j] = (dp[i][j] + C[i - 1][j]) % MOD;
        }
    }
    int ans = 0;
    for (int j = 0; j < n; j++) ans = (ans + dp[n][j]) % MOD;
    printf("%d\n", ans);
    return 0;
}
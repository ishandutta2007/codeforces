#include<bits/stdc++.h>
using namespace std;
const int N = 577;
int n, m, Mod, dp[N], dp2[N], C[N][N], res[N][N], res2[N][N];
inline int GetSum(int l, int r)
{
    return ((l + r) * 1LL * (r - l + 1) / 2) % Mod;
}
int main()
{
    scanf("%d%d%d", &n, &m, &Mod);
    for (int i = C[0][0] = 1; i < N; i ++)
        for (int j = C[0][i] = C[i][i] = 1; j < i; j ++)
            C[j][i] = (C[j][i - 1] + C[j - 1][i - 1]) % Mod;
    dp[0] = 1; dp2[0] = 0;
    for (int len = 1; len <= n; len ++)
    {
        for (int i = 1; i <= len; i ++)
        {
            int sm = GetSum(1, i - 1) + GetSum(1, len - i);
            int cnt = len + 1;
            dp[len] = (dp[len] + dp[i - 1] * 1LL * cnt % Mod * dp[len - i] % Mod * C[i - 1][len - 1]) % Mod;
            dp2[len] = (dp2[len] + sm * 1LL * dp[i - 1] % Mod % Mod * dp[len - i] % Mod * C[i - 1][len - 1]) % Mod;
            dp2[len] = (dp2[len] + dp2[i - 1] * 1LL * cnt % Mod * dp[len - i] % Mod * C[i - 1][len - 1]) % Mod;
            dp2[len] = (dp2[len] + dp2[len - i] * 1LL * cnt % Mod * dp[i - 1] % Mod * C[i - 1][len - 1]) % Mod;
        }
    }

    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= m && j <= i; j ++)
        {
            res[i][j] = res[i - 1][j];
            res2[i][j] = res2[i - 1][j];
            for (int h = 1; h < j; h ++)
            {
                res[i][j] = (res[i][j] + res[i - h - 1][j - h] * 1LL * dp[h] % Mod * C[h][j]) % Mod;
                res2[i][j] = (res2[i][j] + res2[i - h - 1][j - h] * 1LL * dp[h] % Mod * C[h][j]) % Mod;
                res2[i][j] = (res2[i][j] + res[i - h - 1][j - h] * 1LL * dp2[h] % Mod * C[h][j]) % Mod;
            }
            res[i][j] = (res[i][j] + dp[j]) % Mod;
            res2[i][j] = (res2[i][j] + dp2[j]) % Mod;
        }
    return !printf("%d\n", res2[n][m]);
}
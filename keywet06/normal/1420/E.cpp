#include <bits/stdc++.h>

using namespace std;

const int N = 85;
const int S = 4e3 + 5;

int tot, n, ans;
int a[N], lv[N];
int dp[N][N][S];

void rel(int &x, int y) { x = x > y ? x : y; }

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i]) tot++, lv[tot] = i;
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 0, lim; i < n; i++) {
        lim = min(i, tot - 1);
        for (int j = 0; j <= lim; j++)
            for (int k = 0; k < S; k++)
                if (dp[i][j][k] >= 0) {
                    for (int p = i + 1; p <= n; p++)
                        rel(dp[p][j + 1][k + abs(p - lv[j + 1])],
                            dp[i][j][k] + (i - j) * (p - i - 1));
                }
    }
    int len = (n * (n - 1)) >> 1;
    for (int t = 0, now; t <= len; t++) {
        for (int i = 1; i <= n; i++)
            rel(ans, dp[i][tot][t] + (i - tot) * (n - i));
        printf("%d ", ans);
    }
    puts("");
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int C = 26;
const int N = 300005;

char a[N], b[N];

int n, m, cnt;
int ans[N], sum[N], s1[N], s2[N], f[N];
int dp[N][C];

void solve(int u, int v) {
    int i;
    for (i = 1; i <= n; ++i) s1[i] = (a[i] == 'a' + u);
    for (i = 1; i <= m; ++i) {
        s2[i] = (b[i] == 'a' + v);
        if (i > 1) {
            f[i] = f[i - 1];
            for (; f[i] && s2[f[i] + 1] != s2[i]; f[i] = f[f[i]])
                ;
            f[i] += (s2[f[i] + 1] == s2[i]);
        }
    }
    int k = 1;
    for (i = 1; i <= n; ++i) {
        for (; k && s2[k + 1] != s1[i]; k = f[k]) void();
        k += (s2[k + 1] == s1[i]);
        if (k == m) {
            dp[i - m + 1][u] = v;
            k = f[k];
        }
    }
}

int main() {
    scanf("%d%d%s%s", &n, &m, a + 1, b + 1);
    int i, j;
    memset(dp, -1, sizeof(dp));
    for (i = 0; i < C; ++i) {
        for (j = 0; j < C; ++j) solve(i, j);
        for (j = 1; j <= n; ++j) {
            sum[j] = sum[j - 1] + (a[j] == 'a' + i);
            if (j >= m && sum[j] == sum[j - m]) dp[j - m + 1][i] = -2;
        }
    }
    for (i = 1; i <= n - m + 1; ++i) {
        for (j = 0; j < C; ++j) {
            if (dp[i][j] == -1) break;
            if (dp[i][j] == -2) continue;
            if (dp[i][dp[i][j]] == -2) dp[i][dp[i][j]] = j;
            if (dp[i][dp[i][j]] != j) break;
        }
        if (j == C) ans[++cnt] = i;
    }
    printf("%d\n", cnt);
    for (i = 1; i <= cnt; ++i) printf("%d%c", ans[i], i < cnt ? ' ' : '\n');
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int dp[10005][10005], nxt[10005];
char S[10005], T[10005];

int main() {
    scanf("%s %s", S + 1, T + 1);
    int n = strlen(S + 1), m = strlen(T + 1);
    for (int i = 1; i <= n; i++) {
        if (S[i] == '.') continue;
        int sum = 1;
        for (nxt[i] = i; nxt[i] <= n && sum > 0; sum += S[++nxt[i]] == '.' ? -1 : 1);
        if (nxt[i] > n) nxt[i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 1e8;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            char s = S[i + 1], t = T[j + 1];
            if (s && t && S[i + 1] == T[j + 1]) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            if (s) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            if (s && nxt[i + 1]) dp[nxt[i + 1]][j] = min(dp[nxt[i + 1]][j], dp[i][j]);
        }
    }
    printf("%d\n", dp[n][m]);
}
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;

int n, m, k;
char S[N], T[N];
int len[N][N];
int dp[10][N][N];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", S + 1);
    scanf("%s", T + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S[i] == T[j]) len[i][j] = len[i - 1][j - 1] + 1;
        }
    }
    for (int x = 1; x <= k; x++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (S[i] == T[j]) {
                    int l = len[i][j];
                    dp[x][i][j] = max(dp[x][i][j], dp[x - 1][i - l][j - l] + l);
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i) dp[x][i][j] = max(dp[x][i][j], dp[x][i - 1][j]);
                if (j) dp[x][i][j] = max(dp[x][i][j], dp[x][i][j - 1]);
            }
        }
    }
    printf("%d\n", dp[k][n][m]);
    return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = 100005;
const int N = 2005;
const int MOD = 1000000007;

char str[M];
int dp[N][N];

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s", str + 1);
    if (n % 2) {
        printf("0\n");
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n - m; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = dp[i - 1][j + 1];
            if (j) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
       // printf("%d %d %d\n", i, j, dp[i][j]);
        }
    }
    int l = 0, r = 0, need = 0, cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (str[i] == '(') cnt--;
        else cnt++;
        need = max(need, cnt);

    }
    for (int i = 1; i <= m; i++) {
        if (str[i] == '(') l++;
        else r++;
    }
    int ans = 0;
    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j * 2 <= i; j++) {
            if (i - j * 2 < need) continue;
            int ll = l + i - j, rr = r + j;
            ll = n / 2 - ll;
            rr = n / 2 - rr;
            if (ll < 0 || rr < 0) continue;
            ans = (ans + 1LL * dp[i][i - j * 2] * dp[ll + rr][rr - ll] % MOD) % MOD;
        }
    }
    printf("%d\n", ans);
    return 0;
}
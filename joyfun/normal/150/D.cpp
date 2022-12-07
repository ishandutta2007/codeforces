#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 155;
const int INF = 0x3f3f3f3f;

int n, a[N], dp[N][N][N];
char str[N];
int f[N];

int solve(int l, int r, int c) {
    if (dp[l][r][c] != -1) return dp[l][r][c];
    int &ans = dp[l][r][c]; ans = -INF;
    if (l > r) return dp[l][r][c] = a[c];
    if (c) ans = max(ans, solve(l, r, 0) + a[c]);
    if (str[l] == str[r]) ans = max(ans, solve(l + 1, r - 1, c + 2 - (l == r)));
    for(int i = l; i < r; i++) {
        ans = max(ans, solve(l, i, c) + solve(i + 1, r, 0));
        ans = max(ans, solve(l, i, 0) + solve(i + 1, r, c));
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == -1)
            a[i] = -INF;
    }
    scanf("%s", str + 1);
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        for (int j = 1; j <= i; j++) {
            f[i] = max(f[i], f[j - 1] + solve(j, i, 0));
        }
    }
    printf("%d\n", f[n]);
    return 0;
}
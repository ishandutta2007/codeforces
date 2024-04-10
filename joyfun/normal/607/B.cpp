#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 505;
const int INF = 0x3f3f3f3f;

int n;
int str[N];
int dp[N][N];

int solve(int l, int r) {
    if (l > r) return 1;
    if (dp[l][r] != -1) return dp[l][r];
    dp[l][r] = INF;
    for (int i = l; i <= r; i++) {
        if (str[l] == str[i]) {
            int sb = solve(l + 1, i - 1);
            if (i + 1 <= r) sb += solve(i + 1, r);
            dp[l][r] = min(dp[l][r], sb);
        }
    }
    return dp[l][r];
}

int main() {
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++) scanf("%d", &str[i]);
    printf("%d\n", solve(1, n));
    return 0;
}
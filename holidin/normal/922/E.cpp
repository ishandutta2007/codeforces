#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;

long long dp[N][(int)1e4 + 2], c[N], cost[N];

int main() {
    long long i, j, n, W, B, X;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> W >> B >> X;
    for (i = 1; i <= n; ++i)
        cin >> c[i];
    for (i = 1; i <= n; ++i)
        cin >> cost[i];
    for (i = 1; i <= n + 1; ++i)
    for (j = 0; j <= 1e4; ++j)
        dp[i][j] = -1;
    dp[1][0] = W;
    for (i = 1; i <= n; ++i)
    for (j = 0; j <= 1e4; ++j)
    if (dp[i][j] != -1)
    for (long long i1 = 0; (cost[i] == 0 && i1 <= c[i]) || (cost[i] > 0 && i1 <= min(c[i], dp[i][j] / cost[i])); ++i1)
    if (j + i1 <= 1e4)
        dp[i + 1][j + i1] = max(dp[i + 1][j + i1], min(W + B * (j + i1), dp[i][j] - i1 * cost[i] + X));
    j = 1e4;
    while (dp[n + 1][j] == -1) --j;
    cout << j;
}
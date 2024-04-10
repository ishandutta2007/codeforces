#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 51;

int dp[N][N][N], cost[N][N][N][N];
bool use[N][N][N];

int f(int l, int r, int k) {
    if (l > r)
        return 0;
    if (!use[l][r][k]) {
        use[l][r][k] = 1;
        dp[l][r][k] = 0;
        for (int i = l; i <= r; ++i)
        for (int j = 0; j <= k; ++j)
            dp[l][r][k] = max(dp[l][r][k], f(l, i - 1, j) + f(i + 1, r, j) + j * j - cost[l][r][i][j]);
    }
    return dp[l][r][k];
}
int main() {
    int i, j, k, n, h, l, r, x, c;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> h >> k;
    for (i = 0; i < k; ++i) {
        cin >> l >> r >> x >> c;
        int lm = l;
        for (int l1 = 1; l1 <= l; ++l1)
        for (int r1 = r; r1 <= n; ++r1)
        for (j = l; j <= r; ++j)
        for (int h1 = x + 1; h1 <= h; ++h1)
            cost[l1][r1][j][h1] += c;
    }
    cout << f(1, n, h);
}
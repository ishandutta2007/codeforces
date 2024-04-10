#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 401;

int dp[N][N][N], a[N];

int main() {
    int i, j, q, n, l, r, f;
    long long c;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    for (i = 1; i <= n; ++i) {
        for (j = i; j <= n; ++j)
            dp[i][j][0] = a[j] - a[i];
        for (l = 1; l <= n; ++l) {
            dp[i][i][l] = 0;
            int uk = i;
            for (j = i + 1; j <= n; ++j) {
                while (uk < j && dp[i][uk][l - 1] < a[j] - a[uk])
                    ++uk;
                dp[i][j][l] = dp[i][uk][l - 1];
                if (uk > i)
                    dp[i][j][l] = min(dp[i][j][l], a[j] - a[uk - 1]);
            }
        }
    }
    long long ans = 0;
    for (i = 0; i < q; ++i) {
        cin >> l >> r >> c >> f;
        ans = max(ans, (long long)dp[l][r][f] * c);
    }
    cout << ans;
}
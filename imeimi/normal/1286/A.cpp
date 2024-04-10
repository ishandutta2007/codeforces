#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

const int inf = 1e8;
int n;
int P[101];
int dp[101][105][105][2];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    int cnt[2] = { n >> 1, n + 1 >> 1 };
    for (int i = 1; i <= n; ++i) {
        cin >> P[i];
        if (P[i]) --cnt[P[i] & 1];
    }
    int ans = 0;
    for (int i = 0; i <= n + 2; ++i) for (int j = 0; j <= n + 2; ++j) {
        dp[1][i][j][0] = dp[1][i][j][1] = inf;
    }
    if (P[1]) {
        dp[1][cnt[0]][cnt[1]][P[1] & 1] = 0;
    }
    else {
        if (cnt[0]) dp[1][cnt[0] - 1][cnt[1]][0] = 0;
        if (cnt[1]) dp[1][cnt[0]][cnt[1] - 1][1] = 0;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= n + 2; ++j) {
            for (int k = 0; k <= n + 2; ++k) {
                if (P[i]) {
                    dp[i][j][k][P[i] + 1 & 1] = inf;
                    dp[i][j][k][P[i] & 1] = min(dp[i - 1][j][k][0] + (P[i] & 1), dp[i - 1][j][k][1] + (P[i] + 1 & 1));
                }
                else {
                    dp[i][j][k][0] = min(dp[i - 1][j + 1][k][0], dp[i - 1][j + 1][k][1] + 1);
                    dp[i][j][k][1] = min(dp[i - 1][j][k + 1][0] + 1, dp[i - 1][j][k + 1][1]);
                }
            }
        }
    }
    printf("%d\n", min(dp[n][0][0][0], dp[n][0][0][1]));
    return 0;
}
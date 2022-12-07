#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    string s, t;
    cin >> s >> t;

    int dp[n + 1][m + 1][k + 1][2];

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            for(int l = 0; l <= k; ++l) {
                for(int p = 0; p < 2; ++p)
                    dp[i][j][l][p] = -1;
            }
        }
    }

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= m; ++j)
            dp[i][j][0][1] = 0;
    }

    dp[0][0][0][0] = 0;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            for(int l = 1; l <= k; ++l) {
                if(s[i - 1] == t[j - 1]) {
                    if(dp[i - 1][j - 1][l][0] != -1)
                        dp[i][j][l][0] = dp[i - 1][j - 1][l][0] + 1;
                    if(dp[i - 1][j - 1][l - 1][0] != -1)
                        dp[i][j][l][0] = max(dp[i - 1][j - 1][l - 1][0] + 1, dp[i][j][l][0]);
                    if(dp[i - 1][j - 1][l - 1][1] != -1)
                        dp[i][j][l][0] = max(dp[i - 1][j - 1][l - 1][1] + 1, dp[i][j][l][0]);
                }
                dp[i][j][l][1] = max(max(dp[i - 1][j][l][1], dp[i - 1][j][l][0]), max(dp[i][j - 1][l][1], dp[i][j - 1][l][0]));
            }
        }
    }

    int ans = max(dp[n][m][k][0], dp[n][m][k][1]);

    cout << ans;


    return 0;
}
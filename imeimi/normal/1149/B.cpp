#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long llong;

int n, q;
char in[100001];
int nxt[100002][26];
int dp[251][251][251];
int len[4];
int st[4][251];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q >> in;
    for (int i = 0; i < 26; ++i) nxt[n][i] = nxt[n + 1][i] = n;
    for (int i = n; i--; ) {
        for (int j = 0; j < 26; ++j) {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][in[i] - 'a'] = i;
    }
    dp[0][0][0] = -1;
    while (q--) {
        char c[10];
        int it;
        cin >> c >> it;
        if (c[0] == '+') {
            cin >> c;
            st[it][len[it]++] = c[0] - 'a';
            if (it == 1) {
                for (int j = 0; j <= len[2]; ++j) {
                    for (int k = 0; k <= len[3]; ++k) {
                        dp[len[1]][j][k] = n + 1;
                        //if (i > 0)
                        dp[len[1]][j][k] = min(dp[len[1]][j][k], nxt[dp[len[1] - 1][j][k] + 1][st[1][len[1] - 1]]);
                        if (j > 0)
                        dp[len[1]][j][k] = min(dp[len[1]][j][k], nxt[dp[len[1]][j - 1][k] + 1][st[2][j - 1]]);
                        if (k > 0)
                        dp[len[1]][j][k] = min(dp[len[1]][j][k], nxt[dp[len[1]][j][k - 1] + 1][st[3][k - 1]]);
                    }
                }
            }
            if (it == 2) {
                for (int i = 0; i <= len[1]; ++i) {
                    for (int k = 0; k <= len[3]; ++k) {
                        dp[i][len[2]][k] = n + 1;
                        if (i > 0)
                        dp[i][len[2]][k] = min(dp[i][len[2]][k], nxt[dp[i - 1][len[2]][k] + 1][st[1][i - 1]]);
                        //if (j > 0)
                        dp[i][len[2]][k] = min(dp[i][len[2]][k], nxt[dp[i][len[2] - 1][k] + 1][st[2][len[2] - 1]]);
                        if (k > 0)
                        dp[i][len[2]][k] = min(dp[i][len[2]][k], nxt[dp[i][len[2]][k - 1] + 1][st[3][k - 1]]);
                    }
                }
            }
            if (it == 3) {
                for (int i = 0; i <= len[1]; ++i) {
                    for (int j = 0; j <= len[2]; ++j) {
                        dp[i][j][len[3]] = n + 1;
                        if (i > 0)
                        dp[i][j][len[3]] = min(dp[i][j][len[3]], nxt[dp[i - 1][j][len[3]] + 1][st[1][i - 1]]);
                        if (j > 0)
                        dp[i][j][len[3]] = min(dp[i][j][len[3]], nxt[dp[i][j - 1][len[3]] + 1][st[2][j - 1]]);
                        //if (k > 0)
                        dp[i][j][len[3]] = min(dp[i][j][len[3]], nxt[dp[i][j][len[3] - 1] + 1][st[3][len[3] - 1]]);
                    }
                }
            }
        }
        else {
            --len[it];
        }
        printf("%s\n", dp[len[1]][len[2]][len[3]] < n ? "YES" : "NO");
    }
    return 0;
}
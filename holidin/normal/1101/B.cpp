#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 1;
const int inf = 1e9;
int dp[5][N];

int main() {
    string s;
    int i, j, l, r, q, d;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    for (i = 1; i < 5; ++i)
        dp[i][0] = -inf;
    dp[0][0] = 0;
    for (i = 0; i < s.size(); ++i) {
        for (j = 0; j < 5; ++j)
            dp[j][i + 1] = dp[j][i];
        if (s[i] == '[')
            dp[1][i + 1] = max(dp[1][i + 1], dp[0][i] + 1);
        if (s[i] == ':')
            dp[2][i + 1] = max(dp[2][i + 1], dp[1][i] + 1);
        if (s[i] == '|')
            dp[2][i + 1] = max(dp[2][i + 1], dp[2][i] + 1);
        if (s[i] == ':')
            dp[3][i + 1] = max(dp[3][i + 1], dp[2][i] + 1);
        if (s[i] == ']')
            dp[4][i + 1] = max(dp[0][i + 1], dp[3][i] + 1);
    }
    if (dp[4][s.size()] <= 0)
        cout << -1;
    else
        cout << dp[4][s.size()];
}
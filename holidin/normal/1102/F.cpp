#include <bits/stdc++.h>
using namespace std;
const int LogN = 16;
const int N = 65536;
const int inf = 1e9;

int m[LogN][N], c[LogN][LogN], dp[LogN][LogN][N], t[LogN + 1];

int main() {
    int i, j, n, k, l, h;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 0; i < n; ++i)
    for (j = 0; j < k; ++j)
        cin >> m[i][j];
    for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j) {
        c[i][j] = inf;
        for (l = 0; l < k; ++l)
            c[i][j] = min(c[i][j], abs(m[i][l] - m[j][l]));
    }
    t[0] = 1;
    for (i = 1; i <= n; ++i)
        t[i] = t[i - 1] * 2;
    for (i = 0; i < n; ++i)
        dp[i][i][t[i]] = inf;
    for (l = 1; l < t[n]; ++l) {
        for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
        if (dp[i][j][l] != 0)
            for (h = 0; h < n; ++h)
            if ((l & t[h]) == 0)
                dp[i][h][(l | t[h])] = max(dp[i][h][(l | t[h])], min(dp[i][j][l], c[j][h]));
    }
    int ans = 0;
    for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j) {
        int x = dp[i][j][t[n] - 1];
        for (l = 0; l < k - 1; ++l)
            x = min(x, abs(m[j][l] - m[i][l + 1]));
        ans = max(ans, x);
    }
    cout << ans;
}
#include <bits/stdc++.h>
#pragma GCC optimize 03
#define fi first
#define se second
using namespace std;
const int N = 5001;

long long dp[N][N], a[N], b[N], c[N], d[N], x[N];

int main() {
    int i, j, n, s, e, k;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s >> e;
    for (i = 1; i <= n; ++i)
        cin >> x[i];
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    for (i = 1; i <= n; ++i)
        cin >> b[i];
    for (i = 1; i <= n; ++i)
        cin >> c[i];
    for (i = 1; i <= n; ++i)
        cin >> d[i];
    for (i = 1; i <= n; ++i) {
        a[i] += x[i];
        b[i] -= x[i];
        c[i] += x[i];
        d[i] -= x[i];
        if (s == i) {
            a[i] = 0;
            b[i] = 0;
        }
        if (e == i) {
            c[i] = 0;
            d[i] = 0;
        }
    }
    for (i = 0; i <= n; ++i)
    for (j = 0; j <= n; ++j)
        dp[i][j] = 1e18;
    dp[0][0] = 0;
    for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j) {
        int fromleft = j, toleft = j;
        if (i >= s)
            --toleft;
        if (i >= e)
            ++toleft;
        if (fromleft == 0 && toleft == 0 && i > 0)
            continue;
        for (int l = 0; l < 2; ++l)
        for (int p = 0; p < 2; ++p)
        if (toleft >= 1 - l && fromleft >= 1 - p) {
            long long cnt = 0;
            if (l == 0)
                cnt += c[i + 1];
            else
                cnt += d[i + 1];
            if (p == 0)
                cnt += a[i + 1];
            else
                cnt += b[i + 1];
            if (s == i + 1)
                dp[i + 1][j + l] = min(dp[i][j] + cnt, dp[i + 1][j + l]);
            else if (e != i + 1)
                    dp[i + 1][j + l - 1 + p] = min(dp[i][j] + cnt, dp[i + 1][j + l - 1 + p]);
                else
                    dp[i + 1][j - 1 + p] = min(dp[i][j] + cnt, dp[i + 1][j - 1 + p]);
        }
    }
    cout << dp[n][0];
}
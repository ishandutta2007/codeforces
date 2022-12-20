#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 18;
const int MXF = 65536;
int dp[MXF][140], r[N], b[N], t[N];
char c[N];

int main() {
    int i, j, n, k, l;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    t[0] = 1;
    int ansr = 0, ansb = 0;
    for (i = 0; i < n; ++i) {
        t[i + 1] = t[i] * 2;
        cin >> c[i] >> r[i] >> b[i];
        ansr += r[i];
        ansb += b[i];
    }
    for (i = 0; i < t[n]; ++i)
    for (j = 0; j < 140; ++j)
        dp[i][j] = -1;
    dp[0][0] = 0;
    for (i = 0; i < t[n]; ++i)
    for (j = 0; j < 140; ++j)
    if (dp[i][j] >= 0) {
        int red = 0, blu = 0;
        for (int l = 0; l < n; ++l)
        if ((i & t[l]) > 0)
            if (c[l] == 'R')
                ++red;
            else
                ++blu;
        for (l = 0; l < n; ++l)
        if ((i & t[l]) == 0)
            dp[i + t[l]][j + min(r[l], red)] = max(dp[i + t[l]][j + min(r[l], red)], dp[i][j] + min(b[l], blu));
    }
    int ans = 2e9;
    for (j = 0; j < 140; ++j)
    if (dp[t[n] - 1][j] >= 0)
        ans = min(ans, n + max(ansr - j, ansb - dp[t[n] - 1][j]));
    cout << ans;
}
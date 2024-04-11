#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> c(n);
    vector<string> a(n), rev(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        rev[i] = a[i];
        reverse(rev[i].begin(), rev[i].end());
    }

    vector< vector<int> > dp(n, vector<int>(2, INF));
    dp[0][0] = 0;
    dp[0][1] = c[0];
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] >= a[i]) dp[i + 1][0] = min(dp[i + 1][0], dp[i][0]);
        if (rev[i + 1] >= a[i]) dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + c[i + 1]);
        if (a[i + 1] >= rev[i]) dp[i + 1][0] = min(dp[i + 1][0], dp[i][1]);
        if (rev[i + 1] >= rev[i]) dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + c[i + 1]);
    }

    int ans = min(dp[n - 1][0], dp[n - 1][1]);
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}
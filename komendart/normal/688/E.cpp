#include <bits/stdc++.h>

using namespace std;

const int maxn = 501;

char dp[maxn][maxn];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 0; j--) {
            for (int m = k; m >= 0; m--) {
                if (dp[j][m]) {
                    if (j + c[i] <= k) dp[j + c[i]][m] = true;
                    if (m + c[i] <= k) dp[j][m + c[i]] = true;
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i <= k; i++) {
        if (dp[i][k - i]) cnt++;
    }
    cout << cnt << '\n';
    for (int i = 0; i <= k; i++) {
        if (dp[i][k - i]) cout << i << ' ';
    }
}
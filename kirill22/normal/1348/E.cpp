#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    int dp[n + 1][k];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            for (int j2 = 0; j2 < k; j2++) {
                if (dp[i - 1][j2] == 0) continue;
                int res;
                if (j >= j2) {
                    res = j - j2;
                }
                else res = k - (j2 - j);
                if (a[i - 1].first >= res) {
                    int v = a[i - 1].first - res;
                    v %= k;
                    if (v == 0) v = k;
                    if (v + a[i - 1].second >= k) dp[i][j] = 1;
                }
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    int s = 0;
    for (auto el : a) s += el.first + el.second;
    bool f = false;
    for (int i = 0; i < k; i++) {
        if (dp[n][i] == 1) {
            if (i <= s % k) {
                f = true;
            }
        }
    }
    if (f) {
        cout << s / k;
    }
    else cout << s / k - 1;
}
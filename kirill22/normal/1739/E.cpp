#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string a, b;
    cin >> n >> a >> b;
    vector<int> dp(n), dp2(n);
    dp.back() = dp2.back() = (int) (a.back() == '1') + (int) (b.back() == '1');
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = (a[i] == '1');
        if (b[i] == '0') {
            dp[i] += dp[i + 1];
        } else {
            if (a[i + 1] != '1') {
                dp[i] += max(1 + dp2[i + 1], dp[i + 1]);
            } else {
                dp[i] += max(dp[i + 1], 1 + (int) (b[i + 1] == '1') + (i + 2 < n ? dp2[i + 2] : 0));
            }
        }
        dp2[i] = (b[i] == '1');
        if (a[i] == '0') {
            dp2[i] += dp2[i + 1];
        } else {
            if (b[i + 1] != '1') {
                dp2[i] += max(1 + dp[i + 1], dp2[i + 1]);
            } else {
                dp2[i] += max(dp2[i + 1], 1 + (int) (a[i + 1] == '1') + (i + 2 < n ? dp[i + 2] : 0));
            }
        }
        //cout << dp[i] << " " << dp2[i] << endl;
    }
    cout << dp[0];
}
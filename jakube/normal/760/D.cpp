#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> t(n + 1);
    t[0] = 0;
    for (int idx = 0; idx < n; idx++)
        cin >> t[idx + 1];

    vector<int> dp(n + 1);
    dp[0] = 0;

    for (int i = 1; i < n + 1; i++) {
        dp[i] = dp[i-1] + 20;
        int j = i;
        while (j > 0 && t[i] - t[j] + 1 <= 1440) {
            if (t[i] - t[j] + 1 <= 90) {
                dp[i] = min(dp[i], dp[j-1] + 50);
            }
            dp[i] = min(dp[i], dp[j-1] + 120);
            j--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dp[i+1] - dp[i] << '\n';
    }

    return 0;
}
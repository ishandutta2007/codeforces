#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];

    vector<vector<int>> dp(2, vector<int>(n, 0));
    dp[0][0] = 1;
    int m = 1;


    for (int i = 1; i < n; i++) {
        if (v[i] > v[i-1]) {
            dp[0][i] = dp[0][i-1] + 1;
            dp[1][i] = dp[1][i-1] + 1;
            if (i >= 2 && v[i] >= v[i-2] + 2) {
                dp[1][i] = max(dp[1][i], dp[0][i-2] + 2);
            }
        }

        else if (v[i] <= v[i-1]) {
            dp[0][i] = 1;
            dp[1][i] = 2;
            if (i >= 2 && v[i] >= v[i-2] + 2) {
                dp[1][i] = dp[0][i-2] + 2;
            }
        }

        m = max(m, max(dp[0][i], dp[1][i]));
        if (i < n-1 || dp[0][i] <= i) m = max(m, dp[0][i] + 1);
    }

    cout << m << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int idx = 0; idx < n; idx++)
        cin >> a[idx];
    vector<int> b(n);
    for (int idx = 0; idx < n; idx++)
        cin >> b[idx];
    vector<int> c(n);
    for (int idx = 0; idx < n; idx++)
        cin >> c[idx];
    
    vector<vector<int>> dp(2, vector<int>(n, 0));
    dp[0][0] = a[0];
    dp[1][0] = b[0];

    for (int i = 1; i < n; i++) {
        dp[0][i] = max(dp[0][i-1] + b[i], dp[1][i-1] + a[i]);
        dp[1][i] = max(dp[1][i-1] + b[i], dp[0][i-1] + c[i]);
    }
    
    cout << dp[0][n-1] << endl;

    return 0;
}
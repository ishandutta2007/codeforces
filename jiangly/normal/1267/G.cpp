#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    int s = accumulate(c.begin(), c.end(), 0);
    vector<vector<double>> dp(n + 1, vector<double>(s + 1));
    dp[0][0] = 1;
    for (int i = 0, t = 0; i < n; ++i) {
        for (int j = i; j >= 0; --j)
            for (int k = t; k >= 0; --k)
                dp[j + 1][k + c[i]] += dp[j][k];
        t += c[i];
    }
    double ans = 0, b = 1;
    for (int k = 1; k <= n; ++k) {
        b = b * (n - k + 1) / k;
        for (int i = 1; i <= s; ++i)
            ans += dp[k][i] / b * min(1.0 * i / k, (1.0 * n / k + 1) * x / 2);
    }
    cout << setprecision(10) << fixed << ans << endl;
    return 0;
}
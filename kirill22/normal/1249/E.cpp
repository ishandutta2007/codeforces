#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, c;
    cin >> n >> c;
    vector<int> dp(n, 1e18), a(n - 1), b(n - 1);
    dp[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    int tmp = 0, tmp2 = c;
    for (int i = 1; i < n; i++) {
        tmp += a[i - 1];
        tmp2 += b[i - 1];
        dp[i] = min(tmp, tmp2);
        tmp = min(tmp, dp[i]);
        tmp2 = min(tmp2, dp[i] + c);
    }
    for (auto c : dp) {
        cout << c << " ";
    }
}
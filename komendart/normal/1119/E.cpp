#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0LL);
    
    for (int i = 1; i <= n; ++i) {
        int t = min(dp[i - 1], a[i] / 2);
        int x = dp[i - 1] - t;
        int y = a[i] - 2 * t;
        y %= 3;
        dp[i] = x + y;
    }
    int ans = (sum - dp[n]) / 3;
    cout << ans << '\n';
}
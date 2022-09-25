#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, x;
        cin >> n >> x;
        vector<int> dp(n + 1), ans(n + 1);
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            for (int j = n; j >= 0; j -= 1)
                dp[j] = max({j ? dp[j - 1] + x + a : 0, dp[j] + a, 0});
            for (int j = 0; j <= n; j += 1) ans[j] = max(ans[j], dp[j]);
        }
        for (int f : ans) cout << f << " ";
        cout << "\n";
    }
}
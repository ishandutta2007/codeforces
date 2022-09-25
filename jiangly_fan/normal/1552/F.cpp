#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<LL> x(n + 1), y(n + 1), s(n + 1);
    vector<LL> dp(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i += 1)
        cin >> x[i] >> y[i] >> s[i];
    LL ans = (x.back() + 1) % mod;
    for (int i = 1; i <= n; i += 1) {
        int j = lower_bound(x.begin(), x.end(), y[i]) - x.begin();
        dp[i] = (x[i] + mod - y[i] + sum[i - 1] + mod - sum[j - 1]) % mod;
        sum[i] = (sum[i - 1] + dp[i]) % mod;
        if (s[i]) ans = (ans + dp[i]) % mod;
    }
    cout << ans;
    return 0;
}
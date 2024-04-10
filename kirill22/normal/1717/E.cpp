#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n);
    iota(dp.begin(), dp.end(), 0);
    for (int i = 1; i < n; i++) {
        for (int j = i * 2; j < n; j += i) {
            dp[j] -= dp[i];
        }
    }
    int ans = 0;
    for (int d = 1; d <= n; d++) {
        for (int s = 2 * d; s <= n - 1; s += d) {
            int c = n - s;
            ans = (ans + lcm(c, d) * 1ll * dp[s / d]) % mod;
        }
    }
    cout << ans;
}
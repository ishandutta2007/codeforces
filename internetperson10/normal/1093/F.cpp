#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 998244353;

vector<int> nums;
ll ct[100001][101];
ll dp[100001][102];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, len;
    cin >> n >> k >> len;
    nums.resize(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
        if(nums[i] < 0) ct[i][0]++;
        else ct[i][nums[i]]++;
        for(int j = 0; j <= k; j++) {
            ct[i][j] += ct[i-1][j];
        }
    }
    if(len == 1) {
        cout << 0 << '\n';
        return 0;
    }
    dp[0][k+1] = dp[1][k+1] = 1;
    if(nums[1] == -1) {
        for(int i = 1; i <= k; i++) dp[1][i] = 1;
        dp[1][k+1] = k;
    }
    else {
        dp[1][nums[1]] = 1;
    }
    for(int i = 2; i <= n; i++) {
        int l = 1, r = k;
        if(nums[i] > 0) {
            l = r = nums[i];
        }
        for(int j = l; j <= r; j++) {
            dp[i][j] += dp[i-1][k+1];
            if(ct[i][j] + ct[i][0] - ct[i-len][j] - ct[i-len][0] == len) {
                dp[i][j] -= dp[i-len][k+1];
                dp[i][j] += dp[i-len][j];
            }
            dp[i][j] += MOD;
            dp[i][j] %= MOD;
            dp[i][k+1] += dp[i][j];
            dp[i][k+1] %= MOD;
        }
    }
    ll ans = 0;
    for(int i = 1; i <= k; i++) {
        ans += dp[n][i];
        ans %= MOD;
    }
    cout << ans << '\n';
}
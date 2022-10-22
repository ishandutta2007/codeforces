#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<ll> nums, dp(5000, -1);

// Hahahahaha bruh this is just longest increasing subsequence

int lis(int i) {
    if(i == 0) return dp[i] = 1;
    int ans = 0;
    for(int j = 0; j < i; j++) {
        if(nums[j] <= nums[i] && dp[j] > ans) ans = dp[j];
    }
    // cout << i << ' ' << ans+1 << '\n';
    return dp[i] = ans+1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, m, n;
    int k, ans = 0;
    string s1, s2;
    bool sad = false;
    cin >> n >> m;
    nums.resize(n);
    for(int i = 0; i < n; i++) cin >> nums[i] >> s1;
    for(int i = 0; i < n; i++) ans = max(ans, lis(i));
    cout << n - ans << '\n';
}
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<ll> pref, dp;

bool check_good(int l, int r) {
    for(int i = l; i <= r; i++) {
        for(int j = i+2; j <= r; j++) {
            if(pref[i] > pref[j]) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        int x;
        cin >> x;
        for(int i = 0; i < n; i++) nums[i] -= x;
        pref.resize(n+1);
        dp.resize(n+1);
        pref[0] = 0;
        for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + nums[i-1];
        dp[n] = 0;
        for(int i = n-1; i >= 0; i--) {
            dp[i] = -1;
            for(int j = i+1; j <= min(i+4, n); j++) {
                if(!check_good(i, j)) {
                    dp[i] = j-1;
                    break;
                }
                if(j == n) {
                    dp[i] = j;
                    break;
                }
            }
            if(dp[i] == -1) {
                dp[i] = min(dp[i+1], min(dp[i+2], dp[i+3]));
            }
        }
        ll ans = 0;
        for(int i = n; i >= 0; i--) {
            if(dp[i] >= n-1) dp[i] = max(ans, dp[i]-i);
            else dp[i] = max(ans, (dp[i]-i) + dp[dp[i]+1]);
            ans = dp[i];
        }
        cout << ans << '\n';
        vector<ll>().swap(pref);
        vector<ll>().swap(dp);
    }
}
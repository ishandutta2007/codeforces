#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

set<int> ps;
set<int> primes;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 2; i <= 1000; i++) {
        bool ok = true;
        for(int p : ps) {
            if(!(i%p)) ok = false;
        }
        if(ok) {
            ps.insert(i);
            primes.insert(i);
        }
    }
    for(int i = 1001; i <= 1000000; i++) {
        bool ok = true;
        for(int p : ps) {
            if(!(i%p)) ok = false;
        }
        if(ok) {
            primes.insert(i);
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        vector<pair<int, int>> dp(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            if(nums[i] > 1) {
                if(primes.count(nums[i])) nums[i] = 2;
                else nums[i] = 0;
            }
        }
        ll ans = 0;
        for(int i = 0; i < k; i++) {
            if(nums[i] == 0) {
                dp[i] = {-1, 0};
            }
            if(nums[i] == 1) {
                dp[i] = {-1, 1};
            }
            if(nums[i] == 2) {
                dp[i] = {1, 0};
            }
        }
        for(int i = k; i < n; i++) {
            if(nums[i] == 0) {
                dp[i] = {-1, 0};
            }
            if(nums[i] == 1) {
                if(dp[i-k].first == -1) dp[i] = {-1, dp[i-k].second+1};
                else {
                    dp[i] = {dp[i-k].first+1, dp[i-k].second+1};
                }
            }
            if(nums[i] == 2) {
                dp[i] = {dp[i-k].second+1, 0};
                ans--;
            }
            if(dp[i].first > -1) ans += (dp[i].first - dp[i].second);
        }
        cout << ans << '\n';
    }
}
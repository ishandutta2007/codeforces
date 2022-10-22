#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> nums(n+1);
        for(int i = 1; i <= n; i++) {
            cin >> nums[i];
            nums[i] += nums[i-1];
        }
        if(k <= n) {
            ll ans = 0;
            for(int i = k; i <= n; i++) {
                ans = max(ans, nums[i] - nums[i-k]);
            }
            cout << ans + (k * (k - 1) / 2) << '\n';
        }
        else {
            ll ans = nums[n];
            ans += (k * (k-1) / 2);
            ans -= (((k-n) * (k-n-1)) / 2);
            cout << ans << '\n';
        }
    }
}
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            nums[i] += i;
        }
        if(n == k) {
            cout << "0\n";
            continue;
        }
        sort(nums.begin(), nums.end());
        ll tot = 0, ans = (ll)1e18 + 7;
        for(ll i = 0; i < n; i++) {
            tot += nums[i];
            if(i >= n - k - 1) ans = min(ans, tot - (i * i + i) / 2);
        }
        cout << ans << '\n';
    }
}
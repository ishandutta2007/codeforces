#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> nums(2 * n);
    vector<ll> nums2(n+1);
    ll sum = 0, extras = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        if(nums[i]) sum += nums[i];
        else extras++;
    }
    for(int i = n; i < 2 * n; i++) nums[i] = nums[i-n];
    if(abs(sum) > k * extras) {
        cout << "-1\n";
        return 0;
    }
    vector<ll> exts(extras);
    for(int i = 0; i < extras; i++) {
        ll g = (extras - 1 - i) * k;
        exts[i] = min(k, g - sum);
        sum += exts[i];
    }
    assert(sum == 0);
    for(int i = 0; i < n; i++) {
        int e = 0;
        for(int j = 0; j < n; j++) {
            nums2[j] = nums[i+j];
            if(nums2[j] == 0) {
                nums2[j] = exts[e];
                e++;
            }
            if(j) nums2[j] += nums2[j-1];
            ans = max(ans, nums2[j]);
        }
    }
    cout << ans+1 << '\n';
}
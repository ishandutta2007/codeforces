#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
ll ans=0;
vector<ll> nums, nums1, nums2;

ll rec(int i) {
    if(nums2[i] < nums1[i]) swap(nums1[i], nums2[i]);
    if(i == 1) return nums2[i] - nums1[i] + 1;
    ll x = rec(i-1);
    ans = max(ans, nums[i-1] + x);
    // cout << i << ' ' << x << ' ' << ans << '\n';
    if((nums1[i] == nums2[i]) || (i == nums.size()-1)) return 1;
    return max(nums2[i] - nums1[i] + 1, nums[i-1] - nums2[i] + nums1[i] + 1 + x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, w, x, y, z;
    ll a, b, c, d, k;
    string s1, s2;
    bool sad = false;
    cin >> t;
    while(t--) {
        ans = 0;
        cin >> n;
        nums.resize(n);
        nums1.resize(n);
        nums2.resize(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        for(int i = 0; i < n; i++) cin >> nums1[i];
        for(int i = 0; i < n; i++) cin >> nums2[i];
        nums.push_back(n);
        nums1.push_back(1);
        nums2.push_back(n);
        rec(n);
        cout << ans << '\n';
        vector<ll>().swap(nums);
        vector<ll>().swap(nums2);
        vector<ll>().swap(nums1);
    }
}
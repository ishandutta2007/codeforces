#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll BIG = 11234567890LL;

ll diffe(vector<int> nums1, vector<int> nums2) {
    vector<int> v1, v2;
    for(int i = 0; i < nums1.size(); i++) {
        if(nums1[i] == 0) v1.push_back(i);
        if(nums2[i] == 0) v2.push_back(i);
    }
    if(v1.size() != v2.size()) {
        return BIG;
    }
    ll ans = 0;
    for(int i = 0; i < v1.size(); i++) ans += abs(v1[i] - v2[i]);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n), nums2(n);
        int k = 0;
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            nums[i] %= 2;
            k += (nums[i]);
        }
        if(n%2) {
            for(int i = 0; i < n; i++) {
                if(2*k > n) nums2[i] = 1 - (i%2);
                else nums2[i] = (i%2);
            }
            ll g = diffe(nums, nums2);
            if(g == BIG) cout << "-1\n";
            else cout << diffe(nums, nums2) << '\n';
        }
        else {
            for(int i = 0; i < n; i++) {
                nums2[i] = (i%2);
            }
            ll g = diffe(nums, nums2);
            for(int i = 0; i < n; i++) {
                nums2[i] = 1 - (i%2);
            }
            g = min(g, diffe(nums, nums2));
            if(g == BIG) cout << "-1\n";
            else cout << g << '\n';
        }
    }
}
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int ans = 0;
        sort(nums.begin(), nums.end());
    while(nums.size()) {
        ans += 1;
        vector<int> nums2;
        for(int g : nums) {
            if(g % nums[0]) nums2.push_back(g);
        }
        nums = nums2;
        nums2 = vector<int>();
    }
    cout << ans << '\n';
}
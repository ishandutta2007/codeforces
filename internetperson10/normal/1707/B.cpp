#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int z = (nums[0] == 0);
    multiset<int> s;
    while(nums.size() > 3) {
        if(z > 0) z--;
        int old_n = nums.size();
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        n = nums.size();
        z += (old_n - n);
        for(int i = 1; i < n; i++) {
            s.insert(nums[i] - nums[i-1]);
        }
        if(z > 0 && (s.find(0) == s.end())) s.insert(0);
        nums.resize(s.size());
        auto it = s.begin();
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = *it;
            it++;
        }
        s.clear();
    } 
    while(z > 1) {
        z--;
        for(int i = nums.size() - 1; i > 0; i--) {
            nums[i] -= nums[i-1];
        }
        if(nums.size() == 3) {
            if(nums[1] > nums[2]) swap(nums[1], nums[2]);
        }
    }
    while(nums.size() > 1) {
        vector<int> nums2;
        for(int j = nums.size() - 1; j > 0; j--) {
            nums2.push_back(nums[j] - nums[j-1]);
        }
        sort(nums2.begin(), nums2.end());
        nums = nums2;
        vector<int>().swap(nums2);
    }
    cout << nums[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}
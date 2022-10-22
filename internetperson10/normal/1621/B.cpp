#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<pair<int, int>, int>> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i].first.first >> nums[i].first.second >> nums[i].second;
        }
        map<pair<int, int>, int> s;
        int mi = 1234567890, mii = 0, ma = -1, maa = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i].first.first < mi) {
                mi = nums[i].first.first;
                mii = nums[i].second;
            }
            if(nums[i].first.first == mi) {
                mii = min(mii, nums[i].second);
            }
            if(nums[i].first.second > ma) {
                ma = nums[i].first.second;
                maa = nums[i].second;
            }
            if(nums[i].first.second == ma) {
                maa = min(maa, nums[i].second);
            }
            if(s.find(nums[i].first) == s.end()) s[nums[i].first] = nums[i].second;
            else s[nums[i].first] = min(s[nums[i].first], nums[i].second);
            if(s.find({mi, ma}) != s.end()) cout << min(mii + maa, s[{mi, ma}]) << '\n';
            else cout << mii + maa << '\n';
        }
    }
}
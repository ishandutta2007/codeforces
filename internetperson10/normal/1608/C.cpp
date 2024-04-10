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
        vector<pair<pair<int, int>, int>>  nums(n), nums2(n);
        vector<bool> wins(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i].first.first;
            nums[i].second = nums2[i].second = i;
        }
        for(int i = 0; i < n; i++) {
            cin >> nums[i].first.second;
            tie(nums2[i].first.second, nums2[i].first.first) = nums[i].first;
        }
        sort(nums.rbegin(), nums.rend());
        sort(nums2.rbegin(), nums2.rend());
        for(int i = 0; i < n; i++) {
            swap(nums2[i].first.first, nums2[i].first.second);
        }
        set<pair<int, int>> s1, s2;
        for(int i = 0; i < n; i++) {
            s1.insert(nums[i].first);
            s2.insert(nums2[i].first);
            if(s1 == s2) {
                for(int j = 0; j <= i; j++) {
                    wins[nums[j].second] = true;
                }
                break;
            }
        }
        for(int i = 0; i < n; i++) {
            cout << wins[i];
        }
        cout << '\n';
        vector<pair<pair<int, int>, int>>().swap(nums);
        vector<pair<pair<int, int>, int>>().swap(nums2);
        vector<bool>().swap(wins);
    }
}
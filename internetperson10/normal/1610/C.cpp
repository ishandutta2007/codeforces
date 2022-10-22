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
        vector<pair<int, int>> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i].first >> nums[i].second;
        }
        int l = 1, r = n+1;
        while(l != r - 1) {
            int mid = (l + r)/2;
            int j = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i].first >= mid-j-1 && nums[i].second >= j) j++;
                if(j == mid) break;
            }
            if(j == mid) l = mid;
            else r = mid;
        }
        cout << l << '\n';
        vector<pair<int, int>>().swap(nums);
    }
}
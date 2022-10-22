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
        vector<int> nums(n-1);
        ll ans = 0, ma = 0;
        cin >> nums[0];
        for(int i = 0; i < n-2; i++) {
            cin >> nums[i];
            ma = max(ma, (ll)nums[i]);
        }
        cin >> nums[n-2];
        nums.pop_back();
        sort(nums.rbegin(), nums.rend());
        bool ok = true;
        if(ma < 2) ok = false;
        if(nums.size() == 1) {
            if(nums[0]%2) ok = false;
        }
        else {
            if(nums[1] == 0) {
                if(nums[0]%2) ok = false;
            }
        }
        if(!ok) cout << "-1\n";
        else {
            ans = 0;
            for(int i = 0; i < n-2; i++) {
                ans += (nums[i] + 1) / 2;
            }
            cout << ans << '\n';
        }
    }
}
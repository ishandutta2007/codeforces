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
        vector<int> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        nums.push_back(-1);
        bool ok = true;
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(!ok) {
                nums[i] = max(nums[i-1], nums[i+1]);
                ans++;
                ok = true;
                continue;
            }
            if(i == n-1) break;
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                ok = false;
            }
        }
        cout << ans << '\n';
        for(int i = 0; i < n; i++) cout << nums[i] << ' ';
        cout << '\n';
    }
}
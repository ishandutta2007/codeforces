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
        int ans = max(0, n-2);
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int x = 0;
                for(int k = 0; k < n; k++) {
                    if(nums[k] * (j - i) != nums[i] * (j - i) + (nums[j] - nums[i]) * (k - i)) x++;
                }
                ans = min(ans, x);
            }
        }
        cout << ans << '\n';
    }
}
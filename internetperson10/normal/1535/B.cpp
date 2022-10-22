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
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            if(nums[i]%2 == 0) nums[i] *= -1;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) nums[i] = abs(nums[i]);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(__gcd(nums[i], 2*nums[j]) > 1) ans++;
            }
        }
        cout << ans << '\n';
    }
}
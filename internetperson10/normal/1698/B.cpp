#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        for(int i = 1; i < n-1; i++) {
            if(nums[i] > nums[i-1] + nums[i+1]) ans++;
        }
        if(k == 1) cout << (n-1)/2 << '\n';
        else cout << ans << '\n';
    }
}
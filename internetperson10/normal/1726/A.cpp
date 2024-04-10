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
    int ans = nums[n-1] - nums[0];
    for(int i = 0; i < n-1; i++) {
        ans = max(ans, nums[n-1] - nums[i]);
        ans = max(ans, nums[i] - nums[i+1]);
    }
    for(int i = 1; i < n; i++) {
        ans = max(ans, nums[i] - nums[0]);
    }
    cout << ans << '\n';
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
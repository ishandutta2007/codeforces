#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0, x = 0;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        if(nums[i] == 0) x++;
    }
    for(int i = 0; i < x; i++) {
        if(nums[i] == 1) ans++;
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
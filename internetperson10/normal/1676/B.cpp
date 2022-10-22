#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    vector<int> nums(n);
    int mi = 1e9;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        mi = min(mi, nums[i]);
        ans += nums[i];
    }
    cout << ans - n * mi << '\n';
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
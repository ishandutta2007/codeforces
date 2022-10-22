#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    string s1, s2;
    cin >> s1 >> s2;
    vector<bool> nums(n);
    int ones = 0;
    for(int i = 0; i < n; i++) {
        nums[i] = ((int)s1[i] ^ (int)s2[i]);
        ones += nums[i];
    }
    if(ones%2) {
        cout << "-1\n";
        return;
    }
    if(ones == 0) {
        cout << "0\n";
        return;
    }
    nums.push_back(0);
    ll ans = (ll)(ones / 2) * y;
    int pairs = 0;
    int len = nums[0];
    for(int i = 1; i <= n; i++) {
        if(nums[i]) len++;
        else if(nums[i-1]) {
            if(len == 2) pairs++;
            else pairs--;
            len = 0;
        }
    }
    if(pairs == 1 && ones == 2) {
        ans -= y;
        ans += min(2 * y, x);
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
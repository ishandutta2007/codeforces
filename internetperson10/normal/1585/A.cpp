#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int x = 1;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        if(nums[i] == 1) {
            x++;
            if(i) {
                if(nums[i-1] == 1) x += 4;
            }
        }
        else {
            if(i) {
                if(nums[i-1] == 0) x = -999999;
            }
        }
    }
    if(x < 0) cout << -1 << '\n';
    else cout << x << '\n';
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
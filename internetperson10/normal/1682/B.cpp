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
        int ans = (1 << 30) - 1;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        for(int i = 0; i < n; i++) if(nums[i] != i) ans &= (nums[i] & i);
        cout << ans << '\n';
    }
}
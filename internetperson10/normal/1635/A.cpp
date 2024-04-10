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
        ll tot = 0;
        for(int i = 0; i < n; i++) cin >> nums[i];
        int ans = 0;
        for(int i = 0; i < n; i++) ans |= nums[i];
        cout << ans << '\n';
    }
}
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
        vector<int> nums(31);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            for(int j = 0; j < 31; j++) {
                if(!(x & (1 << j))) nums[j]++;
            }
        }
        ll ans = 0;
        for(int i = 30; i >= 0; i--) {
            if(k >= nums[i]) {
                k -= nums[i];
                ans += (1 << i);
            }
        }
        cout << ans << '\n';
    }
}
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
        for(int i= 0; i < n; i++) cin >> nums[i];
        ll ans = 0;
        for(int l = 0; l < n; l++) {
            for(int r = l; r < n; r++) {
                for(int j = l; j <= r; j++) {
                    if(nums[j] == 0) ans += 2;
                    else ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}
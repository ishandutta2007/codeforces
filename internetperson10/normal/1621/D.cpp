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
        ll ans = 0;
        vector<vector<ll>> nums;
        nums.resize(2*n);
        for(int i = 0; i < 2*n; i++) {
            nums[i].resize(2*n);
            for(int j = 0; j < 2*n; j++) {
                cin >> nums[i][j];
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans += nums[i][j];
                ans += nums[n+i][n+j];
            }
        }
        vector<int> v = {0, n-1, n, 2*n-1};
        ll x = 21234567890;
        for(int i = 0; i < 2; i++) {
            for(int j = 2; j < 4; j++) {
                x = min(x, nums[v[i]][v[j]]);
                x = min(x, nums[v[j]][v[i]]);
            }
        }
        cout << ans+x << '\n';
    }
}
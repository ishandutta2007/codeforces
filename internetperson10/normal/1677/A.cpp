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
        for(int i = 0; i < n; i++) cin >> nums[i];
        vector<vector<int>> prefa(n), prefb(n);
        for(int i = 0; i < n; i++) {
            prefa[i].resize(n+1);
            if(i) {
                for(int j = 0; j <= n; j++) {
                    prefa[i][j] = prefa[i-1][j];
                }
            }
            for(int j = nums[i]; j <= n; j++) prefa[i][j]++;
        }
        ll ans = 0;
        for(int i = 1; i < n-2; i++) {
            for(int j = i+1; j < n-1; j++) {
                ans += prefa[i-1][nums[j]-1] * (prefa[n-1][nums[i]-1] - prefa[j][nums[i]-1]);
            }
        }
        cout << ans << '\n';
    }
}
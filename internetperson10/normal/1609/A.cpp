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
        vector<ll> nums(n);
        int g = 0;
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            while(!(nums[i]%2)) {
                nums[i] /= 2;
                g++;
            }
        }
        sort(nums.begin(), nums.end());
        while(g) {
            g--;
            nums[n-1] *= 2;
        }
        ll ans = 0;
        for(int i = 0; i < n; i++) ans += nums[i];
        cout << ans << '\n';
    }
}
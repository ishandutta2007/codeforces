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
        vector<ll> nums(n+1, 0);
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            cin >> nums[i];
        }
        vector<ll> dif(n);
        for(int i = 0; i < n; i++) {
            ll x = nums[i] - nums[i+1];
            dif[i] = x;
            if(x > 0 && i > 0) dif[0] += x;
            if(i) ans += abs(x);
        }
        ans += abs(dif[0]);
        cout << ans << '\n';
    }
}
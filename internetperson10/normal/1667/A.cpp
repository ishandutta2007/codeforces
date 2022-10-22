#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    ll best = 999999999999999999LL;
    for(int i = 0; i < n; i++) {
        ll x = 0, ans = 0;
        for(int j = i-1; j >= 0; j--) {
            ll g = x / nums[j];
            g *= nums[j];
            while(g >= x) g -= nums[j];
            ans -= g / nums[j];
            x = g;
        }
        x = 0;
        for(int j = i+1; j < n; j++) {
            ll g = x / nums[j];
            g *= nums[j];
            while(g <= x) g += nums[j];
            ans += g / nums[j];
            x = g;
        }
        best = min(best, ans);
    }
    cout << best << '\n';
}
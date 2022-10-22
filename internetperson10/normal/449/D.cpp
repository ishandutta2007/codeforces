#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> nums(1048576);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums[(1 << 20) - 1 - x]++;
    }
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < (1 << 20); j++) {
            if(j & (1 << i)) {
                nums[j] += nums[j - (1 << i)];
            }
        }
    }
    reverse(nums.begin(), nums.end());
    ll g = 1, ans = 0;
    vector<ll> modpow(1048576);
    modpow[0] = 1;
    for(int i = 1; i < modpow.size(); i++) {
        modpow[i] = (modpow[i-1] * 2) % MOD;
    }
    for(int i = 0; i < nums.size(); i++) {
        int k = __builtin_popcount(i);
        if(k%2) ans -= modpow[nums[i]];
        else ans += modpow[nums[i]];
        ans += MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    vector<ll> nums(n);
    set<ll> allNums;
    vector<ll> ct(200001);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        allNums.insert(nums[i]);
    }
    for(int i = 0; i < n; i++) {
        int x = nums[i];
        bool ok = true;
        while(x%4 != 2) {
            if(x%4) x /= 2;
            else x /= 4;
            if(x == 0) break;
            if(allNums.count(x)) ok = false;
        }
        if(ok) {
            int k = 0;
            while((1LL << k) <= nums[i]) k++;
            ct[k]++;
        }
    }
    for(int i = 2; i <= 200000; i++) {
        ct[i] += (ct[i-1] + ct[i-2]) % MOD;
    }
    ll ans = 0;
    for(int i = 1; i <= p; i++) {
        ans += ct[i];
        ans %= MOD;
    }
    cout << ans << '\n';
}
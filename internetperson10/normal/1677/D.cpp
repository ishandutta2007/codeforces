#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll fact[1000001];

const ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = 1;
    for(int i = 1; i <= 1000000; i++) {
        fact[i] = (fact[i-1] * (ll)(i)) % MOD;
    }
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        bool ok = true;
        for(int i = 0; i < n-k; i++) {
            if(nums[i] > i) ok = false;
        }
        for(int i = n-k; i < n; i++) {
            if(nums[i] > 0) ok = false;
        }
        if(!ok) {
            cout << "0\n";
            continue;
        }
        ll ans = fact[k+1];
        for(int i = 1; i < n-k; i++) {
            if(nums[i] == -1) {
                ans *= (k+1 + (i));
            }
            else if(nums[i] == 0) {
                ans *= (k+1);
            }
            ans %= MOD;
        }
        cout << ans << '\n';
    }
}
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 998244353;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> nums(n);
        vector<vector<ll>> mex;
        mex.resize(2);
        mex[0].resize(n+2);
        mex[1].resize(n+2);
        mex[0][0] = 1;
        ll ans = -1;
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            if(nums[i]) {
                mex[1][nums[i]-1] += (mex[0][nums[i]-1] + mex[1][nums[i]-1]);
                mex[1][nums[i]-1] %= MOD;
            }
            mex[0][nums[i]+1] *= 2;
            mex[0][nums[i]+1] %= MOD;
            mex[1][nums[i]+1] *= 2;
            mex[1][nums[i]+1] %= MOD;
            mex[0][nums[i]+1] += mex[0][nums[i]];
            mex[0][nums[i]+1] %= MOD;
        }
        for(int i = 0; i <= n+1; i++) {
            ans += mex[0][i];
            ans += mex[1][i];
            ans %= MOD;
        }
        cout << ans << '\n';
    }
}
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll mine[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> nums(n), pref(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        if(i%2) nums[i] *= -1;
        if(i) pref[i] = pref[i-1] + nums[i];
        else pref[i] = nums[i];
    }
    for(int i = 1; i < n; i+=2) {
        for(int j = i+1; j < n; j += 2) {
            if(i == j-1) mine[i][j] = pref[j-1] - pref[i-1];
            else mine[i][j] = min(mine[i][j-2], pref[j-1] - pref[i-1]); 
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i += 2) {
        for(int j = i+1; j < n; j += 2) {
            ll g = pref[j-1] - pref[i];
            ll l = abs(nums[i]), r = abs(nums[j]);
            if(g > 0) {
                r -= g;
                r += (mine[i+1][j-1]+1);
                l += (mine[i+1][j-1]+1);
            }
            else {
                r -= max(0LL, g - mine[i+1][j-1] - 1);
                l += min(g, mine[i+1][j-1]+1);
            }
            ans += max(0LL, min(l, r));
        }
    }
    cout << ans << '\n';
}
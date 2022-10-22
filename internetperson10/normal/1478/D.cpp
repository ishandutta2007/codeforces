#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, w, x, y, z;
    ll m, n, a, b, c, d, k, ans=0;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        nums.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> a;
            nums[i] = a;
        }
        sort(nums.begin(), nums.end());
        d = nums[1] - nums[0];
        for(int i = 0; i < n-1; i++) {
            c = nums[i+1] - nums[i];
            d = __gcd(c, d);
        }
        if(((k - nums[0])%d) == 0) cout << "YES\n";
        else cout << "NO\n";
        vector<ll>().swap(nums);
    }
}
#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    int sum = x % mod, mul = 1, add = 0;
    vector<array<int, 3>> dp = {{1, x, 1}};
    for (int t = 1; t < n; t++) {
        int y;
        cin >> y;
        int psum = sum;
        mul *= -1;
        add = (sum - add + mod) % mod;
        sum = (x - 1) * 1ll * sum % mod;
        if (y > x) {
            int val = psum;
            psum = (psum - add + mod) % mod;
            psum = (psum * mul + mod) % mod;
            dp.push_back({x + 1, y, psum});
            sum = (sum + (y - x) * 1ll * val) % mod;
        }
        while (dp.back()[1] > y) {
            auto arr = dp.back();
            dp.pop_back();
            int l = arr[0], r = arr[1], x = arr[2];
            int val = (add + mul * (x % mod) + mod) % mod;
            if (l > y) {
                sum = (sum - (r - l + 1) * 1ll * val % mod + mod) % mod;
            } else {
                sum = (sum - (r - y) * 1ll * val % mod + mod) % mod;
                dp.push_back({l, y, x});
            }
        }
        x = y;
    }
    cout << sum;
}
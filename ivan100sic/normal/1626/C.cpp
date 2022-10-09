// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct elem {
    int x, y;
};

ll b2(ll x) {
    return x*(x+1) / 2;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x(n), y(n);
        for (int& t : x) cin >> t;
        for (int& t : y) cin >> t;

        vector<ll> dp(n+1, 4e18);
        dp[0] = 0;
        for (int i : ra(0, n)) {
            int shadow = 0;
            for (int j=i; j>=0; j--) {
                shadow = max(shadow, y[j] + x[i] - x[j]);
                if (j == 0 || x[i] - x[j-1] >= shadow) {
                    dp[i+1] = min(dp[i+1], b2(shadow) + dp[j]);
                }
            }
        }
        cout << dp[n] << '\n';
    }
}
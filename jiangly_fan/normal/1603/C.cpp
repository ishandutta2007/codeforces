#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        vector<pair<int, LL>> dp = {};
        int ans = 0;
        for (int p = n - 1; p >= 0; p -= 1) {
            int x = a[p];
            //cout << x << "-----------\n";
            vector<pair<int, LL>> nxt;
            LL sum = 1;
            for (int i = 0, L = 1, R; L <= x; L = R + 1) {
                int z = (x + L - 1) / L;
                R = z > 1 ? (x - 1) / (z - 1) : x;
                while (i < (int)dp.size() and dp[i].first >= (x + L - 1) / L) {
                    sum = (sum + dp[i].second) % mod;
                    i += 1;
                }
                ans = (ans + sum * (L - 1) % mod * (p + 1)) % mod;
                nxt.push_back({x / L, sum});
                sum = 0;
            }
            dp.swap(nxt);
            //for (auto [x, y] : dp) cout << x << ":" << y << " "; cout << "\n";
            //cout << ans << "\n";
        }
        cout << ans << "\n";
    }
    return 0;
}
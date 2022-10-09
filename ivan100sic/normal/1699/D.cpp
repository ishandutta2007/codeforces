// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x, x--;

        vector<string> tk(n, string(n, 0));
        for (int i : ra(0, n)) {
            vector<int> freq(n, 0);
            int hi = 0, cnt = 0;
            for (int j : ra(i, n)) {
                hi = max(hi, ++freq[a[j]]);
                cnt++;
                if (cnt % 2 == 0 && 2*hi <= cnt) {
                    tk[i][j] = 1;
                }
            }
        }

        auto can = [&](int i, int j) {
            return (j-i == 1 || tk[i+1][j-1] == 1) && (i == -1 || j == n || a[i] == a[j]);
        };

        vector<int> dp(n, -123123123);
        int sol = 0;
        for (int i : ra(0, n)) {
            // init?
            if (can(-1, i)) dp[i] = max(dp[i], 1);
            for (int j : ra(0, i)) {
                if (can(j, i)) dp[i] = max(dp[i], dp[j] + 1);
            }
            if (can(i, n)) sol = max(sol, dp[i]);
        }

        cout << sol << '\n';
    }
}
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
        string a[2];
        cin >> a[0] >> a[1];

        int l = n, r = -1;
        for (int i : ra(0, n)) {
            if (a[0][i] == '*' || a[1][i] == '*') {
                l = min(l, i);
                r = max(r, i);
            }
        }

        if (r == -1) {
            cout << "0\n";
            continue;
        }

        a[0] = a[0].substr(l, r-l+1);
        a[1] = a[1].substr(l, r-l+1);

        n = r-l+1;
        vector dp(2, vector(n, 0));
        dp[0][0] = a[1][0] == '*';
        dp[1][0] = a[0][0] == '*';

        for (int i : ra(1, n)) {
            dp[0][i] = min(
                dp[0][i-1] + 1 + (a[1][i] == '*'),
                dp[1][i-1] + 2
            );

            dp[1][i] = min(
                dp[1][i-1] + 1 + (a[0][i] == '*'),
                dp[0][i-1] + 2
            );
        }

        cout << min(dp[0][n-1], dp[1][n-1]) << '\n';
    }
}
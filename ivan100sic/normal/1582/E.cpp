// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll dp[100005][450];

void mx(ll& x, ll y) {
    x = max(x, y);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        R::reverse(a);
        vector<ll> z(n+1);
        for (int i : ra(0, n)) {
            z[i+1] = z[i] + a[i];
        }

        int h = 1;
        while (h*(h+1) / 2 <= n) h++;
        h--;

        for (int i : ra(0, n+1)) {
            fill(dp[i], dp[i]+h+1, 0);
        }

        for (int i : ra(0, n)) {
            for (int j : ra(1, h+1)) {
                if (i + j <= n && (j == 1 || z[i+j] - z[i] < dp[i][j-1])) {
                    mx(dp[i+j][j], z[i+j] - z[i]);
                }

                mx(dp[i+1][j], dp[i][j]);
            }
        }

        int sol = 1;
        for (int j : ra(1, h+1)) {
            if (dp[n][j]) {
                sol = j;
            }
        }

        cout << sol << '\n';
    }
    
}
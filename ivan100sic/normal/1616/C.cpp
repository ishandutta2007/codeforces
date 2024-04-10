// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int a[77];
int dp[77][77];

bool colin(int i, int j, int k) {
    return i*a[j] + j*a[k] + k*a[i] - j*a[i] - k*a[j] - i*a[k] == 0;
}

void mx(int& x, int y) {
    x = max(x, y);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i : ra(0, n)) cin >> a[i];
        memset(dp, 192, sizeof(dp));

        int sol = 1;
        for (int i : ra(0, n)) {
            for (int j : ra(0, i)) {
                mx(dp[i][j], 2);
                for (int k : ra(0, j)) {
                    if (colin(i, j, k)) {
                        mx(dp[i][j], dp[j][k] + 1);
                    }
                }
                mx(sol, dp[i][j]);
            }
        }

        cout << n - sol << '\n';
    }
}
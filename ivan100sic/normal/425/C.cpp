// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m, s, ex;
int a[100005], b[100005];
vector<int> e[100005];

int dp[100005][305];

void mn(int& x, int y) {
    x = min(x, y);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m >> s >> ex;
    for (int i : ra(0, n)) cin >> a[i];
    for (int i : ra(0, m)) {
        cin >> b[i];
        e[b[i]].push_back(i);
    }

    memset(dp, 63, sizeof(dp));
    dp[0][0] = 0;
    for (int i : ra(0, n)) {
        const int x = a[i];
        for (int j : ra(0, 301)) {
            // skip this
            mn(dp[i+1][j], dp[i][j]);

            // seek and take
            auto it = R::lower_bound(e[x], dp[i][j]);
            if (it != end(e[x])) {
                mn(dp[i+1][j+1], *it + 1);
            }
        }
    }

    int sol = 0;
    for (int i : ra(0, n+1)) {
        for (int j : ra(0, 301)) {
            if (ex * j + i + dp[i][j] <= s) {
                sol = max(sol, j);
            }
        }
    }

    cout << sol << "\n";
}
// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll solve_easy(span<int> c, int n, int x, int y) {
    ll sol = 0;
    if (c.size() > 2) {
        sol = ssize(c) / 2 * y;
    } else {
        if (c[1] - c[0] > 1) {
            sol = y;
        } else {
            if (n == 3) {
                sol = 2*x;
            } else if (n == 4 && c[0] == 1 && c[1] == 2) {
                sol = min(x+y, 3*y);
            } else {
                sol = min(x, 2*y);
            }
        }
    }

    return sol;
}

const ll linf = 1e18;

void mn(ll& x, ll y) {
    x = min(x, y);
}

ll solve_hard(span<int> c, int n, ll x, ll y) {
    const int k = ssize(c);

    vector dp(k+5, vector(k+5, linf));
    dp[0][0] = 0;

    for (int i : ra(0, k)) {
        for (int j : ra(0, i+1)) {
            // don't take i
            mn(dp[i+1][j], dp[i][j]);

            // take i and i+1
            if (i+1 < k) {
                mn(dp[i+2][j+1], dp[i][j] + x * (c[i+1] - c[i]));
            }
        }
    }

    ll sol = linf;
    for (int j : ra(0, k/2+1)) {
        mn(sol, dp[k][j] + y*(k/2-j));
    }

    return sol;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        string a, b;
        cin >> n >> x >> y >> a >> b;
        vector<int> c;
        string g(n, 0);
        for (int i : ra(0, n)) {
            if (a[i] != b[i]) {
                c.push_back(i);
                g[i] = 1;
            }
        }

        if (c.empty()) {
            cout << "0\n";
            continue;
        }

        if (c.size() % 2) {
            cout << "-1\n";
            continue;
        }

        if (x >= y) {
            cout << solve_easy(c, n, x, y) << '\n';
        } else {
            cout << solve_hard(c, n, x, y) << '\n';
        }
    }
}
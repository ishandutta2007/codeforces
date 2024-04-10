// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;
string a, b;

int table[505][2];
int dp[2][505][505];

void mn(int& x, int y) {
    x = min(x, y);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m >> a >> b;

    for (int i=0; i<=m; i++) {
        for (char c : {'0', '1'}) {
            string q = b.substr(0, i) + c;
            for (int l=min(ssize(q), ssize(b)); l>=0; l--) {
                if (equal(b.begin(), b.begin() + l, q.end() - l)) {
                    table[i][c-'0'] = l;
                    break;
                }
            }
        }
    }

    memset(dp, 63, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i : ra(0, n)) {
        auto ol = dp[i%2];
        auto nu = dp[(i+1)%2];
        memset(nu, 63, sizeof(dp[0]));

        for (int l : ra(0, m+1)) {
            for (int k : ra(0, i+1)) {
                for (char c : {'0', '1'}) {
                    int l2 = table[l][c - '0'];
                    int k2 = k + (l2 == m);
                    mn(nu[l2][k2], ol[l][k] + (c != a[i]));
                }
            }
        }
    }

    for (int i : ra(0, n-m+2)) {
        int x = 123123123;
        for (int j : ra(0, m+1)) {
            mn(x, dp[n%2][j][i]);
        }
        
        if (x == 123123123) x = -1;
        cout << x << ' ';
    }
    cout << '\n';
}
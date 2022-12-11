#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int nmax = 1e6 + 100;

int dp[nmax][2];

void upd(int& x, int val) {
    if (x == -1) {
        x = val;
    } else {
        x = min(x, val);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    memset(dp, -1, sizeof(dp));
    dp[0][a[0] - '0'] = 0;
    dp[0][1 - (a[0] - '0')] = 1;

    for (int i = 0; i + 1 < n; ++i) {
        for (int x = 0; x < 2; ++x) {
            if (dp[i][x] == -1) {
                continue;
            }
            int y = a[i + 1] - '0';
            if (b[i] - '0' == x) {
                upd(dp[i + 1][a[i + 1] - '0'], dp[i][x]);
            } else {
                upd(dp[i + 1][a[i + 1] - '0'], dp[i][x] + 1);
            }
            if (y == b[i] - '0') {
                upd(dp[i + 1][x], dp[i][x] + 1);
            }
        }
    }

    int ans = dp[n - 1][b[n - 1] - '0'];
    if (dp[n - 1][1 - (b[n - 1] - '0')] != -1) {
        upd(ans, dp[n - 1][1 - (b[n - 1] - '0')] + 1);
    }
    cout << ans << "\n";

}
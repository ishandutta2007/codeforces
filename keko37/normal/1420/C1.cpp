#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 300005;

int t, n, q;
llint dp[MAXN][2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> q;
        dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i <= n; i++) {
            llint x;
            cin >> x;
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + x);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - x);
        }
        cout << max(dp[n][0], dp[n][1]) << '\n';
    }
    return 0;
}
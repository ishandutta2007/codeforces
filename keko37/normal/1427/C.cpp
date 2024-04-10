#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int r, n;
int t[MAXN], x[MAXN], y[MAXN], dp[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> r >> n;
    t[0] = 0; x[0] = y[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }
    int hi = n, mx = 0;
    for (int i = n; i >= 0; i--) {
        while (t[hi] - t[i] > 2 * r) {
            mx = max(mx, dp[hi]);
            hi--;
        }
        int res = mx;
        for (int j = i; j <= hi; j++) {
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[j] - t[i]) {
                res = max(res, dp[j]);
            }
        }
        dp[i] = res + 1;
    }
    cout << dp[0] - 1;
    return 0;
}
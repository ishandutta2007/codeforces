#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 3005;

int t, n;
int a[MAXN], sum[MAXN][MAXN], dp[MAXN][MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            for (int j = 1; j < i; j++) {
                sum[i][j] = (i <= j + a[j]);
                sum[i][j] += sum[i][j - 1];
            }
        }
        for (int i = 0; i <= n+1; i++) dp[n][i] = 0;
        for (int pos = n-1; pos >= 1; pos--) {
            for (int nxt = n + 1; nxt >= pos + 1; nxt--) {
                int res = 1e9;
                if (nxt <= pos + a[pos]) {
                    if (nxt < n) res = min(res, dp[pos][nxt + 1]);
                    res = min(res, sum[nxt][nxt - 1] - sum[nxt][pos] + dp[nxt][pos + a[pos] + 1]);
                }
                dp[pos][nxt] = res;
            }
        }
        cout << dp[1][2] << '\n';
    }
    return 0;
}
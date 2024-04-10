#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

const int mod = 1e9 + 7;
int dp[2005][2005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        m = n - m;
        memset(dp[n], 0, sizeof(dp[n]));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= i && j <= m; ++j) {
                if (j == m) dp[i][j] = (dp[i + 1][j] + k) % mod;
                else dp[i][j] = (dp[i + 1][j] + dp[i + 1][j + 1]) * (mod + 1ll) / 2 % mod;
            }
        }
        printf("%d\n", dp[0][0]);
    }
    return 0;
}
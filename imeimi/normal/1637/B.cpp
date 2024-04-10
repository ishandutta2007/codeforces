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

int n;
int A[105];
int C[105][105];
ll dp[105];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> A[i];
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                for (int k = 0; ; ++k) {
                    bool in = 0;
                    for (int l = i; l <= j; ++l) {
                        if (A[l] == k) in = 1;
                    }
                    if (in) continue;
                    C[i][j] = k + 1;
                    break;
                }
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                dp[i - 1] = 0;
                for (int k = i; k <= j; ++k) {
                    dp[k] = 0;
                    for (int l = i - 1; l < k; ++l) {
                        dp[k] = max(dp[k], dp[l] + C[l + 1][k]);
                    }
                }
                ans += dp[j];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
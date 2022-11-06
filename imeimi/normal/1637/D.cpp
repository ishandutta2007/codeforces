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

int n, A[105], B[105];
bool dp[105][10005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> A[i];
        for (int i = 1; i <= n; ++i) cin >> B[i];
        ll sum = 0, sum2 = 0;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            sum += A[i] + B[i];
            sum2 += A[i] * A[i] + B[i] * B[i];
            for (int j = 0; j <= 10000; ++j) {
                if (!dp[i - 1][j]) continue;
                int k = j + A[i] - B[i], l = j - A[i] + B[i];
                dp[i][abs(k)] = dp[i][abs(l)] = 1;
            }
        }
        for (int i = 0; ; ++i) {
            if (dp[n][i]) {
                debug("i = %d\n", i);
                ll sumA = (sum - i) / 2;
                ll sumB = (sum + i) / 2;
                ll ans = sumA * sumA + sumB * sumB + (n - 2) * sum2;
                printf("%lld\n", ans);
                break;
            }
        }
    }
    return 0;
}
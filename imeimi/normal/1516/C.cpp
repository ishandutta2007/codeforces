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
typedef long long llong;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

const int M = 2e5 + 5;
int n, A[105];
bool dp[M + M], pp[M + M];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> A[i];
    while (1) {
        int even = 1, odd = 0;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (A[i] % 2) even = 0, odd = i;
            sum += A[i];
        }
        if (sum % 2) return printf("0\n"), 0;
        if (even) {
            for (int i = 1; i <= n; ++i) A[i] /= 2;
            continue;
        }
        memset(dp, 0, sizeof(dp));
        dp[M] = 1;
        for (int i = 1; i <= n; ++i) {
            memcpy(pp, dp, sizeof(pp));
            memset(dp, 0, sizeof(dp));
            for (int j = 0; j < M + M; ++j) {
                if (!pp[j]) continue;
                dp[j + A[i]] = 1;
                dp[j - A[i]] = 1;
            }
        }
        if (dp[M]) printf("1\n%d\n", odd);
        else printf("0\n");
        break;
    }
    return 0;
}
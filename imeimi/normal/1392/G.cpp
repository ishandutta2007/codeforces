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

int n, m, k;
char A[25], B[25];
int a[1000001], b[1000001];
int P[20], T[20], Q[20];
int as[1000001], bs[1000001];
int dp[21][1 << 20];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n >> m >> k >> A >> B;
    for (int i = 0; i < k; ++i) P[i] = i;
    for (int i = 0; i <= n; ++i) {
        if (i) {
            cin >> a[i] >> b[i];
            --a[i], --b[i];
            for (int i = 0; i < k; ++i) T[i] = i, Q[i] = P[i];
            swap(T[a[i]], T[b[i]]);
            for (int i = 0; i < k; ++i) P[i] = T[Q[i]];
        }
        for (int j = 0; j < k; ++j) {
            as[i] |= int(A[P[j]] - '0') << j;
            bs[i] |= int(B[P[j]] - '0') << j;
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i <= n; ++i) dp[0][as[i]] = min(dp[0][as[i]], i);
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < (1 << k); ++j) {
            dp[i][j] = dp[i - 1][j];
            for (int l = 0; l < k; ++l) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j ^ (1 << l)]);
            }
        }
    }
    for (int ans = 0; ans < k; ++ans) {
        for (int r = m; r <= n; ++r) {
            int l = dp[ans][bs[r]];
            if (r - l >= m) {
                printf("%d\n%d %d\n", k - ans, l + 1, r);
                return 0;
            }
        }
    }
    printf("0\n1 %d\n", n);
    return 0;
}
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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

void setmin(llong &x, llong y) {
    x = min(x, y);
}

int n, m;
pii A[100];
const llong inf = 1e18;
llong dp[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> A[i].fs >> A[i].se;
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= m; ++i) dp[i] = inf;
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 0; --j) {
            if (j + 1 < A[i].fs - A[i].se) {
                int cost = A[i].fs - A[i].se - j - 1;
                setmin(dp[min(A[i].fs + A[i].se + cost, m)], dp[j] + cost);
            }
            else {
                setmin(dp[min(max(j, A[i].fs + A[i].se), m)], dp[j]);
            }
            if (j < m) dp[j] = min(dp[j], dp[j + 1]);
        }
    }
    llong ans = inf;
    for (int j = 0; j <= m; ++j) {
        ans = min(ans, dp[j] + m - j);
    }
    printf("%lld\n", ans);
    return 0;
}
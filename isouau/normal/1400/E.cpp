#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

typedef long long ll;

inline void addmin(ll &x, ll y) { x = min(x, y); }

ll dp[2][N];
int a[N], b[N];
int n;

int main() {
  memset(dp, 0x7f, sizeof(dp));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
  sort(b + 1, b + n + 1); int lim = unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + lim + 1, a[i]) - b;
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    memset(dp[i & 1], 0x7f, sizeof(dp[i & 1]));
    ll minn = dp[i & 1][0];
    for (int j = 0; j <= lim; j++) {
      addmin(dp[i & 1][min(j, a[i])], dp[(i & 1) ^ 1][j] + (a[i] > j));
    }
    for (int j = 0; j <= a[i]; j++) {
      addmin(minn, dp[i & 1][j] - b[j]);
      addmin(dp[i & 1][j], minn + b[j]);
    }
    for (int j = 0; j <= a[i]; j++) addmin(dp[i & 1][a[i]], dp[(i & 1) ^ 1][j] + b[a[i]] - b[j]);
  }
  ll ans = dp[n & 1][0];
  for (int i = 1; i <= lim; i++) addmin(ans, dp[n & 1][i]);
  printf("%lld\n", ans);
  return 0;
}
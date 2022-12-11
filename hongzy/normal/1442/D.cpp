#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 3000 + 5;

int n, k, sz[N];
ll ans, a[N][N], dp[N << 2][N];
void solve(int u, int l, int r) {
  if(l == r) {
    rep(i, 0, sz[l]) ans = max(ans, a[l][i] + dp[u][k - i]);
    return ;
  }
  int mid = (l + r) >> 1;
  copy(dp[u], dp[u] + k + 1, dp[u << 1]);
  rep(i, mid + 1, r) per(j, k, sz[i])
    dp[u << 1][j] = max(dp[u << 1][j], dp[u << 1][j - sz[i]] + a[i][sz[i]]);
  solve(u << 1, l, mid);
  copy(dp[u], dp[u] + k + 1, dp[u << 1 | 1]);
  rep(i, l, mid) per(j, k, sz[i])
    dp[u << 1 | 1][j] = max(dp[u << 1 | 1][j], dp[u << 1 | 1][j - sz[i]] + a[i][sz[i]]);
  solve(u << 1 | 1, mid + 1, r);
}
int main() {
  scanf("%d%d", &n, &k);
  rep(i, 1, n) {
    int t; scanf("%d", &t);
    rep(j, 1, t) {
      int x; scanf("%d", &x);
      if(j <= k) { a[i][j] = a[i][j - 1] + x; }
    }
    sz[i] = min(t, k);
  }
  solve(1, 1, n);
  printf("%lld\n", ans);
  return 0;
}
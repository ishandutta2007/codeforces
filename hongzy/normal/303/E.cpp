#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef double db;
const int N = 85;
const db eps = 1e-10;
int n, l[N], r[N], len[N], num[N + N], m;
db dp[16][N][N], ans[N][N], w[N + N][N], w2[N + N][N], w3[N + N][N];
void solve(int d, int v, int l, int r) {
  if(l == r) {
    if(!(::l[l] <= v && v < ::r[l])) return ;
    rep(i, 0, n) rep(j, 0, n - i) if(dp[d][i][j] > eps) {
      db t = dp[d][i][j] / (j + 1) * w3[v][l];
      ans[l][i + 1] += t;
      ans[l][i + j + 2] -= t;
    }
    return ;
  }
  int mid = (l + r) >> 1;
  static db g[N][N][N];
  auto func = [&](int l, int r) {
    rep(i, 0, n) rep(j, 0, n - i) g[l - 1][i][j] = dp[d][i][j];
    rep(i, l, r) {
      rep(j, 0, n) rep(k, 0, n - j) {
        g[i][j][k] = 0;
        if(::r[i] > v + 1)
          g[i][j][k] += g[i - 1][j][k] * w[v][i];
        if(j && ::l[i] < v)
          g[i][j][k] += g[i - 1][j - 1][k] * w2[v][i];
        if(k && ::l[i] <= v && ::r[i] > v)
          g[i][j][k] += g[i - 1][j][k - 1] * w3[v][i];
      }
    }
    rep(i, 0, n) rep(j, 0, n - i) dp[d + 1][i][j] = g[r][i][j];
  };
  func(mid + 1, r);
  solve(d + 1, v, l, mid);
  func(l, mid);
  solve(d + 1, v, mid + 1, r);
}
int main() {
  scanf("%d", &n);
  rep(i, 1, n) {
    scanf("%d%d", l + i, r + i);
    num[i] = l[i];
    num[n + i] = r[i];
    len[i] = r[i] - l[i];
  }
  sort(num + 1, num + n * 2 + 1);
  m = unique(num + 1, num + n * 2 + 1) - num - 1;
  rep(i, 1, n) {
    l[i] = lower_bound(num + 1, num + m + 1, l[i]) - num;
    r[i] = lower_bound(num + 1, num + m + 1, r[i]) - num;
  }
  rep(v, 1, m - 1) {
    rep(i, 1, n) {
      if(r[i] > v + 1)
        w[v][i] = 1.0 * min(len[i], num[r[i]] - num[v + 1]) / len[i];
      if(l[i] < v)
        w2[v][i] = 1.0 * min(len[i], num[v] - num[l[i]]) / len[i];  
      if(l[i] <= v && r[i] > v)
        w3[v][i] = 1.0 * (num[v + 1] - num[v]) / len[i];
    }
  }
  dp[1][0][0] = 1;
  rep(v, 1, m - 1) solve(1, v, 1, n);
  rep(i, 1, n) rep(j, 1, n) ans[i][j] += ans[i][j - 1];
  rep(i, 1, n) rep(j, 1, n)
    printf("%.8f%c", ans[i][j], " \n"[j == n]);
  return 0;
}
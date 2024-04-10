#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int V = 1e7 + 10;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
bool tag[V];
int p[V], q[V], pc;
void sieve(int n) {
  q[1] = 1;
  for(int i = 2, v; i <= n; i ++) {
    if(!tag[i]) p[++ pc] = i, q[i] = i;
    for(int j = 1; j <= pc && (v = i * p[j]) <= n; j ++) {
      tag[v] = 1;
      q[v] = q[i] % p[j] ? q[i] * p[j] : q[i] / p[j];
      if(i % p[j] == 0) break ;
    }
  }
}
int n, k, a[N], L[21][N], dp[21][N], cnt[V];
int main() {
  sieve(1e7);
  int test; scanf("%d", &test);
  while(test --) {
    scanf("%d%d", &n, &k);
    rep(i, 1, n) scanf("%d", a + i), a[i] = q[a[i]];
    rep(t, 0, k) {
      int l = 1, c = 0;
      rep(i, 1, n) cnt[a[i]] = 0;
      rep(i, 1, n) {
        if(cnt[a[i]] ++) c ++;
        while(c > t) {
          if(cnt[a[l]] >= 2) c --;
          cnt[a[l]] --;
          l ++;
        }
        L[t][i] = l;
        // LOG("L[%d][%d] = %d\n", t, i, L[t][i]);
      }
    }
    int ans = n;
    rep(t, 0, k) {
      dp[t][0] = 0;
      rep(i, 1, n) {
        dp[t][i] = n;
        rep(x, 0, t) {
          dp[t][i] = min(dp[t][i], dp[t - x][L[x][i] - 1] + 1);
        }
      }
      ans = min(ans, dp[t][n]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
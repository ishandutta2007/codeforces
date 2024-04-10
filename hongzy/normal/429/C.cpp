#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
int n, b, t[32], c[32], s[1 << 11], cnt[1 << 11];
bool dp[12][25][1 << 11];
int main() {
  scanf("%d", &n);
  rep(i, 1, n) {
    scanf("%d", t + i);
    if(t[i] > 1) c[++ b] = t[i];
  }
  if(n == 1) { puts("YES"); return 0; }
  if(b * 2 > n - 1) { puts("NO"); return 0; }
  sort(c + 1, c + b + 1);
  if(c[b] < n) { puts("NO"); return 0; }
  dp[0][n - b][0] = 1;
  for(int S = 1; S < (1 << b); S ++) {
    s[S] = s[S & (S - 1)] + c[__builtin_ctz(S) + 1];
    cnt[S] = cnt[S & (S - 1)] + 1;
  }
  rep(i, 1, b) rep(j, 0, n - b) {
    for(int S = 0; S < (1 << (i - 1)); S ++) {
      bool z = 0;
      int cS = ((1 << (i - 1)) - 1) ^ S;
      for(int T = cS; !z; T = (T - 1) & cS) {
        rep(k, j, n - b) {
          if(dp[i - 1][k][S ^ T] && s[T] + k - j == c[i] - 1 && k - j + cnt[T] >= 2) {
            z = 1; break ;
          }
        }
        if(!T) break ;
      }
      if(z) dp[i][j][S ^ (1 << (i - 1))] = 1;
    }
  }
  puts(dp[b][0][1 << (b - 1)] ? "YES" : "NO");
  return 0;
}
#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 510;
const int mod = 1e9 + 7;
int n, fa[N], pw[N], c[N];
int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", fa + i), c[~fa[i] ? fa[i] : 0] ++;
  *pw = 1;
  rep(i, 1, n) pw[i] = pw[i - 1] * 2 % mod;
  int ans = 0;
  rep(i, 1, n) ans = (ans + 1 + mod - pw[c[i]]) % mod;
  ans = (ans + pw[n - 1] - 1) % mod;
  printf("%d\n", ans);
  return 0;
}
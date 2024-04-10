#include <cstdio>
#include <iostream>
using namespace std;
const int inf = 1e9;
const int maxn = 21;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int dp[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      m = gcd(m, t);
    }
    // printf("%d\n", m);
    fill(dp, dp + maxn, inf);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < maxn; j++)
        dp[gcd(j, i)] = min(dp[gcd(j, i)], dp[j] + n - i + 1);
    int res = inf;
    for (int i = 0; i < maxn; i++)
      if (gcd(i, m) == 1) res = min(res, dp[i]);
    printf("%d\n", res);
  }
  return 0;
}
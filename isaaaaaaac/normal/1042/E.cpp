#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1e6 + 50;
const LL mod = 998244353;

struct node {
  int v, x, y;
  inline bool operator < (const node &o) const { return v < o.v; }
} a[N];

inline LL pow(LL x, LL exp = mod - 2) {
  LL res = 1;
  for (; exp; exp >>= 1, x = x * x % mod)
    if (exp & 1) res = res * x % mod;
  return res;
}

int n, m, t;
LL dp[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, x; i <= n; i ++)
    for (int j = 1; j <= m; j ++) {
      scanf("%d", &x);
      a[++ t] = (node) { x, i, j };
    }
  sort(a + 1, a + t + 1);
  LL sqrx = 0, sumx = 0, sqry = 0, sumy = 0, sdp = 0;
  for (int i = 1, j = 1; i <= t; i = j) {
    if (a[i].v == a[1].v) {
      j = i + 1;
      (sumx += a[i].x) %= mod;
      (sqrx += a[i].x * a[i].x) %= mod;
      (sumy += a[i].y) %= mod;
      (sqry += a[i].y * a[i].y) %= mod;
    }
    else {
      LL tmp = pow(i - 1);
      while (a[j].v == a[i].v && j <= t) j ++;
      for (int k = i; k < j; k ++) {
        LL &f = dp[k];
        f = (sdp + sqrx + sqry
             + 1ll * (i - 1) * a[k].x * a[k].x % mod
             + 1ll * (i - 1) * a[k].y * a[k].y % mod
             - 2ll * sumx * a[k].x % mod
             - 2ll * sumy * a[k].y % mod) % mod;
        f = (f + mod) % mod;
        f = f * tmp % mod;
      }
      for (int k = i; k < j; k ++) {
        (sdp += dp[k]) %= mod;
        (sumx += a[k].x) %= mod;
        (sqrx += a[k].x * a[k].x) %= mod;
        (sumy += a[k].y) %= mod;
        (sqry += a[k].y * a[k].y) %= mod;
      }
    }
  }
  int r, c;
  scanf("%d%d", &r, &c);
  for (int i = 1; i <= t; i ++)
    if (a[i].x == r && a[i].y == c) {
      printf("%lld\n", dp[i]);
      return 0;
    }
  return 0;
}
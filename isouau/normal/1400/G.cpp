#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5, md = 998244353;

inline int add(int x, int y) {
  x += y;
  if (x >= md) x -= md;
  return x;
}

inline int sub(int x, int y) {
  x -= y;
  if (x < 0) x += md;
  return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = mul(ans, x);
    y >>= 1; x = mul(x, x);
  }
  return ans;
}

int sum[45][N];
int l[N], r[N], s[N], used[N], fac[N], inv[N], x[25], y[25];
int n, m, ans;

inline int comb(int n, int m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return mul(fac[n], mul(inv[m], inv[n - m]));
}

int main() {
  scanf("%d%d", &n, &m);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
  inv[n] = fpow(fac[n], md - 2);
  for (int i = n; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
  for (int i = 1; i <= n; i++) scanf("%d%d", &l[i], &r[i]), ++s[l[i]], --s[r[i] + 1];
  for (int i = 1; i <= m; i++) scanf("%d%d", &x[i], &y[i]);
  for (int i = 1; i <= n; i++) s[i] += s[i - 1];
  for (int cnt = 0; cnt <= m * 2; cnt++) {
    for (int i = 1; i <= n; i++) {
      sum[cnt][i] = add(sum[cnt][i - 1], comb(s[i] - cnt, i - cnt));
    }
  }
  for (int mask = 0; mask < (1 << m); mask++) {
    int cnt = 0, L = 1, R = n;
    for (int i = 1; i <= m; i++) {
      if ((mask >> (i - 1)) & 1) {
        if (!used[x[i]]) used[x[i]] = 1, ++cnt;
        if (!used[y[i]]) used[y[i]] = 1, ++cnt;
        L = max(L, max(l[x[i]], l[y[i]]));
        R = min(R, min(r[x[i]], r[y[i]]));
      }
    }
    if (L <= R) {
      int res = sub(sum[cnt][R], sum[cnt][L - 1]);
      if (__builtin_popcount(mask) & 1) ans = sub(ans, res);
      else ans = add(ans, res);
    }
    for (int i = 1; i <= m; i++) used[x[i]] = used[y[i]] = 0;
  }
  printf("%d\n", ans);
  return 0;
}
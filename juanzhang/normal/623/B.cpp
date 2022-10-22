#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 10;
ll f[3][maxn];
int n, A, B, a[maxn];

inline ll calc(int x, int P) {
  if (x % P == 0) return 0;
  if ((x + 1) % P == 0 || (x - 1) % P == 0) {
    return B;
  }
  return 1ll << 40;
}

inline ll check(int P) {
  bool flg = 1;
  f[1][0] = f[2][0] = 1ll << 40;
  for (int i = 1; i <= n; i++) {
    ll v = calc(a[i], P);
    f[0][i] = f[0][i - 1] + v;
    f[1][i] = min(f[0][i - 1], f[1][i - 1]) + A;
    f[2][i] = min(f[1][i - 1], f[2][i - 1]) + v;
    flg &= i == 1 || f[0][i - 1] > f[1][i - 1];
  }
  return min(f[0][n], min(flg ? 1ll << 60: f[1][n], f[2][n]));
}

inline ll factor(int x) {
  int tmp = sqrt(x);
  ll res = 1ll << 60;
  for (int i = 2; i <= tmp; i++) {
    if (x % i == 0) {
      res = min(res, check(i));
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) res = min(res, check(x));
  return res;
}

int main() {
  scanf("%d %d %d", &n, &A, &B);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  if (n == 1) return puts("0");
  int s[7];
  s[1] = a[1];
  s[2] = a[1] - 1;
  s[3] = a[1] + 1;
  s[4] = a[n];
  s[5] = a[n] - 1;
  s[6] = a[n] + 1;
  ll ans = 1ll << 60;
  for (int i = 1; i < 7; i++) {
    ans = min(ans, factor(s[i]));
  }
  printf("%I64d", ans);
  return 0;
}
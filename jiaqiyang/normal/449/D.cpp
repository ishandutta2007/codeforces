#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 1 << 20, MOD = 1000000007;

int n, f[N], g[N];

void fwt(int l, int r) {
  if (l + 1 == r) return;
  int mid = (l + r) >> 1;
  fwt(l, mid);
  fwt(mid, r);
  for (int i = 0; i < mid - l; ++i) (g[l + i] += g[mid + i]) %= MOD;
}

void ifwt(int l, int r) {
  if (l + 1 == r) return;
  int mid = (l + r) >> 1;
  ifwt(l, mid);
  ifwt(mid, r);
  for (int i = 0; i < mid - l; ++i) (f[l + i] -= f[mid + i]) %= MOD;
}

void solve(int l, int r) {
  if (l + 1 == r) return;
  int mid = (l + r) >> 1;
  solve(l, mid);
  solve(mid, r);
  std::copy(f + l, f + r, g + l);
  fwt(l, mid);
  fwt(mid, r);
  for (int i = 0; i < mid - l; ++i) {
    int u = g[l + i], v = g[mid + i];
    f[l + i] = u * (v + 1LL) % MOD;
  }
  ifwt(l, mid);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);
    ++f[a];
  }
  g[0] = 1;
  for (int i = 1; i < N; ++i) g[i] = 2LL * g[i - 1] % MOD;
  for (int i = 0; i < N; ++i) f[i] = g[f[i]] - 1;
  solve(0, N);
  printf("%d\n", (f[0] + MOD) % MOD);
  return 0;
}
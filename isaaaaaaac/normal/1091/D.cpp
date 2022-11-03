#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod = 998244353;
const int N = 1e6 + 50;

namespace MathCal {
  LL fac[N], inv[N];

  inline LL Pow(LL x, LL exp) {
    LL res = 1;
    for (; exp; exp >>= 1, x = x * x % mod)
      if (exp & 1) res = res * x % mod;
    return res;
  }
  inline void Init() {
    for (int i = fac[0] = 1; i < N; i ++) fac[i] = fac[i - 1] * i % mod;
    inv[N - 1] = Pow(fac[N - 1], mod - 2);
    for (int i = N - 1; i; i --) inv[i - 1] = inv[i] * i % mod;
  }
  inline LL C(int x, int y) {
    return y > x ? 0 : fac[x] * inv[y] % mod * inv[x - y] % mod;
  }
}
using namespace MathCal;

int n;

int main() {
  Init();
  scanf("%d", &n);
  LL ans = 1;
  for (int k = 1; k < n; k ++) {
    // cerr << fac[n - k] * k % mod * C(n, k + 1) << endl;
    ans = (ans + fac[n - k] * k % mod * C(n, k + 1)) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
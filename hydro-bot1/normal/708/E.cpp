// Hydro submission #62d016f464b2490bf4219231@1657804533287
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1505
#define K 3000005
const int mod = 1e9 + 7;
int fac[K], ifac[K], n, m, a, b, k, Num, Num2, g[N << 1], dp[N << 1][N << 1],
    ans, s[N], p[N], q[N];
inline int Fpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
inline void init() {
  fac[0] = 1;
  for (int i = 1; i <= k; ++i) fac[i] = fac[i - 1] * i % mod;
  ifac[k] = Fpow(fac[k], mod - 2);
  for (int i = k - 1; ~i; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
}
inline int Combination(int n, int k) {
  return fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}
signed main() {
  cin >> n >> m;
  cin >> a >> b;
  cin >> k;
  init();
  // cout << Fpow(3, 1024) << endl;
  /*
  cout << "--------------\n";
  for (int i = 0; i <= k; ++i) cout << fac[i] << ' ' << ifac[i] << endl;
  cout << "--------------\n";
  */
  // cout << n << ' ' << m << ' ' << a << ' ' << b << ' ' << k << endl;
  // cout << ifac[k] << endl;
  Num = a * Fpow(b, mod - 2) % mod, Num2 = 1 - Num, Num2 += mod, Num2 %= mod;
  // cout << Num << ' ' << Num2 << endl;
  for (int i = 0; i <= k && i <= m; ++i)
    g[i] = Combination(k, i) * Fpow(Num, i) % mod * Fpow(Num2, k - i) % mod;
  dp[0][m] = 1;
  p[0] = g[0];
  /*
  cout << "NUM = " << Num << ",   "
       << "Num2 = " << Num2 << endl;
  for (int i = 0; i <= k && i <= m; ++i) cout << g[i] << ' ';
  cout << endl;
  */
  for (int i = 1; i <= m; ++i) p[i] = p[i - 1] + g[i], p[i] %= mod;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) s[j] = s[j - 1] + dp[i - 1][j], s[j] %= mod;
    for (int j = 1; j <= m; ++j)
      q[j] = q[j - 1] + g[j] * s[j] % mod, q[j] %= mod;
    for (int r = 1; r <= m; ++r)
      dp[i][r] =
          g[m - r] *
          ((s[m] - s[m - r] + mod) % mod * p[r - 1] % mod - q[r - 1] + mod) %
          mod;
  }
  for (int i = 1; i <= m; ++i) (ans += dp[n][i]) %= mod;
  cout << ans << endl;
  return 0;
}
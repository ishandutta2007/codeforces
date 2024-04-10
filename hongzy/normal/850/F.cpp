#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
using ll = long long;
const int N = 2510;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
int qpow(int a, int b) {
  int ans = 1;
  for(; b >= 1; b >>= 1, a = (ll)a * a % mod)
    if(b & 1) ans = (ll)ans * a % mod;
  return ans;
}
int n, s, m, a[N], f[M];
int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", a + i), m = max(m, a[i]), (s += a[i]) %= mod;
  rep(i, 1, m)
    f[i] = (f[i - 1] + (mod - s + 1ll) * qpow(s - i + 1, mod - 2)) % mod;
  rep(i, 2, m) (f[i] += f[i - 1]) %= mod;
  int ans = 0;
  rep(i, 1, n) (ans += f[a[i]]) %= mod;
  ans = (ans + s * (s - 1ll)) % mod;
  printf("%d\n", ans);
  return 0;
}
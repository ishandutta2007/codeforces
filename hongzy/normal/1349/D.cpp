#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
const int mod = 998244353;
int n, s, a[N], f[N * 3], inv[N * 3];
int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", a + i), s += a[i];
  rep(i, 1, s - 1) inv[i] = i > 1 ? (mod - mod/i) * (ll)inv[mod % i] % mod : 1;
  rep(i, 1, s - 1) f[i+1] = ( (s + (n-2ll) * i) % mod * f[i] + (mod-i) * (n-1ll) % mod * (f[i-1] + 1) ) % mod * inv[s-i] % mod;
  int ans = mod - f[s];
  rep(i, 1, n) (ans += f[a[i]]) %= mod;
  printf("%d\n", ans);
  return 0;
}
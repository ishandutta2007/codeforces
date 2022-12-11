#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
using ll = long long;

const int N = 6e5 + 10;
const int mod = 998244353;
int n, a[N], b, c[N][2];
int qpow(int a, int b) {
  int ans = 1;
  for(; b >= 1; b >>= 1, a = (ll)a * a % mod)
    if(b & 1) ans = (ll)ans * a % mod;
  return ans;
}
int fac[N], fav[N];
void binom(int n) {
  fac[0] = 1;
  rep(i, 1, n) fac[i] = (ll)fac[i - 1] * i % mod;
  fav[n] = qpow(fac[n], mod - 2);
  per(i, n, 1) fav[i - 1] = (ll)fav[i] * i % mod;
}
int main() {
  scanf("%d", &n); binom(n);
  rep(i, 1, n) scanf("%d", a + i);
  int mn = *min_element(a + 1, a + n + 1);
  int mx = *max_element(a + 1, a + n + 1);
  int t = mn + n - 1;
  rep(i, 1, n) scanf("%d", &b), c[a[i]][b] ++;
  if(mx > t) { puts("0"); return 0; }
  if(mx == mn) { printf("%d\n", fac[n]); return 0; }
  int ans = (ll)fac[n] * fav[n-c[t][1]] % mod, cnt = 0;
  rep(i, mn, mx) {
    if(c[i][0] && cnt < t - i) { ans = 0; break ; }
    cnt += c[i][0]; ans = (ll)ans * fac[c[i][0]] % mod;
    if(i != t && c[i][1] && (c[i][1] > 1 || cnt < i - mn)) { ans = 0; break ; }
    cnt += c[i][1];
  }
  printf("%d\n", ans);
  return 0;
}
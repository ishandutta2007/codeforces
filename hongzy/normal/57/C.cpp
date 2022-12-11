#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int qpow(int a, int b) {
  int ans = 1;
  for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
    if(b & 1) ans = (ll) ans * a % mod;
  return ans;
}
int fac[N], fav[N]; 
ll C(int n, int m) {
  return n < m ? 0 : (ll)fac[n] * fav[m] % mod * fav[n - m];
}
void binom(int n) {
  fac[0] = 1;
  for(int i = 1; i <= n; i ++) fac[i] = (ll)fac[i - 1] * i % mod;
  fav[n] = qpow(fac[n], mod - 2);
  for(int i = n; i >= 1; i --) fav[i - 1] = (ll)fav[i] * i % mod;
}
int main() {
  int n;
  cin >> n;
  binom(2 * n);
  int ans = 0;
  for(int i = 1; i <= n; i ++) {
    ans = (ans + C(n + i - 2, n - 1)) % mod;
  }
  ans = (ans * 2ll + mod - n) % mod;
  printf("%d\n", ans);
  return 0;
}
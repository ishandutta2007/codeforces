#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = 1ll * a * a % mod)
      if(b & 1) ans = 1ll * ans * a % mod;
   return ans;
}
int fac[N], fav[N]; 
void binom(int n) {
   fac[0] = 1;
   for(int i = 1; i <= n; i ++) fac[i] = 1ll * fac[i - 1] * i % mod;
   fav[n] = qpow(fac[n], mod - 2);
   for(int i = n; i >= 1; i --) fav[i - 1] = 1ll * fav[i] * i % mod;
}
int n, m, ans, pw[N], pw2[N];
int main() {
   scanf("%d%d%*d%*d", &n, &m);
   binom(max(n, m));
   pw[0] = pw2[0] = 1;
   rep(i, 1, n) pw[i] = 1ll * pw[i - 1] * n % mod, pw2[i] = 1ll * pw2[i - 1] * m % mod;
   rep(i, 0, min(n - 2, m - 1)) {
      ans = (ans + 1ll * fac[n - 2] * fav[n - 2 - i] % mod * fac[m - 1] % mod * fav[i] % mod * fav[m - 1 - i] % mod 
      * (i == n - 2 ? 1 : pw[n - i - 3] * (i + 2ll) % mod) % mod * pw2[n - 2 - i]) % mod;
   }
   printf("%d\n", ans);
   return 0;
}
#include <algorithm>
#include <cstdio>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int n, k, w, fac[N], fav[N];
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = 1ll * a * a % mod)
      if(b & 1) ans = 1ll * ans * a % mod;
   return ans;
}
void init(int n) {
   fac[0] = 1;
   rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
   fav[n] = qpow(fac[n], mod - 2);
   per(i, n, 1) fav[i - 1] = 1ll * fav[i] * i % mod;
}
int C(int n, int m) {
   return n < m ? 0 : 1ll * fac[n] * fav[m] % mod * fav[n - m] % mod;
}
int S(int n, int m) {
   int ans = 0;
   for(int i = 0; i <= m; i ++) {
      int res = 1ll * C(m, i) * qpow(m - i, n) % mod;
      if(i & 1) (ans += mod - res) %= mod;
      else (ans += res) %= mod;
   }
   return 1ll * ans * fav[m] % mod;
}
int main() {
   scanf("%d%d", &n, &k); init(n);
   rep(i, 1, n) {
      int x; scanf("%d", &x); (w += x) %= mod;
   }
   int res = 1ll * w * (S(n, k) + (n - 1ll) * S(n - 1, k) % mod) % mod;
   printf("%d\n", res);
   return 0;
}
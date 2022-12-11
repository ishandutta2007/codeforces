#include <algorithm>
#include <cstdio>
using namespace std;
const int mod = 998244353;
const int N = 1e4 + 10;
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = 1ll * a * a % mod)
      if(b & 1) ans = 1ll * ans * a % mod;
   return ans;
}
int n, s, r, fac[N], fav[N], inv[N];
int C(int x, int y) {
   return x < 0 || y < 0 || x < y ? 0 : 1ll * fac[x] * fav[y] % mod * fav[x - y] % mod;
}
int calc(int s, int n, int lim) {
   if(n == 0) return s == 0;
   if((lim - 1) * n < s) return 0;
   int ans = 0;
   for(int i = 0; i <= n; i ++) {
      int tmp = 1ll * C(n, i) * C(s - lim * i + n - 1, n - 1) % mod;
      (ans += (i & 1 ? mod - 1ll : 1ll) * tmp % mod) %= mod; 
   }
   return ans;
}
int main() {
   scanf("%d%d%d", &n, &s, &r);
   fac[0] = 1;
   for(int i = 1; i < N; i ++) fac[i] = 1ll * fac[i - 1] * i % mod;
   fav[N - 1] = qpow(fac[N - 1], mod - 2);
   for(int i = N - 1; i >= 1; i --) fav[i - 1] = 1ll * fav[i] * i % mod;
   for(int i = 1; i < N; i ++) inv[i] = 1ll * fav[i] * fac[i - 1] % mod;
   int res = 0 * 0;
   for(int v = r; v <= s; v ++) {
      for(int i = 0; i < n; i ++) {
         if(s - v * (i + 1) < 0) break ;
         (res += 1ll * C(n - 1, i) * calc(s - v * (i + 1), n - (i + 1), v) % mod * inv[i + 1] % mod) %= mod;
      }
   }
   res = 1ll * res * qpow(C(s - r + n - 1, n - 1), mod - 2) % mod;
   printf("%d\n", res);
   return 0;
}
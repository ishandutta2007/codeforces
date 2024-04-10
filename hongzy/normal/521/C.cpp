#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
 
typedef double db;
typedef long long ll;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int n, k, ans, fav[N], fac[N], S[N], pw[N], SS[N];
char s[N];
int C(int n, int m) {
   return n < m || m < 0 || n < 0 ? 0 : 1ll * fac[n] * fav[m] % mod * fav[n - m] % mod;
}
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = 1ll * a * a % mod)
      if(b & 1) ans = 1ll * ans * a % mod;
   return ans;
}
void binom(int n) {
   fac[0] = 1;
   for(int i = 1; i <= n; i ++) fac[i] = 1ll * fac[i - 1] * i % mod;
   fav[n] = qpow(fac[n], mod - 2);
   for(int i = n; i >= 1; i --) fav[i - 1] = 1ll * fav[i] * i % mod;
}
int main() {
   scanf("%d%d%s", &n, &k, s + 1);
   binom(n);
   pw[0] = 1;
   rep(i, 1, n) pw[i] = 10ll * pw[i - 1] % mod;
   rep(i, 1, n) S[i] = (10ll * S[i - 1] + (s[i] & 15)) % mod;
   rep(i, 1, n) SS[i] = (SS[i - 1] + S[i]) % mod;
   if(k == 0) {
      printf("%d\n", S[n]);
      return 0;
   }
   rep(len, 1, n - 2) {
      int cur = ((SS[n - 1] - SS[len] + mod) % mod - 1ll * pw[len] * SS[n - len - 1] % mod + mod) % mod;
      (ans += 1ll * C(n - len - 2, k - 2) * cur % mod) %= mod;
   }
   // ans = 0;
   rep(i, 1, n) {
      (ans += 1ll * C(n - 1 - i, k - 1) * S[i] % mod) %= mod;
   }
   int ret = 0;
   per(i, n, 1) {
      (ret += 1ll * (s[i] & 15) * pw[n - i] % mod) %= mod;
      (ans += 1ll * C(n - 1 - (n - i + 1), k - 1) * ret % mod) %= mod;
   }
   printf("%d\n", ans);
   return 0;
}
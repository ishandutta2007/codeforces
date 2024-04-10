#include <algorithm>
#include <cstdio>
using namespace std;

const int mod = 998244353, N = 66;

int n, a[N], b[N], c[N * 2], f[N], bin[N], inv[N];
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = 1ll * a * a % mod)
      if(b & 1) ans = 1ll * ans * a % mod;
   return ans;
}
int main() {
   scanf("%d", &n);
   for(int i = 1; i <= n; i ++) {
      scanf("%d%d", a + i, b + i);
      c[i * 2 - 1] = a[i];
      c[i * 2] = ++ b[i];
   }
   sort(c + 1, c + 2 * n + 1);
   int m = unique(c + 1, c + 2 * n + 1) - c - 1;
   for(int i = 1; i <= n; i ++) {
      a[i] = lower_bound(c + 1, c + m + 1, a[i]) - c;
      b[i] = lower_bound(c + 1, c + m + 1, b[i]) - c;
   }
   inv[1] = 1;
   for(int i = 2; i <= n; i ++) {
      inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
   }
   f[0] = bin[0] = 1;
   for(int j = m; j >= 2; j --) { //[c[j-1], c[j])
      int L = c[j] - c[j - 1];
      for(int i = 1; i <= n; i ++)
         bin[i] = 1ll * bin[i - 1] * (L + i - 1) % mod * inv[i] % mod;
      for(int i = n; i >= 1; i --) {
         for(int k = i - 1; k >= 0; k --) if(a[k + 1] <= j - 1 && b[k + 1] >= j) {
            f[i] = (f[i] + 1ll * f[k] * bin[i - k]) % mod;
         } else break ;
      }
   }
   int ans = f[n], tot = 1;
   for(int i = 1; i <= n; i ++) tot = 1ll * tot * (c[b[i]] - c[a[i]]) % mod;
   ans = 1ll * ans * qpow(tot, mod - 2) % mod;
   printf("%d\n", ans);
   return 0;
}
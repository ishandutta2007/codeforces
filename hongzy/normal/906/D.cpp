#include <algorithm>
#include <cstring>
#include <cstdio>
#include <unordered_map>
using namespace std;
const int N = 1e5 + 10;
int n, mod, q, a[N];
unordered_map<int, int> val;
int phi(int n) {
   int ans = n;
   for(int i = 2; i * i <= n; i ++) {
      if(n % i == 0) {
         ans = ans / i * (i - 1);
         while(n % i == 0) n /= i;
      }
   }
   if(n > 1) ans = ans / n * (n - 1);
   return ans;
}
int qpow(int a, int b, int mod) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = 1ll * a * a < mod ? a * a : 1ll * a * a % mod + mod)
      if(b & 1) ans = 1ll * ans * a < mod ? ans * a : 1ll * ans * a % mod + mod;
   return ans;
}
int solve(int l, int r, int mod) {
   if(l == r) return a[l] < mod ? a[l] : a[l] % mod + mod;
   if(mod == 1) return 1;
   int x = solve(l + 1, r, val[mod]);
   return qpow(a[l], x, mod);
}
int main() {
   scanf("%d%d", &n, &mod);
   for(int i = 1; i <= n; i ++) scanf("%d", a + i);
   for(int p = mod, nxt = 0; p > 1; p = nxt) {
      val[p] = nxt = phi(p);
   }
   scanf("%d", &q);
   while(q --) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", solve(l, r, mod) % mod);
   }
   return 0;
}
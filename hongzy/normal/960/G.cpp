#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 262144 * 2 + 5, mod = 998244353;
int n, A, B, len, rev[N], k, W[N], iW[N], ntta[N], nttb[N];
int fac[N], fav[N];
inline int add(int x, int y) {
   return x + y >= mod ? x + y - mod : x + y;
}
inline int dec(int x, int y) {
   return x - y < 0 ? x - y + mod : x - y;
}
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = 1ll * a * a % mod)
      if(b & 1) ans = 1ll * ans * a % mod;
   return ans;
}
void InitNTT(int n) {
   len = 1; k = 0;
   while(len <= n) len <<= 1, k ++;
   rep(i, 1, len - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
   int w0 = qpow(3, (mod - 1) / len); W[0] = iW[len] = 1;
   rep(i, 1, len) W[i] = iW[len - i] = 1ll * W[i - 1] * w0 % mod;
}
void NTT(int *a, const int *W) {
   rep(i, 1, len - 1) if(i < rev[i]) swap(a[i], a[rev[i]]);
   for(int i = 1; i < len; i <<= 1) {
      for(int j = 0, t = len / (i << 1); j < len; j += i << 1) {
         const int *wn = W;
         for(int k = 0; k < i; k ++, wn += t) {
            int p = a[j + k], q = 1ll * *wn * a[j + k + i] % mod;
            a[j + k] = add(p, q); a[j + k + i] = dec(p, q);
         }
      }
   }
   if(W == iW) {
      int inv = mod - (mod - 1) / len;
      for(int i = 0; i < len; i ++)
         a[i] = 1ll * a[i] * inv % mod;
   }
}
#define poly vector<int>
poly operator * (poly a, poly b) {
   int deg = (int) a.size() + b.size() - 2; InitNTT(deg);
   for(int i = 0; i < len; i ++) ntta[i] = i < a.size() ? a[i] : 0;
   for(int i = 0; i < len; i ++) nttb[i] = i < b.size() ? b[i] : 0;
   NTT(ntta, W); NTT(nttb, W);
   for(int i = 0; i < len; i ++) ntta[i] = 1ll * ntta[i] * nttb[i] % mod;
   NTT(ntta, iW);
   poly ans(deg + 1);
   for(int i = 0; i <= deg; i ++) ans[i] = ntta[i];
   return ans;
}
poly offset(poly a, int c) {
   static int pw[N];
   int n = a.size() - 1;
   pw[0] = 1;
   for(int i = 1; i <= n; i ++) pw[i] = 1ll * pw[i - 1] * c % mod;
   InitNTT(n << 1);
   for(int i = 0; i < len; i ++) ntta[i] = i <= n ? 1ll * a[i] * fac[i] % mod : 0;
   for(int i = 0; i < len; i ++) nttb[i] = i <= n ? 1ll * pw[n - i] * fav[n - i] % mod : 0;
   NTT(ntta, W); NTT(nttb, W);
   for(int i = 0; i < len; i ++) ntta[i] = 1ll * ntta[i] * nttb[i] % mod;
   NTT(ntta, iW);
   poly ans(n + 1);
   for(int i = 0; i <= n; i ++) ans[i] = 1ll * fav[i] * ntta[n + i] % mod;
   return ans;
}
poly solve(int n) {
   if(n == 0) return poly(1, 1);
   poly t = solve(n >> 1);
   t = t * offset(t, n >> 1);
   if(n & 1) { // * (x + n - 1)
      t.push_back(0);
      for(int i = (int) t.size() - 1; i >= 0; i --) {
         t[i] = ((i ? t[i - 1] : 0) + t[i] * (n - 1ll)) % mod;
      }
   }
   return t;
}
int C(int x, int y) {
   return x < y ? 0 : 1ll * fac[x] * fav[y] % mod * fav[x - y] % mod;
}
int main() {
   scanf("%d%d%d", &n, &A, &B);
   if(A + B - 2 >= n) return puts("0");
   fac[0] = 1;
   for(int i = 1; i <= n; i ++) fac[i] = 1ll * fac[i - 1] * i % mod;
   fav[n] = qpow(fac[n], mod - 2);
   for(int i = n; i >= 1; i --) fav[i - 1] = 1ll * fav[i] * i % mod;
   poly S = solve(n - 1);
   printf("%d\n", 1ll * C(A + B - 2, A - 1) * S[A + B - 2] % mod);
   return 0;
}
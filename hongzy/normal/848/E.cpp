#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

typedef long long ll;
typedef vector<int> poly;

const int N = 131072 | 5, mod = 998244353;

int add(int x, int y) { return (x += y) >= mod ? x - mod : x; }
void ADD(int &x, int y) { (x += y) >= mod ? x -= mod : 0; }
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll)a * a % mod)
      if(b & 1) ans = (ll)ans * a % mod;
   return ans;
}

int rev[N], W[N];
int getn(int len) { int n = 1; while(n < len) n <<= 1; return n; } //[0, len - 1]
void prework(int n) {
   for(int i = 1; i < n; i <<= 1) {
      W[i] = 1;
      int w = qpow(3, (mod - 1) / (i << 1));
      for(int j = 1; j < i; j ++)
         W[i + j] = (ll)W[i + j - 1] * w % mod;
   }
}
void NTT(poly &a, int n, int op) {
   a.resize(n);
   for(int i = 1; i < n; i ++)
      if(i < (rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? n >> 1 : 0)))
         swap(a[i], a[rev[i]]);
   for(int i = 1; i < n; i <<= 1) {
      for(int j = 0; j < n; j += i << 1) {
         for(int k = 0; k < i; k ++) {
            int q = (ll)W[i + k] * a[j + k + i] % mod;
            a[j + k + i] = add(a[j + k], mod - q); ADD(a[j + k], q);
         }
      }
   }
   if(op == 1) return ;
   reverse(a.begin() + 1, a.end());
   int inv = mod - (mod - 1) / n;
   rep(i, 0, n - 1) a[i] = (ll)a[i] * inv % mod;
}
poly operator * (poly a, poly b) {
   int t = a.size() + b.size() - 1, n = getn(t);
   NTT(a, n, 1); NTT(b, n, 1);
   rep(i, 0, n - 1) a[i] = (ll)a[i] * b[i] % mod;
   NTT(a, n, -1); a.resize(t);
   return a;
}
poly fix(poly a, int n) { a.resize(n); return a; }
poly Inv(poly a) {
   int sz = a.size();
   poly c(1, qpow(a[0], mod - 2)), t;
   for(int i = 1; i < sz; i <<= 1) {
      NTT(t = fix(a, i << 1), i << 2, 1); NTT(c, i << 2, 1);
      for(int j = 0; j < (i << 2); j ++)
         c[j] = (2 * c[j] - (ll)t[j] * c[j] % mod * c[j] % mod + mod) % mod;
      NTT(c, i << 2, -1); c.resize(i << 1);
   }
   c.resize(sz);
   return c;
}
int main() {
   int n; scanf("%d", &n);
   const int m = max(n + 1, 32);
   poly a = {0, 0, 0, 24, 4, 144, mod - 4, 348, mod - 128, 240, 28, 188, mod - 68, 16, 0, 4};
   poly b = {1, 0, mod - 4, mod - 8, 1, mod - 16, 10, mod - 4, 12, 48, mod - 26, 44, mod - 15, 16, 4, 4, 1};
   a.resize(m); b.resize(m); prework(2 * m); a = a * Inv(b);
   printf("%d\n", a[n]);
   return 0;
}
#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

typedef long long ll;
typedef vector<int> poly;

const int N = 1 << 17 | 5, mod = 998244353;
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
            int q = 1ll * W[i + k] * a[j + k + i] % mod;
            a[j + k + i] = add(a[j + k], mod - q); ADD(a[j + k], q);
         }
      }
   }
   if(op == 1) return ;
   reverse(a.begin() + 1, a.end());
   int inv = mod - (mod - 1) / n;
   rep(i, 0, n - 1) a[i] = (ll)a[i] * inv % mod;
}
poly operator + (poly a, poly b) {
   if(a.size() < b.size()) a.resize(b.size());
   for(int i = 0; i < (int)b.size(); i ++) ADD(a[i], b[i]);
   return a;
}
poly fix(poly a, int n) { a.resize(n); return a; }
int n, k, st[64], t;
poly f[3], g[3];
poly shift(poly x) {
   poly y = {0};
   for(int v : x) y.push_back(v);
   return y;
}
void fmul() {
   int n = getn((k + 1) * 2);
   NTT(f[0], n, 1); NTT(f[1], n, 1); NTT(f[2], n, 1);
   for(int i = 0; i < n; i ++) {
      int w = i < (n >> 1) ? W[(n >> 1) | i] : mod - W[(n >> 1) | i];
      g[0][i] = ( (ll)f[0][i] * f[0][i] + (ll)w * f[1][i] % mod * f[1][i] ) % mod;
      g[1][i] = ( (ll)f[0][i] * f[1][i] + (ll)w * f[1][i] % mod * f[2][i] ) % mod;
      g[2][i] = ( (ll)f[1][i] * f[1][i] + (ll)w * f[2][i] % mod * f[2][i] ) % mod;
   }
   NTT(g[0], n, -1); NTT(g[1], n, -1); NTT(g[2], n, -1);
   rep(i, 0, 2) { f[i] = g[i]; f[i].resize(k + 1); }
}
void fadd() {
   poly t = f[0];
   f[0] = t + shift(t) + shift(f[1]);
   f[0].resize(k + 1);
   f[2] = f[1]; f[1] = t;
}
int main() {
   scanf("%d%d", &n, &k); prework((k + 1) * 2);
   f[0] = {1, 1}; f[1] = {1}; f[2] = {0};
   f[0].resize(k + 1); f[1].resize(k + 1); f[2].resize(k + 1);
   for(; n; n >>= 1) st[++ t] = n & 1;
   n = getn((k + 1) * 2); g[0].resize(n); g[1].resize(n); g[2].resize(n);
   for(int i = t - 1; i >= 1; i --) {
      fmul();
      if(st[i]) fadd();
   }
   for(int i = 1; i <= k; i ++) {
      printf("%d%c", f[0][i], " \n"[i == k]);
   }
   return 0;
}
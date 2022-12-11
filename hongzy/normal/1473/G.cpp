#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
typedef vector<int> poly;
const int N = 2e5 + 10, mod = 998244353, g = 3;
int add(int x, int y) { return (x += y) >= mod ? x - mod : x; }
int qpow(int a, int b) {
  int ans = 1;
  for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
    if(b & 1) ans = (ll) ans * a % mod;
  return ans;
}
int fac[N], fav[N]; 
int C(int n, int m) {
  return n < m || m < 0 ? 0 : 1ll * fac[n] * fav[m] % mod * fav[n - m] % mod;
}
void binom(int n) {
  fac[0] = 1;
  for(int i = 1; i <= n; i ++) fac[i] = 1ll * fac[i - 1] * i % mod;
  fav[n] = qpow(fac[n], mod - 2);
  for(int i = n; i >= 1; i --) fav[i - 1] = 1ll * fav[i] * i % mod;
}
int rev[N], W[N];
int getn(int len) { int n = 1; while(n < len) n <<= 1; return n; } //[0, len - 1]
void prework(int n) {
  for(int i = 1; i < n; i <<= 1) {
    W[i] = 1;
    int w = qpow(g, (mod - 1) / (i << 1));
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
        a[j + k + i] = add(a[j + k], mod - q);
        a[j + k] = add(a[j + k], q);
      }
    }
  }
  if(op == 1) return ;
  reverse(a.begin() + 1, a.end());
  int inv = mod - (mod - 1) / n;
  rep(i, 0, n - 1) a[i] = (ll)a[i] * inv % mod;
}
int main() {
  int n; scanf("%d", &n); prework(15 * n); binom(2e5);
  static int f[N];
  poly A, B;
  f[1] = 1;
  int s = 1;
  rep(i, 1, n) {
    int a, b;
    scanf("%d%d", &a, &b);
    int ns = s + a - b;
    int l = getn(s + (ns + s) + 1);
    A.resize(l); B.resize(l);
    rep(u, 0, l - 1) A[u] = u <= s ? f[u] : 0;
    rep(u, 0, l - 1) B[u] = u <= ns + s ? C(a + b, b + u - s) : 0;
    NTT(A, l, 1); NTT(B, l, 1);
    rep(u, 0, l - 1) A[u] = (ll)A[u] * B[u] % mod;
    NTT(A, l, -1);
    rep(u, 1, ns) f[u] = A[u + s];
    s = ns;
  }
  int x = 0;
  rep(i, 1, s) x = add(x, f[i]);
  printf("%d\n", x);
  return 0;
}
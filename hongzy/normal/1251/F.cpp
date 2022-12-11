#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

typedef long long ll;
typedef vector<int> poly;

const int N = 1 << 20 | 5, mod = 998244353;

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
int n, k, a[N], b[N], q, c, sz[N], pre1[N], pre2[N];
int fac[N], fav[N], pw[N]; 
int C(int n, int m) {
   return n < m ? 0 : 1ll * fac[n] * fav[m] % mod * fav[n - m] % mod;
}
void binom(int n) {
   fac[0] = 1;
   for(int i = 1; i <= n; i ++) fac[i] = 1ll * fac[i - 1] * i % mod;
   fav[n] = qpow(fac[n], mod - 2);
   for(int i = n; i >= 1; i --) fav[i - 1] = 1ll * fav[i] * i % mod;
   pw[0] = 1;
   rep(i, 1, n) pw[i] = add(pw[i - 1], pw[i - 1]);
}
int main() {
   scanf("%d%d", &n, &k);
   rep(i, 1, n) scanf("%d", a + i);
   c = *max_element(a + 1, a + n + 1);
   rep(i, 1, n) sz[a[i]] ++;
   rep(i, 1, c) {
      pre1[i] = pre1[i - 1] + (sz[i] == 1);
      pre2[i] = pre2[i - 1] + (sz[i] > 1);
   }
   rep(i, 0, k - 1) scanf("%d", b + i);
   poly F[5]; prework((n + 1) * 2);
   binom(n * 2);
   rep(u, 0, k - 1) {
      int p1 = pre1[min(c, b[u] - 1)];
      int p2 = pre2[min(c, b[u] - 1)];
      poly G(p1 + 1), H(2 * p2 + 1);
      rep(i, 0, p1) G[i] = (ll)pw[i] * C(p1, i) % mod;
      rep(i, 0, 2 * p2) H[i] = C(2 * p2, i);
      F[u] = G * H;
   }
   scanf("%d", &q);
   rep(i, 1, q) {
      int res = 0, x; scanf("%d", &x);
      rep(j, 0, k - 1) {
         int y = x / 2 - b[j] - 1;
         // cerr << "y = " << y << endl;
         if(y >= 0 && y < F[j].size()) {
            ADD(res, F[j][y]);
            // cerr << "F = " << F[j][y] << endl;
         }
      }
      printf("%d\n", res);
      // if(x == 8) return 0;
   }
   return 0;
}
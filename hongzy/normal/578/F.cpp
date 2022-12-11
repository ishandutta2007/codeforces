#include <bits/stdc++.h>
#define pb push_back
#define ID(x, y) (x) * (m + 1) + (y) + 1
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 405;
int n, m, mod;
char c[N][N];
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = 1ll * a * a % mod)
      if(b & 1) ans = 1ll * ans * a % mod;
   return ans;
}
struct ufs {
   int f[N * N], id[N * N];
   bool use[N * N];
   void init(int n) { rep(i, 1, n) f[i] = i; }
   int find(int u) { return u == f[u] ? u : f[u] = find(f[u]); }
   bool unite(int u, int v) { u = find(u); v = find(v); f[u] = v; return u != v; }
   int assign(int n) {
      int c = 0;
      rep(i, 1, n) if(use[i] && find(i) == i) id[i] = ++ c;
      return c;
   }
   int map(int u) { return id[f[u]]; }
} s[2];
struct matrix {
   int a[N][N];
   void add(int u, int v) {
      if((++ a[u][u]) == mod) a[u][u] = 0;
      if((++ a[v][v]) == mod) a[v][v] = 0;
      if((-- a[u][v]) < 0) a[u][v] += mod;
      if((-- a[v][u]) < 0) a[v][u] += mod;
   }
   int det(int n) {
      int ans = 1;
      rep(i, 2, n) {
         int k = i;
         rep(j, i, n) if(a[j][i]) k = j, j = n;
         if(k != i) {
            ans = mod - ans;
            rep(j, i, n) swap(a[i][j], a[k][j]);
         }
         if(!a[i][i]) return 0;
         ans = 1ll * ans * a[i][i] % mod;
         int inv = qpow(a[i][i], mod - 2);
         rep(j, i + 1, n) {
            int z = 1ll * inv * a[j][i] % mod;
            per(k, n, i) {
               a[j][k] = (a[j][k] - 1ll * a[i][k] * z % mod + mod) % mod;
            }
         }
      }
      return ans;
   }
} t[2];
int main() {
   scanf("%d%d%d", &n, &m, &mod);
   rep(i, 1, n) scanf("%s", c[i] + 1);
   const int tot = (n + 1) * (m + 1);
   s[0].init(tot); s[1].init(tot);
   rep(i, 1, n) rep(j, 1, m) {
      if(c[i][j] == '/') {
         if(!s[i + j - 1 & 1].unite(ID(i - 1, j), ID(i, j - 1))) {
            puts("0"); return 0;
         }
      }
      if(c[i][j] == '\\') {
         if(!s[i + j & 1].unite(ID(i - 1, j - 1), ID(i, j))) {
            puts("0"); return 0;
         }
      }
   }
   rep(i, 0, n) rep(j, 0, m) s[i + j & 1].use[ID(i, j)] = 1;
   int n1 = s[0].assign(tot), n2 = s[1].assign(tot);
   rep(i, 1, n) rep(j, 1, m) if(c[i][j] == '*') {
      t[i + j - 1 & 1].add(s[i + j - 1 & 1].map(ID(i - 1, j)), s[i + j - 1 & 1].map(ID(i, j - 1)));
      t[i + j & 1].add(s[i + j & 1].map(ID(i - 1, j - 1)), s[i + j & 1].map(ID(i, j)));
   }
   printf("%d\n", (t[0].det(n1) + t[1].det(n2)) % mod);
   return 0;
}
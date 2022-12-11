#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
#define debug(arr, pos) fprintf(stderr, "%s[%d] = %lld\n", #arr, pos, (long long) arr[pos])
#define debug2(arr, px, py) fprintf(stderr, "%s[%d][%d] = %lld\n", #arr, px, py, (long long) arr[px][py])
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, mod = 1e9 + 7;
int p[N], mu[N], phi[N], c, val[N];
bool tag[N];
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
void sieve(int n) {
   mu[1] = phi[1] = 1;
   rep(i, 2, n) {
      if(!tag[i]) { p[++ c] = i; phi[i] = i - 1; mu[i] = mod - 1; }
      rep(j, 1, c) {
         if(i * p[j] > n) break ;
         tag[i * p[j]] = 1;
         if(i % p[j] == 0) {
            phi[i * p[j]] = phi[i] * p[j];
            break ;
         }
         phi[i * p[j]] = phi[i] * (p[j] - 1);
         mu[i * p[j]] = mu[i] ? mod - mu[i] : 0;
      }
   }
   rep(i, 1, n) {
      int t = (ll) i * qpow(phi[i], mod - 2) % mod;
      for(int j = 1; i * j <= n; j ++) if(mu[j]) {
         val[i * j] = (val[i * j] + (ll) t * mu[j]) % mod;
      }
   }
}
int n, logn, top, st[N], dfn[N], f[N][21], d[N];
vector<int> G[N], T[N];
void dfs(int u, int p = 0) {
   dfn[u] = ++ *dfn; f[u][0] = p; d[u] = d[p] + 1;
   rep(i, 1, logn) {
      f[u][i] = f[f[u][i - 1]][i - 1];
      if(!f[u][i]) break ;
   }
   for(int v : G[u]) if(v ^ p) dfs(v, u);
}
int LCA(int u, int v) {
   if(d[u] < d[v]) swap(u, v);
   int c = d[u] - d[v];
   per(i, logn, 0) if(c >> i & 1) u = f[u][i];
   if(u == v) return v;
   per(i, logn, 0) if(f[u][i] ^ f[v][i]) u = f[u][i], v = f[v][i];
   return f[u][0];
}
int seq[N], s;
bool mark[N];
void clr(int u, int p = 0) {
   for(int v : T[u]) if(v ^ p) clr(v, u);
   T[u].clear(); mark[u] = 0;
}
void insert(int u) {
   if(top) {
      int x = LCA(st[top], u);
      if(x != st[top]) {
         while(dfn[st[top - 1]] > dfn[x]) {
            T[st[top - 1]].pb(st[top]);
            top --;
         }
         T[x].pb(st[top --]);
         if(x != st[top]) st[++ top] = x;
      }
   }
   st[++ top] = u;
}
int sum[N], cur;
void dfs2(int u, int fa = 0) {
   int s = mark[u] ? phi[u] : 0, s2 = 0;
   for(int v : T[u]) if(v ^ fa) {
      dfs2(v, u); (s += sum[v]) %= mod;
      s2 = (s2 - (ll) sum[v] * sum[v] % mod + mod) % mod;
   }
   sum[u] = s;
   cur = (cur + ( (ll) s * s % mod + s2) * d[u]) % mod;
}
int main() {
   scanf("%d", &n); sieve(n);
   for(logn = 1; (1 << logn) <= n; logn ++) ;
   logn --;
   static int map[N];
   rep(i, 1, n) scanf("%d", map + i);
   int u, v;
   rep(i, 1, n - 1) {
      scanf("%d%d", &u, &v);
      u = map[u]; v = map[v];
      G[u].pb(v); G[v].pb(u);
   }
   dfs(1);
   int ans = 0;
   rep(T, 1, n) if(val[T]) {
      s = 0;
      for(int i = T; i <= n; i += T) { seq[++ s] = i; mark[i] = 1; }
      sort(seq + 1, seq + s + 1, [&](int x, int y) { return dfn[x] < dfn[y]; });
      top = 0;
      if(seq[1] != 1) insert(1);
      rep(i, 1, s) insert(seq[i]);
      rep(i, 1, top - 1) ::T[st[i]].pb(st[i + 1]);

      cur = 0; dfs2(1); cur = cur * (mod - 2ll) % mod;
      int S_dp = 0, S_p = 0;
      for(int i = T; i <= n; i += T) {
         S_dp = (S_dp + (ll) d[i] * phi[i]) % mod;
         (S_p += phi[i]) %= mod;
      }
      for(int i = T; i <= n; i += T) {
         cur = (cur + phi[i] * ((ll) d[i] * S_p % mod + S_dp)) % mod;
      }
      ans = (ans + (ll) cur * val[T]) % mod;
      clr(1);
   }
   ans = (ll) ans * qpow(n * (n - 1ll) % mod, mod - 2) % mod;
   printf("%d\n", ans);
   return 0;
}
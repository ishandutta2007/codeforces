#include <algorithm>
#include <cstdio>
#include <vector>
#define fs first
#define sc second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;
const int N = 2e5 + 10;
int n, lgn, m, q, f[N][20], d[N], dfn[N], dr[N];
vector<int> G[N], R[N];
int lca(int u, int v) {
  if(d[u] < d[v]) swap(u, v);
  int c = d[u] - d[v], ans = 0;
  for(int i = lgn - 1; i >= 0; i --)
    if(c >> i & 1) u = f[u][i];
  if(u == v) return u;
  for(int i = lgn - 1; i >= 0; i --)
    if(f[u][i] ^ f[v][i]) {
      u = f[u][i]; v = f[v][i];
    }
  return f[u][0];
}
int low[N], top[N], lw[N][20], ans[N];
bool cov[N];
int Dmin(int u, int v) {
  if(!u || !v) return u | v;
  return d[u] < d[v] ? u : v;
}
void dfs(int u) {
  static int idx;
  int &fa = f[u][0];
  d[u] = d[fa] + 1; dfn[u] = ++ idx;
  for(int i = 1; i < lgn; i ++) {
    f[u][i] = f[f[u][i - 1]][i - 1];
    if(!f[u][i]) break ;
  }
  for(int v : G[u]) dfs(v);
  dr[u] = idx;
}
int bit[N];
void insert(int u) {
  for(; u <= n; u += u & (-u))
    bit[u] ++;
}
int qry(int u) {
  int ans = 0;
  for(; u >= 1; u &= u - 1)
    ans += bit[u];
  return ans;
}
int qry(int u, int v) {
  return qry(v) - qry(u - 1);
}
pair<int, int> solve(int u, int x) {
  if(d[top[u]] > d[x]) return pii(-1, -1);
  int ans = 0;
  for(int i = lgn - 1; i >= 0; i --) {
    if(d[lw[u][i]] > d[x]) {
      u = lw[u][i]; ans += 1 << i;
    }
  }
  return pii(u, ans);
}
vector<pii> Q[N];
int tmp[N];
void dfs2(int u) {
  for(pii qu : Q[u]) tmp[qu.sc] = qry(dfn[qu.fs], dr[qu.fs]);
  for(int v : R[u]) insert(dfn[v]);
  for(int v : G[u]) dfs2(v);
  for(pii qu : Q[u]) if(!cov[qu.sc] && tmp[qu.sc] != qry(dfn[qu.fs], dr[qu.fs])) cov[qu.sc] = 1;
}
int main() {
  scanf("%d", &n);
  for(lgn = 1; (1 << lgn) <= n; lgn ++) ;
  for(int i = 2; i <= n; i ++) {
    scanf("%d", &f[i][0]);
    G[f[i][0]].pb(i);
  }
  dfs(1);

  scanf("%d", &m);
  for(int u, v, i = 1; i <= m; i ++) {
    scanf("%d%d", &u, &v);
    R[u].pb(v); R[v].pb(u);
    int x = lca(u, v);
    if(u != x) low[u] = Dmin(low[u], x);
    if(v != x) low[v] = Dmin(low[v], x);
  }
  for(int i = n; i > 1; i --) {
    if(low[i] != f[i][0]) {
      low[f[i][0]] = Dmin(low[f[i][0]], low[i]);
    }
  }
  for(int i = 1; i <= n; i ++) {
    lw[i][0] = low[i];
    for(int j = 1; j < lgn; j ++) {
      lw[i][j] = lw[lw[i][j - 1]][j - 1];
      if(!lw[i][j]) break ;
    }
    top[i] = low[i] ? top[low[i]] : i;
  }

  scanf("%d", &q);
  for(int u, v, i = 1; i <= q; i ++) {
    scanf("%d%d", &u, &v);
    int x = lca(u, v);
    pii a = solve(u, x), b = solve(v, x);
    if(a.sc < 0 || b.sc < 0) ans[i] = -1;
    else {
      // printf("u = %d, v = %d, step = %d & %d\n", a.fs, b.fs, a.sc + 1, b.sc + 1);
      if(x == u || x == v) {
        ans[i] = max(a.sc, b.sc) + 1;
        continue ;
      }
      ans[i] = a.sc + b.sc + 2;
      Q[a.fs].pb(pii(b.fs, i));
      Q[b.fs].pb(pii(a.fs, i));
    }
  }
  dfs2(1);
  for(int i = 1; i <= q; i ++)
    printf("%d\n", ans[i] < 0 ? -1 : ans[i] - (int) cov[i]);
  return 0;
}
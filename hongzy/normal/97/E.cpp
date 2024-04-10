#include <algorithm>
#include <cstdio>
#include <vector>
#define fs first
#define sc second
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 10;
int n, lgn, m, q, f[N][20], d[N], cov[N], b, bel[N];
vector<int> G[N], T[N];
int lca(int u, int v) {
  if(d[u] < d[v]) swap(u, v);
  int c = d[u] - d[v];
  for(int i = lgn - 1; ~ i; i --)
    if(c >> i & 1) u = f[u][i];
  if(u == v) return u;
  for(int i = lgn - 1; ~ i; i --)
    if(f[u][i] ^ f[v][i]) {
      u = f[u][i]; v = f[v][i];
    }
  return f[u][0];
}
void dfs(int u, int fa = 0) {
  d[u] = d[fa] + 1; f[u][0] = fa; bel[u] = b;
  for(int i = 1; i < lgn; i ++) {
    f[u][i] = f[f[u][i - 1]][i - 1];
    if(!f[u][i]) break ;
  }
  for(int v : G[u]) if(!bel[v]) {
    dfs(v, u); T[u].push_back(v);
  }
}
pii stk[N];
int top, low[N], dfn[N], idx;
void tarjan(int u, int fa = 0) {
  low[u] = dfn[u] = ++ idx;
  for(int v : G[u]) {
    if(!dfn[v]) {
      stk[++ top] = pii(u, v);
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if(low[v] >= dfn[u]) {
        int tu = 0, tv = 0, ttop = top; bool tag = 0;
        do {
          tu = stk[top].fs; tv = stk[top].sc; top --;
          if((d[tu] + d[tv]) % 2 == 0) {
            tag = 1; break ;
          }
        } while(!(tu == u && tv == v));
        if(tag) {
          top = ttop;
          do {
            tu = stk[top].fs; tv = stk[top].sc; top --;
            cov[tu] = cov[tv] = 1;
          } while(!(tu == u && tv == v));
          cov[u] = 0;
        }
      }
    } else if(dfn[v] < dfn[u] && v != fa) {
      stk[++ top] = pii(v, u);
      low[u] = min(low[u], dfn[v]);
    }
  }
}
void dfs2(int u, int fa = 0) {
  cov[u] += cov[fa];
  for(int v : T[u]) dfs2(v, u);
}
int main() {
  scanf("%d%d", &n, &m);
  for(lgn = 1; (1 << lgn) <= n; lgn ++) ;
  for(int i = 1; i <= m; i ++) {
    int u, v; scanf("%d%d", &u, &v);
    G[u].push_back(v); G[v].push_back(u);
  }
  static bool root[N];
  for(int i = 1; i <= n; i ++)
    if(!bel[i]) b ++, root[i] = 1, dfs(i);
  for(int i = 1; i <= n; i ++)
    if(!dfn[i]) tarjan(i);
  for(int i = 1; i <= n; i ++)
    if(root[i]) dfs2(i);
  scanf("%d", &q);
  while(q --) {
    int u, v;
    scanf("%d%d", &u, &v);
    bool tag = 0;
    if(bel[u] ^ bel[v]) tag = 0;
    else if((d[u] ^ d[v]) & 1) tag = 1;
    else tag = cov[u] + cov[v] - 2 * cov[lca(u, v)] > 0;
    puts(tag ? "Yes" : "No");
  }
  return 0;
}
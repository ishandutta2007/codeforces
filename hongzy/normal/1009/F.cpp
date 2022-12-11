#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define pb push_back

const int N = 1e6 + 10;

int n, ans[N], son[N], d[N];
vector<int> G[N];
void dfs(int u, int fa = 0) {
  for(int v : G[u]) if(v != fa) {
    dfs(v, u);
    if(d[v] > d[son[u]])
      son[u] = v;
  }
  d[u] = d[son[u]] + 1;
}
int p[N], id, f[N];
void dfs2(int u, int fa = 0) {
  if(!son[u]) {
    p[u] = id --;
    f[p[u]] = 1;
    ans[u] = 0;
    return ;
  }
  for(int v : G[u]) if(v != fa && v != son[u]) dfs2(v, u);
  dfs2(son[u], u);
  p[u] = id --;
  f[p[u]] = 1;
  ans[u] = ans[son[u]] + 1;
  if(f[p[u]] >= f[p[u] + ans[u]])
    ans[u] = 0;
  for(int v : G[u]) if(v != fa && v != son[u]) {
    rep(x, 1, d[v]) {
      f[p[u] + x] += f[p[v] + x - 1];
      if(f[p[u] + x] > f[p[u] + ans[u]] || (f[p[u] + x] == f[p[u] + ans[u]] && ans[u] > x))
        ans[u] = x;
    }
  }
}
int main() {
  scanf("%d", &n);
  int u, v;
  rep(i, 1, n - 1) {
    scanf("%d%d", &u, &v);
    G[u].pb(v);
    G[v].pb(u);
  }
  dfs(1); id = n; dfs2(1);
  rep(i, 1, n)
    printf("%d\n", ans[i]);
  return 0;
}
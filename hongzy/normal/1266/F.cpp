#include <bits/stdc++.h>
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define node pair<int, int>
#define LOG printf
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
#define cmax(a, b) a = max(a, b)
using namespace std;
const int N = 5e5 + 10;
int n, p[N], w[N], mx[N], mx2[N], ans[N];
vector<int> G[N];
void dfs(int u, int fa = 0) {
  p[u] = fa;
  for(int v : G[u]) if(v != fa) dfs(v, u), cmax(mx[u], 1 + mx[v]);
}
void dfs2(int u, int fa = 0) {
  int h = mx2[u];
  for(int v : G[u]) if(v != fa) cmax(mx2[v], 1 + h), cmax(h, 1 + mx[v]);
  reverse(G[u].begin(), G[u].end()); h = 0;
  for(int v : G[u]) if(v != fa) cmax(mx2[v], 1 + h), cmax(h, 1 + mx[v]), dfs2(v, u);
}

int main() {
  scanf("%d", &n);
  int u, v;
  rep(i, 1, n - 1) scanf("%d%d", &u, &v), G[u].pb(v), G[v].pb(u);
  rep(i, 1, n) ans[i] = 1;
  dfs(1); dfs2(1);
  vector<node> vec;
  vector<int> ve;
  rep(u, 1, n) {
    ve.clear();
    for(int v : G[u]) ve.pb(p[v] == u ? mx[v] + 1 : mx2[u]);
    sort(ve.begin(), ve.end(), greater<int>());
    int sz = int(ve.size());
    for(int i = 0; i < sz; i ++) {
      cmax(ans[2 * ve[i]], i + 1);
      cmax(ans[2 * ve[i] - 1], i + 1);
      if(i < sz - 1 && ve[i + 1] < ve[i])
        cmax(ans[2 * ve[i + 1] + 1], i + 2);
    }
  }
  rep(u, 1, n) {
    static int c[N];
    vec.clear(); c[u] = 0;
    for(int v : G[u]) vec.pb(mp(p[v] == u ? mx[v] + 1 : mx2[u], u));
    for(int v : G[u]) if(p[v] == u) {
      c[v] = 0;
      for(int w : G[v])
        vec.pb(mp(p[w] == v ? mx[w] + 1 : mx2[v], v));
    }
    sort(vec.begin(), vec.end(), greater<node>());
    int mx = 0;
    for(node cur : vec) {
      ++ c[cur.sc];
      if(cur.sc != u) mx = max(mx, c[cur.sc]);
      if(mx && c[u]) cmax(ans[2 * cur.fs], mx + c[u] - 2);
    }
  }
  per(i, n, 1) cmax(ans[i], ans[i + 2]);
  rep(i, 1, n) cmax(ans[1], int(G[i].size()) + 1);
  rep(i, 1, n) printf("%d%c", ans[i], " \n"[i == n]);
  return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
struct edge {
  int u, v, w;
} e[N];
int n, m, deg[N];
vector<int> adj[N];
ll ans;
bool query(int u, int v) {
  return binary_search(adj[u].begin(), adj[u].end(), v);
}
struct ufs {
  int f[N];
  void init(int n) { rep(i, 1, n) f[i] = i; }
  int find(int u) { return u == f[u] ? u : f[u] = find(f[u]); }
  bool unite(int u, int v) {
    u = find(u); v = find(v);
    // if(u != v) printf("%d & %d\n", u, v);
    return u == v ? 0 : (f[u] = v, 1);
  }
} a, b;

int main() {
  scanf("%d%d", &n, &m);
  rep(i, 1, n) deg[i] = n - 1;
  int _xor = 0;
  rep(i, 1, m) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    e[i] = {u, v, w};
    -- deg[u];
    -- deg[v];
    adj[u].pb(v);
    adj[v].pb(u);
    _xor ^= w;
  }
  sort(e + 1, e + m + 1, [&](edge e1, edge e2) {
    return e1.w < e2.w;
  });
  rep(i, 1, n) sort(adj[i].begin(), adj[i].end());
  int rt = 0;
  rep(i, 1, n) if(deg[i] > deg[rt]) rt = i;
  a.init(n);
  bool bo = 0;
  rep(i, 1, n)
    if(rt != i && !query(rt, i))
      a.unite(rt, i);
  static bool vis[N];
  rep(i, 1, n) if(a.find(i) == a.find(rt)) vis[i] = 1;
  rep(i, 1, n) if(!vis[i])
    rep(j, 1, n) if(!query(i, j)) a.unite(i, j);
  vector< vector<int> > vec(n + 1);
  rep(i, 1, n) vec[a.find(i)].pb(i);
  rep(i, 1, n) {
    const int sz = vec[i].size();
    if(!sz) continue ;
    int cnt = 0;
    rep(j, 0, sz - 1) rep(k, j + 1, sz - 1) {
      if(!query(vec[i][j], vec[i][k])) {
        cnt ++;
        if(cnt >= sz) break ;
      }
      if(cnt >= sz) break ;
    }
    if(cnt >= sz) { bo = 1; break; }
  }
  if(bo) {
    rep(i, 1, m)
      if(a.unite(e[i].u, e[i].v))
        ans += e[i].w;
  } else {
    b.init(n);
    int mn = _xor;
    rep(i, 1, m)
      if(a.unite(e[i].u, e[i].v)) {
        ans += e[i].w;
        b.unite(e[i].u, e[i].v);
      } else if(b.find(e[i].u) != b.find(e[i].v)) {
        mn = min(mn, e[i].w);
      }
    ans += mn;
  }
  printf("%lld\n", ans);
  return 0;
}
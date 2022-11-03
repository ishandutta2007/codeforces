#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

namespace NetWork {
  static const int V = 205, E = 2e4;
  struct edge {
    int nxt, to;
    int cap;
  } e[E];
  int fir[V], dis[V], lst[V], vs[V];
  static int cnt = 1;
  
  inline void addedge(int x, int y, int c) {
    e[++ cnt] = (edge) { fir[x], y, (int)c }; fir[x] = cnt;
    e[++ cnt] = (edge) { fir[y], x, 0 }; fir[y] = cnt;
  }
  inline int Bfs(int S, int T) {
    memset(dis, -1, sizeof dis);
    dis[S] = 0;
    queue <int> Q;
    Q.push(S);
    int x;
    while (!Q.empty()) {
      x = Q.front(); Q.pop();
      for (int i = fir[x]; i; i = e[i].nxt)
        if (e[i].cap && dis[e[i].to] == -1) {
          Q.push(e[i].to);
          dis[e[i].to] = dis[x] + 1;
        }
    }
    if (dis[T] != -1) memcpy(lst, fir, sizeof fir);
    return dis[T];
  }
  inline int Dfs(int x, int T, int flow) {
    if (x == T) return flow;
    vs[x] = 1;
    int res = 0, t;
    for (int &i = lst[x]; i; i = e[i].nxt)
      if (e[i].cap && !vs[e[i].to] && dis[e[i].to] > dis[x]) {
        t = Dfs(e[i].to, T, min(flow, e[i].cap));
        flow -= t; res += t;
        e[i].cap -= t; e[i ^ 1].cap += t;
        if (!flow) break;
      }
    vs[x] = 0;
    return res;
  }
  inline int Dinic(int S, int T) {
    int r = 0;
    for (int i = 2; i <= cnt; e[i ^ 1].cap = 0, i += 2)
      e[i].cap += e[i ^ 1].cap;
    while (Bfs(S, T) != -1) r += Dfs(S, T, (int)2e9);
    return r;
  }
}
using namespace NetWork;

int id[V], tmp[V];
int vis[V], cur = 0, ans = 0;
int u[V], v[V], len[V], use[V], bel[V], t = 0;
vector <int> perm[V];

inline void dfs(int x) {
  vis[x] = cur;
  for (int i = fir[x]; i; i = e[i].nxt)
    if (e[i].cap && vis[e[i].to] != cur) dfs(e[i].to);
}

inline void Build(int l, int r) {
  if (l >= r) return;
  int S = id[l], T = id[l + 1], V = Dinic(S, T);
  cur ++; dfs(S);
  int p = l, q = r;
  for (int i = l; i <= r; i ++) {
    if (vis[id[i]] == cur) tmp[p ++] = id[i];
    else tmp[q --] = id[i];
  }
  ans += V;
  u[++ t] = S;
  v[t] = T; len[t] = V;
  cerr << S << " " << T <<  " " << V << endl;
  for (int i = l; i <= r; i ++) id[i] = tmp[i];
  Build(l, p - 1);
  Build(q + 1, r);
}

int main() {
  int n, m, x, y, c;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i ++) id[i] = i;
  for (int i = 1; i <= m; i ++) {
    scanf("%d%d%d", &x, &y, &c);
    addedge(x, y, c); addedge(y, x, c);
  }
  Build(1, n);
  printf("%d\n", ans);
  for (int i = 1; i <= n; i ++) bel[i] = i, perm[i].push_back(i);
  for (int i = 1; i < n; i ++) {
    int ID = 0, S, T;
    for (int j = 1; j < n; j ++)
      if (!use[j] && len[j] > len[ID]) ID = j;
    use[ID] = 1;
    S = bel[u[ID]];
    T = bel[v[ID]];
    for (vector <int> :: iterator it = perm[S].begin(); it != perm[S].end(); it ++)
      perm[T].push_back(*it), bel[*it] = T;
  }
  for (vector <int> :: iterator i = perm[bel[1]].begin(); i != perm[bel[1]].end(); i ++)
    printf("%d ", *i);
  puts("");
  return 0;
}
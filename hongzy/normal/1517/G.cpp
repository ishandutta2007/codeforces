#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2048;
const int M = N * 16;
const ll INF = 1e17;
namespace net {
 
struct Edge {
  int v, nxt; ll c, f;
} e[M];
int hd[N], cur[N], n, ec, d[N], s, t;
void clr(int sz, int ss, int tt) {
  s = ss; t = tt; n = sz; fill(hd, hd + n + 1, -1); ec = 0;
}
void add(int u, int v, ll c) {
  // printf("%d -> %d (%lld)\n", u, v, c);
  e[ec] = {v, hd[u], c, 0}; hd[u] = ec ++;
  e[ec] = {u, hd[v], 0, 0}; hd[v] = ec ++;
}
bool bfs() {
  fill(d, d + n + 1, -1);
  queue<int> q; q.push(s); d[s] = 0;
  while(q.size()) {
    int u = q.front(); q.pop();
    for(int i = hd[u]; ~i; i = e[i].nxt) {
      Edge &e = net::e[i];
      if(e.f < e.c && !~d[e.v]) {
        d[e.v] = d[u] + 1;
        q.push(e.v);
      }
    }
  }
  return ~d[t];
}
ll dfs(int u, ll a) {
  if(u == t || a == 0) return a;
  ll ans = 0, f;
  for(int &i = cur[u]; ~i; i = e[i].nxt) {
    Edge &e = net::e[i];
    if(d[e.v] == d[u] + 1 && (f = dfs(e.v, min(a, e.c - e.f))) > 0) {
      net::e[i].f += f; net::e[i ^ 1].f -= f; ans += f;
      if(!(a -= f)) break ;
    }
  }
  return ans;
}
ll dinic() {
  ll ans = 0;
  while(bfs()) {
    copy(hd, hd + n + 1, cur);
    ans += dfs(s, INF);
  }
  return ans;
}
 
}
int n, ty[2][2], x[N], y[N], w[N];
map<pii, int> ID;
int main() {
  ty[0][0] = 1; ty[0][1] = 0; ty[1][0] = 2; ty[1][1] = 3;
  scanf("%d", &n);
  net::clr(2 * n + 2, 2 * n + 1, 2 * n + 2); // 2->1->0->3
  ll s = 0;
  rep(i, 1, n) {
    scanf("%d%d%d", x + i, y + i, w + i);
    ID[pii(x[i], y[i])] = i;
    s += w[i];
  }
  int v;
  rep(i, 1, n) {
    net::add(i, n + i, w[i]);
    int t = ty[x[i] & 1][y[i] & 1];
    if(t == 0) {
      if(v = ID[pii(x[i] - 1, y[i])], v) net::add(n + i, v, INF);
      if(v = ID[pii(x[i] + 1, y[i])], v) net::add(n + i, v, INF);
    }
    if(t == 1) {
      if(v = ID[pii(x[i], y[i] - 1)], v) net::add(n + i, v, INF);
      if(v = ID[pii(x[i], y[i] + 1)], v) net::add(n + i, v, INF);
    }
    if(t == 2) {
      net::add(2 * n + 1, i, INF);
      if(v = ID[pii(x[i] - 1, y[i])], v) net::add(n + i, v, INF);
      if(v = ID[pii(x[i] + 1, y[i])], v) net::add(n + i, v, INF);
    }
    if(t == 3) {
      net::add(n + i, 2 * n + 2, INF);
    }
  }
  printf("%lld\n", s - net::dinic());
  return 0;
}
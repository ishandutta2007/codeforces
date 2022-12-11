#include <bits/stdc++.h>
#define pb push_back
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
char gc() {
  // return getchar();
  static char buf[1 << 17], *S, *T;
  if(S == T) T = (S = buf) + fread(buf, 1, 1 << 17, stdin);
  return S == T ? EOF : *S ++;
}
template<class T> void read(T &x) {
  x = 0; char c = gc(); bool na = 0;
  for(; c < '0' || c > '9'; c = gc()) na |= c == '-';
  for(; c >= '0' && c <= '9'; c = gc()) x = x * 10 + (c & 15);
  if(na) x = -x;
}
const int N = 1e5 + 10;
const ll INF = 1e17;
int n, m, q, vis[N];
ll dis[N], f[N], W[N];
struct Node {
  int u; ll d;
  bool operator < (const Node &b) const { return d > b.d; }
};
struct Edge { int v, id; };
vector<Edge> G[N];
queue<int> vec[N];
void Dijkstra(int s, int n) {
  fill(dis + 1, dis + n + 1, INF);
  priority_queue<Node> pq; pq.push({s, dis[s] = 0});
  while(pq.size()) {
    int u = pq.top().u; ll d = pq.top().d; pq.pop();
    if(dis[u] < d) continue ;
    for(auto &e : G[u]) if(dis[e.v] > d + W[e.id]) {
      dis[e.v] = d + W[e.id]; pq.push({e.v, dis[e.v]});
    }
  }
}
int main() {
  read(n); read(m); read(q);
  int u, v, w, c, op;
  rep(i, 1, m) {
    read(u); read(v); read(w);
    G[u].pb({v, i}); W[i] = w;
  }
  Dijkstra(1, n);
  rep(i, 1, q) {
    read(op); read(c);
    if(op == 1) { printf("%lld\n", dis[c] < INF ? dis[c] : -1); continue ; }
    rep(j, 1, c) { read(v); W[v] ++; }
    vec[0].push(1);
    fill(f + 2, f + n + 1, INF);
    rep(j, 0, c) {
      while(vec[j].size()) {
        int u = vec[j].front(); vec[j].pop();
        if(vis[u] == i) continue ;
        vis[u] = i;
        for(auto &e : G[u]) {
          ll t = dis[u] + f[u] + W[e.id] - dis[e.v];
          if(f[e.v] > t && t <= c) vec[f[e.v] = t].push(e.v);
        }
      }
    }
    rep(j, 1, n) if(dis[j] < INF) dis[j] += f[j];
  }
  return 0;
}
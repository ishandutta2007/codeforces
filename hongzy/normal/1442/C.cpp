#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;

const int N = 4e5 + 10;
const int mod = 998244353;

int qpow(int a, int b) {
  int ans = 1;
  for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
    if(b & 1) ans = (ll) ans * a % mod;
  return ans;
}
struct node {
  int c, u;
};
int n, m, f[20][N];
pii g[N];
vector<int> G[N], F[N];
struct Node {
  int u; pii d;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};
pii dis[2][N];
void Dijkstra() {
  rep(i, 0, 1)
    fill(dis[i] + 1, dis[i] + n + 1, pii(1e9, 1e9));
  priority_queue<Node> pq;
  pq.push({1, dis[0][1] = pii(0, 0)});
  pq.push({n + 1, dis[1][1] = pii(1, 0)});
  while(pq.size()) {
    int _u = pq.top().u; pii d = pq.top().d; pq.pop();
    int r = _u > n, u = _u <= n ? _u : _u - n;
    if(dis[r][u] < d) continue ;
    if(r == 0) {
      for(int v : G[u]) if(dis[0][v] > pii(d.fs, d.sc + 1)) {
        dis[0][v] = pii(d.fs, d.sc + 1);
        pq.push({v, dis[0][v]});
      }
      for(int v : F[u]) if(dis[1][v] > pii(d.fs + 1, d.sc + 1)) {
        dis[1][v] = pii(d.fs + 1, d.sc + 1);
        pq.push({v + n, dis[1][v]});
      }
    } else {
      for(int v : F[u]) if(dis[1][v] > pii(d.fs, d.sc + 1)) {
        dis[1][v] = pii(d.fs, d.sc + 1);
        pq.push({v + n, dis[1][v]});
      }
      for(int v : G[u]) if(dis[0][v] > pii(d.fs + 1, d.sc + 1)) {
        dis[0][v] = pii(d.fs + 1, d.sc + 1);
        pq.push({v, dis[0][v]});
      }
    }
  }
  // printf("%d %d")
  dis[0][n] = min(dis[0][n], dis[1][n]);
  int res = ((ll)qpow(2, dis[0][n].fs) + mod - 1ll + dis[0][n].sc) % mod;
  printf("%d\n", res);
}
int main() {
  scanf("%d%d", &n, &m);
  rep(i, 1, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].pb(v);
    F[v].pb(u);
  }
  rep(i, 0, 18) rep(u, 1, n) f[i][u] = -1;
  deque<node> q; q.push_back({0, 1}); f[0][1] = 0;
  while(q.size()) {
    auto k = q.front(); q.pop_front();
    if(k.c == 18) continue ;
    if(-1 == f[k.c + 1][k.u]) {
      f[k.c + 1][k.u] = f[k.c][k.u];
      q.push_front({k.c + 1, k.u});
    }
    if(k.c % 2 == 0) {
      for(int v : G[k.u]) {
        if(-1 == f[k.c][v]) {
          f[k.c][v] = f[k.c][k.u] + 1;
          q.push_back({k.c, v});
        }
      }
    } else {
      for(int v : F[k.u]) {
        if(-1 == f[k.c][v]) {
          f[k.c][v] = f[k.c][k.u] + 1;
          q.push_back({k.c, v});
        }
      }
    }
  }
  ll ans = 1ll << 62;
  rep(i, 0, 18) if(~f[i][n]) ans = min(ans, f[i][n] + (1ll << i) - 1);
  if(ans < (1ll << 62)) {
    printf("%d\n", int(ans % mod));
    return 0;
  }
  Dijkstra();
  return 0;
}
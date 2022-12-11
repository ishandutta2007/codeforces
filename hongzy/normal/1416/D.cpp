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
mt19937 mt(std::chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() { ios::sync_with_stdio(0); cin.tie(0); }
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 1e6 + 10;
const int mod = 1e9 + 7;
struct edge { int u, v, w; } e[N];
int n, m, q, id, p[N], sw[N], pos[N], qu[N], qe[N], f[N], w[N];
int find(int u) {
  return u == f[u] ? u : f[u] = find(f[u]);
}
int F[N][20], dl[N], dr[N], idx;
vector<int> G[N];
void dfs(int u, int fa = 0) {
  F[u][0] = fa; dl[u] = ++ idx; sw[idx] = p[u];
  rep(i, 1, 19) {
    F[u][i] = F[F[u][i - 1]][i - 1];
    if(!F[u][i]) break ;
  }
  for(int v : G[u]) {
    // printf("%d -> %d\n", u, v);
    dfs(v, u);
  }
  dr[u] = idx;
}
template<class T>
struct SMT {
  T w[N * 4];
  void up(int u) {
    w[u] = max(w[u << 1], w[u << 1 | 1]);
  }
  void build(int u, int l, int r) {
    if(l == r) { w[u] = sw[l]; return ; }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    up(u);
  }
  void del(int u, int l, int r, int p) {
    if(l == r) { w[u] = 0; return ; }
    int mid = (l + r) >> 1;
    p <= mid ? del(u << 1, l, mid, p) : del(u << 1 | 1, mid + 1, r, p);
    up(u);
  }
  T query(int u, int l, int r, int ql, int qr) {
    if(l == ql && r == qr) return w[u];
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(u << 1, l, mid, ql, qr);
    if(ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
    return max(query(u << 1, l, mid, ql, mid), query(u << 1 | 1, mid + 1, r, mid + 1, qr));
  }
};
SMT<int> seg;
int jump(int u, int lim) {
  per(i, 19, 0) if(F[u][i] && w[F[u][i]] > lim) {
    u = F[u][i];
  }
  return u;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  rep(i, 1, n) scanf("%d", p + i), pos[p[i]] = i;
  rep(i, 1, m) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[i] = {x, y, q + 1};
  }
  int op, v;
  rep(i, 1, q) {
    scanf("%d%d", &op, &v);
    if(op == 1) {
      qu[i] = v;
    } else {
      qu[i] = -1;
      qe[i] = v;
      e[v].w = i;
    }
  }
  rep(i, 1, n) f[i] = i;
  id = n;
  rep(i, 1, m) {
    if(e[i].w == q + 1) {
      int u = find(e[i].u), v = find(e[i].v);
      if(u == v) continue ;
      id ++; f[id] = id;
      f[u] = f[v] = id;
      G[id].pb(u); G[id].pb(v); w[id] = q + 1;
    }
  }
  per(i, q, 1) {
    if(qu[i] == -1) {
      int num = qe[i];
      int u = find(e[num].u), v = find(e[num].v);
      if(u == v) continue ;
      id ++; f[id] = id;
      f[u] = f[v] = id; G[id].pb(u); G[id].pb(v); w[id] = i;
    }
  }
  rep(i, 1, id) if(f[i] == i) {
    G[id + 1].pb(i);
  }
  w[++ id] = 0; dfs(id);
  seg.build(1, 1, id);
  rep(i, 1, q) {
    if(~qu[i]) {
      int u = qu[i], v = jump(u, i);
      int x = seg.query(1, 1, id, dl[v], dr[v]);
      printf("%d\n", x);
      if(x) {
        seg.del(1, 1, id, dl[pos[x]]);
        pos[x] = 0;
      }
    }
  }
  return 0;
}
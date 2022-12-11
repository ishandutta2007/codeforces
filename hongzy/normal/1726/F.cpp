#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 mt(std::chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() { ios::sync_with_stdio(0); cin.tie(0); }
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 2e5*5 + 10;
const int M = 2e5*4*4 + 10;
const int mod = 1e9 + 7;
const ll INF = 1e17;

struct Edge { int v; ll w; };
struct Graph {
  vector<Edge> G[N];
  void add(int u, int v, ll w) { G[u].pb({v, w}); }
  struct Node {
    int u; ll d;
    bool operator < (const Node &b) const {
      return d > b.d;
    }
  };
  ll dis[N];
  ll dijkstra(int s, int t) {
    fill(dis + 1, dis + t + 1, INF);
    priority_queue<Node> pq; pq.push({s, dis[s] = 0});
    while(pq.size()) {
      int u = pq.top().u; ll d = pq.top().d; pq.pop();
      if(dis[u] < d) continue ;
      for(auto e : G[u]) if(dis[e.v] > d + e.w) {
        dis[e.v] = d + e.w; pq.push({e.v, dis[e.v]});
      }
    }
    return dis[t];
  }
} G;
int n, m;
ll g[N], t, c[N], a[N], d[N];
int tag[M];
void down(int u) {
  if(tag[u]) {
    tag[u << 1] = tag[u << 1 | 1] = tag[u];
    tag[u] = 0;
  }
}
void modify(int u, int l, int r, int ql, int qr, int c) {
  if(l == ql && r == qr) {
    tag[u] = c;
    return ;
  }
  down(u);
  int mid = (l + r) >> 1;
  if(qr <= mid) modify(u << 1, l, mid, ql, qr, c);
  else if(ql > mid) modify(u << 1 | 1, mid + 1, r, ql, qr, c);
  else {
    modify(u << 1, l, mid, ql, mid, c);
    modify(u << 1 | 1, mid + 1, r, mid + 1, qr, c);
  }
}
int query(int u, int l, int r, int p) {
  if(l == r) return tag[u];
  down(u);
  int mid = (l + r) >> 1;
  if(p <= mid) return query(u << 1, l, mid, p);
  return query(u << 1 | 1, mid + 1, r, p);
}
vector<ll> num;
int ss, tt;
ll time_to(int cur, int id) {
  int p = a[id] == m ? 1 : a[id]+1;
  // printf("%d to %d = %d\n", cur, id, (num[p-1] + t - cur) % t);
  return (num[p-1] + t - cur) % t;
}
void build(int u, int l, int r) {
  if(l == r) {
    G.add(ss, l, 0);
    if(tag[u]) {
      if(tag[u] == n + 1)
        G.add(l, tt, 0);
      else
        G.add(l, m+tag[u], time_to(num[l-1], tag[u]));
    }
    return ;
  }
  down(u);
  int mid = (l + r) >> 1;
  build(u << 1, l, mid);
  build(u << 1 | 1, mid + 1, r);
}
int main() {
  scanf("%d%lld", &n, &t);
  rep(i, 1, n)
    scanf("%lld%lld", g + i, c + i);
  rep(i, 1, n - 1) scanf("%lld", d + i);
  num.pb(0); num.pb(t-1);
  rep(i, 1, n) {
    d[i] += d[i-1];
    ll len = t - g[i];
    c[i] = ((g[i] - c[i] - d[i-1]) % t + t) % t;

    num.pb((c[i]-1 + t) % t);
    num.pb(c[i]);
    ll r = c[i] + len - 1;
    if(r >= t) r -= t;
    a[i] = r;
    num.pb(r);
    num.pb((r+1) % t);
    // printf("[%lld,%lld]\n", c[i], a[i]);
  }
  // rep(i, 0, t-1) num.pb(i);
  sort(num.begin(), num.end());
  auto it = unique(num.begin(), num.end());
  m = it - num.begin();
  ss = m + n + 1, tt = m + n + 2;
  rep(i, 1, n) {
    c[i] = lower_bound(num.begin(), it, c[i]) - num.begin() + 1;
    a[i] = lower_bound(num.begin(), it, a[i]) - num.begin() + 1;
    // printf("[%lld,%lld]\n", c[i], a[i]);
    // assert(c[i] <= m && a[i] <= m);
  }
  // printf("m = %d, n = %d\n", m, n);
  tag[1] = n + 1;
  per(i, n, 1) {
    // printf("i = %d\n", i);
    int p = a[i] == m ? 1 : a[i]+1;
    int id = query(1, 1, m, p);
    if(id == n + 1) G.add(m+i, tt, 0);
    else G.add(m+i, m+id, time_to(num[p-1], id));
    if(c[i] <= a[i])
      modify(1, 1, m, c[i], a[i], i);
    else
      modify(1, 1, m, c[i], m, i),
      modify(1, 1, m, 1, a[i], i);
  }
  // puts("ow");
  build(1, 1, m);
  ll res = G.dijkstra(ss, tt) + d[n-1];
  printf("%lld\n", res);
  return 0;
}
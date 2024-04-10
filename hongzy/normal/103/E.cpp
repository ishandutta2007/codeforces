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

const int N = 4e5 + 10;
const int mod = 1e9 + 7;


namespace net {

const ll INF = 1e18;
const int N = 1000 + 5;
const int M = 10000 + 5;
struct Edge {
  int v, nxt;
  ll c, f;
} e[M * 2];
int hd[N], cur[N], n, ec, s, t;
int d[N];
void init(int _n) {
  n = _n;
  fill(hd, hd + n + 1, -1);
  ec = 0;
}
void add(int u, int v, ll c) {
  e[ec] = {v, hd[u], c, 0}; hd[u] = ec ++;
  e[ec] = {u, hd[v], 0, 0}; hd[v] = ec ++;
}
bool bfs() {
  fill(d, d + n + 1, -1);
  queue<int> q; q.push(t); d[t] = N;
  while(q.size()) {
    int u = q.front(); q.pop();
    for(int i = hd[u]; ~i; i = e[i].nxt) {
      int v = e[i].v;
      if(e[i ^ 1].f < e[i ^ 1].c && !~d[v]) {
        d[v] = d[u] - 1;
        q.push(v);
        if(v == s) return ~d[s];
      }
    }
  }
  return ~d[s];
}
ll dfs(int u, ll a) {
  if(u == t || !a) return a;
  ll ans = 0, f;
  for(int &i = cur[u]; ~i; i = e[i].nxt) {
    Edge &p = e[i];
    if(d[p.v] == d[u] + 1 && (f = dfs(p.v, min(a, p.c - p.f))) > 0) {
      e[i].f += f;
      e[i ^ 1].f -= f;
      ans += f;
      if(!(a -= f)) break ;
    }
  }
  return ans;
}
ll dinic(int _s, int _t) {
  s = _s, t = _t;
  ll ans = 0;
  while(bfs()) {
    copy(hd, hd + n + 1, cur);
    ans += dfs(s, INF);
  }
  return ans;
}

}
int n;
int main() {
  scanf("%d", &n);
  net::init(2 * n + 2);

  const int X = 1e9;
  rep(i, 1, n) {
    int k, x;
    scanf("%d", &k);
    net::add(n + i, 2 * n + 2, X);
    rep(j, 1, k) {
      scanf("%d", &x);
      net::add(i, n + x, net::INF);
    }
  }
  ll sum = 0;
  rep(i, 1, n) {
    int x;
    scanf("%d", &x);
    sum += X - x;
    net::add(2 * n + 1, i, X - x);
  }
  ll ans = - (sum - net::dinic(2 * n + 1, 2 * n + 2));
  ans = min(ans, 0ll);
  printf("%lld\n", ans);
  return 0;
}
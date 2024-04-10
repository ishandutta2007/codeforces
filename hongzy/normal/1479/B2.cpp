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

const int N = 1e5 + 10;
const int mod = 1e9 + 7;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() {
  ios::sync_with_stdio(0); cin.tie(0);
}
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }

inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }
int n, a[N];

int mv[N * 4], tag[N * 4];
void addtag(int u, int v) {
  tag[u] += v; mv[u] += v;
}
void up(int u) {
  mv[u] = min(mv[u << 1 | 1], mv[u << 1]);
}
void build(int u, int l, int r) {
  if(l == r) { mv[u] = l == n + 1 ? 0 : N; return ; }
  int mid = (l + r) >> 1;
  build(u << 1, l, mid);
  build(u << 1 | 1, mid + 1, r);
  up(u);
}
void down(int u) {
  if(tag[u]) {
    addtag(u << 1, tag[u]);
    addtag(u << 1 | 1, tag[u]);
    tag[u] = 0;
  }
}
void modify(int u, int l, int r, int p, int num) {
  if(l == r) { mv[u] = min(mv[u], num); return ; }
  int mid = (l + r) >> 1; down(u);
  if(p <= mid) modify(u << 1, l, mid, p, num);
  else modify(u << 1 | 1, mid + 1, r, p, num);
  up(u);
}
int query(int u, int l, int r, int ql, int qr) {
  // if(ql > qr) return N;
  if(l == ql && r == qr) return mv[u];
  int mid = (l + r) >> 1; down(u);
  if(qr <= mid) return query(u << 1, l, mid, ql, qr);
  if(ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
  return min(query(u << 1, l, mid, ql, mid), query(u << 1 | 1, mid + 1, r, mid + 1, qr));
}
int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", a + i);
  build(1, 1, n + 1);
  a[0] = n + 1;
  rep(i, 1, n) {
    int w = min(query(1, 1, n + 1, 1, n + 1) + 1, query(1, 1, n + 1, a[i], a[i]));
    addtag(1, a[i] != a[i - 1]);
    modify(1, 1, n + 1, a[i - 1], w);
  }
  printf("%d\n", mv[1]);
  return 0;
}
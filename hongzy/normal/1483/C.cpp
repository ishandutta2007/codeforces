#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT);
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

const int N = 3e5 + 10;
const ll INF = 1ll << 60;
struct SMT {
  ll w[N * 4];
  void up(int u) {
    w[u] = max(w[u << 1], w[u << 1 | 1]);
  }
  void build(int u, int l, int r) {
    w[u] = -INF;
    if(l == r) { return ; }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
  }
  void modify(int u, int l, int r, int p, ll val) {
    if(l == r) { w[u] = val; return ; }
    int mid = (l + r) >> 1;
    if(p <= mid) modify(u << 1, l, mid, p, val);
    else modify(u << 1 | 1, mid + 1, r, p, val);
    up(u);
  }
  ll query(int u, int l, int r, int ql, int qr) {
    if(l == ql && r == qr) return w[u];
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(u << 1, l, mid, ql, qr);
    if(ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
    return max(query(u << 1, l, mid, ql, mid), query(u << 1 | 1, mid + 1, r, mid + 1, qr));
  }
} seg;
int n, h[N], b[N], top, st[N];
ll dp[N];
int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", h + i);
  rep(i, 1, n) scanf("%d", b + i);
  seg.build(1, 0, n);
  dp[0] = 0; seg.modify(1, 0, n, 0, 0);
  rep(i, 1, n) {
    while(top && h[st[top]] > h[i]) {
      top --;
    }
    int s = top ? st[top] : 0;
    if(!s) {
      dp[i] = seg.query(1, 0, n, 0, i - 1) + b[i];
    } else {
      dp[i] = max(dp[s], seg.query(1, 0, n, s, i - 1) + b[i]);
    }
    seg.modify(1, 0, n, i, dp[i]);
    st[++ top] = i;
  }
  printf("%lld\n", dp[n]);
  return 0;
}
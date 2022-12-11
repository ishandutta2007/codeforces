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
int n, v, a[N];
ll ans;
char s[N];

ll c[N], d[N];
vector<int> ops;
void add(int x, int y, int z) {
  ops.pb(x);
  for(; x <= n + 1; x += x & (-x))
    c[x] += y, d[x] += z;
}
ll qryC(int x) {
  int ans = 0;
  for(; x >= 1; x &= x - 1)
    ans += c[x];
  return ans;
}
ll qryD(int x) {
  ll ans = 0;
  for(; x >= 1; x &= x - 1)
    ans += d[x];
  return ans;
}
void clr() {
  for(int x : ops)
    for(; x <= n + 1; x += x & (-x))
      c[x] = d[x] = 0;
  ops.clear();
}
void solve(int l, int r) {
  if(l == r) {
    return ;
  }
  int mid = (l + r) >> 1;

  int mv = 1e9, p = mid;
  ll sum = 0;
  per(i, mid, l) {
    mv = min(mv, a[i]);
    while(p + 1 <= r && a[p + 1] >= mv) {
      p ++;
      add(a[p] - v + 1, 1, a[p]);
      sum += a[p];
    }
    ans += -mv * ll(p-mid) + a[i] * qryC(a[i] - v + 1) + sum - qryD(a[i] - v + 1);
  }
  clr();

  mv = 1e9, p = mid + 1;
  sum = 0;
  rep(i, mid + 1, r) {
    mv = min(mv, a[i]);
    while(p - 1 >= l && a[p - 1] > mv) {
      p --;
      add(a[p] - v + 1, 1, a[p]);
      sum += a[p];
    }
    ans += -mv * ll(mid-p+1) + a[i] * qryC(a[i] - v + 1) + sum - qryD(a[i] - v + 1);
  }
  clr();

  solve(l, mid);
  solve(mid + 1, r);
}
int main() {
  int test;
  scanf("%d", &test);
  rep(T, 1, test) {
    scanf("%d%s", &n, s + 1);
    rep(i, 1, n) a[i] = a[i-1] + (s[i] == '(' ? 1 : -1);
    v = a[0];
    rep(i, 1, n) v = min(v, a[i]);
    fill(c, c + n + 2, 0);

    ans = 0;
    // rep(l, 1, n) rep(r, l, n) {
    //   int v1 = a[l];
    //   rep(i, l - 1, r) v1 = min(v1, a[i]);
    //   ans += max(a[l-1] - v1, a[r] - v1);
    // }
    solve(0, n);
    printf("%lld\n", ans);
  }
  return 0;
}
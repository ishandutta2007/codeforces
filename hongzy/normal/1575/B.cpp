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

const int N = 1e5 + 10;
const int mod = 1e9 + 7;

const db eps = 1e-9, INF = 1e20;
const db pi = acosl(-1.0);

#define lt(x, y) ((x) < (y) - eps)
#define gt(x, y) ((x) > (y) + eps)
#define leq(x, y) ((x) <= (y) + eps)
#define geq(x, y) ((x) >= (y) - eps)
#define cross(u, v, w) ((v - u).det(w - u))
bool eq(db x, db y) { return abs(x-y) < eps; }
int sign(db x) { return x < -eps ? -1 : x > eps; }

struct P {
  db x, y;
  void in() { scanf("%lf%lf", &x, &y); }
  void in_int() { int a, b; scanf("%d%d", &a, &b); x = a; y = b; }
  void debug() { LOG("(%.1f, %.1f)\n", x, y); }
  void out(char c = '\n') { printf("%.12f %.12f%c", x, y, c); }
  db norm() { return sqrtl(x * x + y * y); }
  db norm2() { return x * x + y * y; }
  db alpha() { return atan2l(y, x); }
  P unit() { db z = norm(); return {x / z, y / z}; }
  bool operator < (P b) const { return lt(x, b.x) || (leq(x, b.x) && lt(y, b.y)); }
  bool operator == (P b) { return eq(x, b.x) && eq(y, b.y); }

  P operator + (P b) { return {x + b.x, y + b.y}; }
  P operator - (P b) { return {x - b.x, y - b.y}; }
  P operator - () { return {-x, -y}; }
  void operator += (P b) { *this = *this + b; }
  void operator -= (P b) { *this = *this - b; }

  db operator * (P b) { return x * b.x + y * b.y; }
  P operator * (db b) { return {x * b, y * b}; }
  P operator / (db b) { return {x / b, y / b}; }

  db det(P b) { return x * b.y - y * b.x; }

  P rot90() { return {-y, x}; }
  P rot(db a) { return {cos(a)*x - sin(a)*y, sin(a)*x + cos(a)*y}; }
} a[N];
db f[N], g[N];
int n, k;
bool check(db r) {
  vector<db> num;
  rep(i, 1, n) {
    if(gt(a[i].norm(), r * 2)) continue;
    db z = sqrt(r * r - a[i].norm2() / 4);
    P pm = a[i] / 2;
    P o1 = pm - a[i].rot90().unit() * z;
    P o2 = pm + a[i].rot90().unit() * z;
    f[i] = o1.alpha(), g[i] = o2.alpha();
    num.pb(f[i]); num.pb(g[i]);
  }
  sort(num.begin(), num.end());
  num.resize(unique(num.begin(), num.end(), [&](db x, db y) {
    return eq(x, y);
  }) - num.begin());
  vector<int> cov(num.size());
  auto cover = [&](int a, int b) {
    cov[a]++;
    if(b+1 < num.size())
      cov[b+1] --;
  };
  rep(i, 1, n) {
    if(gt(a[i].norm(), r * 2)) continue;
    int il = lower_bound(num.begin(), num.end(), f[i] - eps) - num.begin();
    int ir = lower_bound(num.begin(), num.end(), g[i] - eps) - num.begin();
    if(il <= ir) cover(il, ir);
    else cover(0, ir), cover(il, int(num.size())-1);
  }
  rep(i, 1, int(num.size())-1)
    cov[i] += cov[i-1];
  rep(i, 0, int(num.size())-1)
    if(cov[i] >= k)
      return 1;
  return 0;
}
int main() {
  scanf("%d%d", &n, &k);
  rep(i, 1, n) {
    a[i].in_int();
    if(a[i] == P{0, 0})
      k --, n --, i --;
  }
  if(k <= 0) return puts("0.0"), 0;
  db l = 0, r = 2e5;
  while(r - l > 1e-6) {
    db mid = (l + r) / 2;
    if(check(mid)) r = mid;
    else l = mid;
  }
  printf("%.10f\n", l);
  return 0;
}
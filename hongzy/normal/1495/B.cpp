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

const int N = 4e5 + 10;
const int mod = 1e9 + 7;
int n, p[N], ldown[N], rdown[N];
int con(int l, int r) {
  static int f[N];
  int ans = 0;
  f[l] = 0;
  rep(i, l + 1, r) f[i] = p[i - 1] < p[i] ? f[i - 1] + 1 : 0;
  rep(i, l, r) ans = max(ans, f[i]);
  f[l] = 0;
  rep(i, l + 1, r) f[i] = p[i - 1] > p[i] ? f[i - 1] + 1 : 0;
  rep(i, l, r) ans = max(ans, f[i]);
  return ans;
}
int check(int x) {
  if(!x || x == 1 || x == n || !(p[x - 1] < p[x] && p[x] > p[x + 1])) return 0;
  int L = max(ldown[x], rdown[x]);
  if(con(1, x - ldown[x]) >= L || con(x + rdown[x], n) >= L) return 0;
  int u = ldown[x], v = rdown[x];
  if(u < v) swap(u, v);
  for(int i = 1; i <= u; i ++)
    if(i % 2 == 1 && i >= v) return 0;
  return 1;
}
int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", p + i);
  ldown[1] = 0;
  rep(i, 2, n) {
    if(p[i - 1] < p[i]) {
      ldown[i] = ldown[i - 1] + 1;
    } else {
      ldown[i] = 0;
    }
  }
  rdown[n] = 0;
  per(i, n - 1, 1) {
    if(p[i] > p[i + 1]) {
      rdown[i] = rdown[i + 1] + 1;
    } else {
      rdown[i] = 0;
    }
  }
  int x = 0, z = 0;
  rep(i, 1, n) {
    if(!x || z < max(ldown[i], rdown[i])) {
      z = max(ldown[i], rdown[i]);
      x = i;
    }
  }
  // cerr << "x = " << x << endl;
  printf("%d\n", check(x));
  return 0;
}
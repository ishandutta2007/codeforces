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

const int N = 2e6 + 10;
const int mod = 1e9 + 7;
int n, m, a[N], b[N], pos[N], match[N];
vector<int> v;
ll k, sum;
ll calc2(ll R, int len) {
  ll c = 0;
  for(ll i = R; i >= R - len + 1; i --) {
    if(a[(i - 1) % n + 1] != b[(i - 1) % m + 1]) {
      c ++;
    }
  }
  return c;
}
ll calc(ll len) {
  ll t = len / ll(v.size()), r = len % ll(v.size());
  ll ans = t * sum;
  for(int i = 0; i < r; i ++) ans += v[i];
  return ans;
}
ll S(ll mid) {
  ll t = mid / m, r = mid % m;
  return calc(t) + calc2(mid, r);
}
int main() {
  scanf("%d%d%lld", &n, &m, &k);
  rep(i, 1, n) scanf("%d", a + i);
  rep(i, 1, m) scanf("%d", b + i);
  if(n < m) swap(n, m), swap(a, b);
  rep(i, 1, n) pos[a[i]] = i;
  //s \in [1, 2n - m + 1], s + i - 1 = pos
  rep(i, 1, m) if(pos[b[i]]) {
    if(pos[b[i]] - i + 1 >= 1) {
      match[pos[b[i]] - i + 1] ++;
    } else {
      match[pos[b[i]] - i + 1 + n] ++;
    }
  }
  // rep(i, 1, n) printf("match %d = %d\n", i, match[i]);
  v.pb(m - match[0 + 1]);
  for(int i = m % n; i; i = (i + m) % n)
    v.pb(m - match[i + 1]);
  for(ll x : v) sum += x;
  ll l = 1, r = 1e18, ans = 0;
  while(l <= r) {
    ll mid = (l + r) / 2;
    if(S(mid) >= k) r = (ans = mid) - 1;
    else l = mid + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
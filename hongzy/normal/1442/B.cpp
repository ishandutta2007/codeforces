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
int n, k, a[N], b[N], pos[N];
bool use[N];
int main() {
  int t; scanf("%d", &t);
  while(t --) {
    scanf("%d%d", &n, &k);
    rep(i, 1, n) scanf("%d", a + i), pos[a[i]] = i;
    fill(use, use + n + 1, 0);
    rep(i, 1, k) scanf("%d", b + i), b[i] = pos[b[i]], use[b[i]] = 1;
    set<int> s;
    rep(i, 0, n + 1) s.insert(i);
    use[0] = use[n + 1] = 1;
    int ans = 1;
    rep(i, 1, k) {
      auto u = s.lower_bound(b[i]);
      auto r = u, l = u; r ++; l --;
      if(use[*r] && use[*l]) { ans = 0; break ; }
      if(use[*r]) s.erase(l);
      else if(use[*l]) s.erase(r);
      else {
        ans = (ans + ans) % mod;
        s.erase(l);
      }
      use[*u] = 0;
    }
    printf("%d\n", ans);
  }
  return 0;
}
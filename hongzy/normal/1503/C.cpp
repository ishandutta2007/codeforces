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
int n, a[N], c[N];
ll ans;
pii p[N];
int main() {
  scanf("%d", &n);
  rep(i, 1, n) {
    scanf("%d%d", a + i, c + i);
    ans += c[i];
    p[i] = pii(a[i], a[i] + c[i]);
  }
  sort(p + 1, p + n + 1);
  int last = p[1].sc;
  rep(i, 2, n) {
    if(p[i].sc <= last) continue ;
    if(p[i].fs > last) {
      ans += p[i].fs - last;
    }
    last = p[i].sc;
  }
  printf("%lld\n", ans);
  return 0;
}
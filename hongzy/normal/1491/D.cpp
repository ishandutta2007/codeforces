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
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() { ios::sync_with_stdio(0); cin.tie(0); }
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 4e5 + 10;
const int mod = 1e9 + 7;
int q;
int main() {
  scanf("%d", &q);
  while(q --) {
    ll u, v;
    scanf("%lld%lld", &u, &v);
    if(u > v) puts("NO");
    else if(u == v) puts("YES");
    else {
      while(1) {
        bool mk = 0;
        for(int i = 30; ~i; i --) if((u >> i & 1) && u + (1ll << i) <= v) {
          u += 1 << i; mk = 1; break ;
        }
        if(!mk) break ;
      }
      puts(u != v ? "NO" : "YES");
    }
  }
  return 0;
}
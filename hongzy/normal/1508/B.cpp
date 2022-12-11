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
int n;
ll k;
vector<int> p;
int main() {
  int t; scanf("%d", &t);
  while(t --) {
    scanf("%d%lld", &n, &k);
    if(n <= 63 && k > (1ll << (n - 1))) { puts("-1"); continue ; }
    p.clear();
    int id = 0;
    while(id < n) {
      // printf("k = %lld\n", k);
      if(id <= n - 63) {
        p.pb(++ id);
        continue ;
      }
      rep(i, id + 1, n) {
        ll t = n == i ? 1 : (1ll << (n - i - 1));
        if(k > t) { k -= t; continue ; }
        per(j, i, id + 1) p.pb(j);
        id = i;
        break ;
      }
    }
    for(int v : p) {
      printf("%d ", v);
    }
    puts("");
  }
  return 0;
}
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

const int N = 2e7 + 10;
const int mod = 1e9 + 7;
bool tag[N];
int p[N], pc, w[N];
void sieve(int n) {
  w[1] = 0;
  for(int i = 2; i <= n; i ++) {
    if(!tag[i]) p[++ pc] = i, w[i] = 1;
    for(int j = 1; j <= pc && i * p[j] <= n; j ++) {
      tag[i * p[j]] = 1;
      if(i % p[j] == 0) {
        w[i * p[j]] = w[i];
        break ;
      }
      w[i * p[j]] = w[i] + 1;
    }
  }
}
int c, d, e;
ll ans;
void calc(ll y) {
  ll u = e / y;
  if((u + d) % c) return ;
  ll k = (u + d) / c;
  ans += 1ll << w[k];
}
int main() {
  sieve(2e7);
  int t; scanf("%d", &t);
  while(t --) {
    ans = 0;
    scanf("%d%d%d", &c, &d, &e);
    for(int y = 1; y * y <= e; y ++) {
      if(e % y == 0) {
        calc(y);
        if(y * y != e) calc(e / y);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
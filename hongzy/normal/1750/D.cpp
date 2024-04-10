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
const int mod = 998244353;
int n, m, a[N];
int main() {
  int test;
  scanf("%d", &test);
  rep(T, 1, test) {
    scanf("%d%d", &n, &m);
    rep(i, 1, n) scanf("%d", a + i);
    bool tag = 1;
    rep(i, 2, n) if(a[i-1] % a[i]) { tag = 0; break ; }
    if(!tag) {
      puts("0");
      continue;
    }
    vector<int> p;
    int t = a[1];
    for(int x = 2; x * x <= t; x ++) {
      if(t % x == 0) {
        p.pb(x);
        while(t % x == 0) t /= x;
      }
    }
    if(t > 1) p.pb(t);
    sort(p.begin(), p.end());
    
    auto func = [&](int x) {
      vector<int> cor(p.size());
      for(int i = 0; i < p.size(); i ++) {
        int c = 0;
        while(x % p[i] == 0) x /= p[i], c ++;
        cor[i] = c;
      }
      return cor;
    };
    vector<int> low = func(a[1]);
    int ans = 1;
    rep(i, 2, n) {
      vector<int> cur = func(a[i]);
      int m0 = m / a[i];
      vector<int> sth;
      for(int j = 0; j < p.size(); j ++) {
        // printf("(%d, %d)\n", cur[j], low[j]);
        if(cur[j] < low[j])
          sth.pb(p[j]);
      }
      int now = 0;
      for(int j = 0; j < (1 << sth.size()); j ++) {
        int tmp = 1, cc = 0;
        for(int k = 0; k < sth.size(); k ++)
          if(j >> k & 1)
            tmp *= sth[k], cc ^= 1;
        if(cc) now -= m0 / tmp;
        else now += m0 / tmp;
      }
      ans = (ll)ans * now % mod;
      low = cur;
    }
    printf("%d\n", ans);
  }
  return 0;
}
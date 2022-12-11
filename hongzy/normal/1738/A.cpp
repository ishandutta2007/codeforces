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

const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int n, a[N], b[N]; 
int main() {
  int test;
  scanf("%d", &test);
  rep(T, 1, test) {
    scanf("%d", &n);
    vector<int> v[2];
    ll sum = 0;
    rep(i, 1, n) scanf("%d", a + i);
    rep(i, 1, n) scanf("%d", b + i), v[a[i]].pb(b[i]), sum += b[i];
    if(v[0].size() > v[1].size())
      swap(v[0], v[1]);
    if(v[1].size() == n) {
      printf("%lld\n", sum);
    } else if(v[0].size() == v[1].size()) {
      int z = v[0][0];
      for(int x : v[0]) z = min(z, x);
      for(int x : v[1]) z = min(z, x);
        printf("%lld\n", 2*sum - z);
    } else {
      for(int x : v[0]) sum += x;
      sort(v[1].begin(), v[1].end(), greater<int>());
      for(int i = 0; i < int(v[0].size()); i ++)
        sum += v[1][i];
      printf("%lld\n", sum);
    }
  }
  return 0;
}
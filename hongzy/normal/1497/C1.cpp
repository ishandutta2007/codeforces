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

const int N = 1e7 + 10;
const int M = 2e5 + 10;
const int mod = 1e9 + 7;

int n, k;
void solve() {
  if(n & 1) printf("%d %d %d\n", 1, (n - 1) / 2, (n - 1) / 2);
  else if(n % 4 == 2) printf("%d %d %d\n", 2, (n - 2) / 2, (n - 2) / 2);
  else printf("%d %d %d\n", n / 4, n / 4, n / 2);
}
int main() {
  int test; scanf("%d", &test);
  while(test --) {
    scanf("%d%d", &n, &k);
    rep(i, 1, k - 3) printf("%d ", 1);
    n -= k - 3;
    solve();
  }
  return 0;
}
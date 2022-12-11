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

const int N = 100 + 10;
const int mod = 1e9 + 7;
int n, k, a[N];
int main() {
  int test; scanf("%d", &test);
  while(test --) {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", a + i);
    vector<int> vis(101), use(101);
    sort(a + 1, a + n + 1);
    rep(i, 1, n) vis[a[i]] = 1;
    int s = -1;
    while(s + 1 <= 100 && vis[s + 1]) s ++;
    rep(i, 0, s) printf("%d ", i), use[i] = 1;
    rep(i, 1, n) {
      if(use[a[i]]) {
        use[a[i]] = 0;
      } else {
        printf("%d ", a[i]);
      }
    }
    puts("");
  }
  return 0;
}
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
const int mod = 1e9 + 7;
int n, c[N];
char a[N], b[N];
bool solve(int par) {
  rep(i, 1, n) c[i] = b[i] ^ par;
  c[n + 1] = 0;
  per(i, n + 1, 1) c[i] ^= c[i-1];
  rep(i, 1, n + 1) if(c[i] != a[i]) return 0;
  vector<int> vec;
  rep(i, 1, n) if(a[i]) vec.pb(i);
  vector<pii> ans;
  for(int i = 0; i + 1 < vec.size(); i += 2) {
    ans.pb(pii(vec[i], vec[i+1]-1));
  }
  if(vec.size() % 2)
    ans.pb(pii(* --vec.end(), n));
  if(par != ans.size() % 2) {
    ans.pb(pii(1, 1)), ans.pb(pii(1, n)), ans.pb(pii(2, n));
  }
  puts("YES");
  printf("%lu\n", ans.size());
  for(auto it: ans)
    printf("%d %d\n", it.fs, it.sc);
  return 1;
}
int main() {
  int test;
  scanf("%d", &test);
  rep(T, 1, test) {
    scanf("%d%s%s", &n, a + 1, b + 1);
    rep(i, 1, n) a[i] &= 15, b[i] &= 15;
    a[n + 1] = 0;
    per(i, n + 1, 1) a[i] ^= a[i-1];
    if(solve(0));
    else if(solve(1));
    else puts("NO");
  }
  return 0;
}
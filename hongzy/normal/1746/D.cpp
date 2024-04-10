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
int test, n, k, p[N], w[N];
vector<int> G[N];
pair<ll, ll> dfs(int u, int k) {
  pll ans(0, 0);
  int c = G[u].size();
  if(!c)
    ans = pll(1ll * k * w[u], (k + 1ll) * w[u]);
  else {
    //all k/c and k%c is k/c+1
    vector<ll> vec;
    for(int v : G[u]) {
      pll cur = dfs(v, k / c);
      ans.fs += cur.fs;
      vec.pb(cur.sc - cur.fs);
    }
    sort(vec.begin(), vec.end(), greater<ll>());
    rep(i, 0, (k%c)-1)
      ans.fs += vec[i];
    ans.sc = ans.fs + vec[k % c];
    ans.fs += 1ll * w[u] * k;
    ans.sc += (k+1ll) * w[u];
  }
  return ans;
}
int main() {
  scanf("%d", &test);
  rep(T, 1, test) {
    scanf("%d%d", &n, &k);
    rep(i, 1, n) G[i].clear();
    rep(i, 2, n) scanf("%d", p + i), G[p[i]].pb(i);
    rep(i, 1, n) scanf("%d", w + i);
    printf("%lld\n", dfs(1, k).fs);
  }
  return 0;
}
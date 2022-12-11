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

const int N = 3e5 + 10;
const int mod = 1e9 + 7;
vector<int> G[N], T[N];
int L[N], R[N], idx;
void dfs(int u, int fa = 0) {
  L[u] = ++ idx;
  for(int v : T[u]) if(v != fa) {
    dfs(v, u);
  }
  R[u] = idx;
}
int n, ans;
set<pii> S;
void dfs2(int u, int fa = 0) {
  auto it = S.lower_bound(mp(L[u] + 1, 0));
  pii tmp(0, 0);
  if(it != S.begin()) {
    it --;
    if(it->sc >= R[u]) {
      tmp = *it;
      S.erase(it);
    }
  }
  S.insert(mp(L[u], R[u]));
  ans = max(ans, int(S.size()));
  for(int v : G[u]) if(v ^ fa) dfs2(v, u);
  if(tmp.fs) {
    S.insert(tmp);
  }
  S.erase(mp(L[u], R[u]));
}
int main() {
  int test;
  scanf("%d", &test);
  while(test --) {
    scanf("%d", &n);
    int f;
    rep(i, 1, n) G[i].clear(), T[i].clear();
    rep(i, 2, n) scanf("%d", &f), G[f].pb(i);
    rep(i, 2, n) scanf("%d", &f), T[f].pb(i);
    idx = 0;
    dfs(1);
    S.clear(); ans = 0;
    dfs2(1);
    printf("%d\n", ans);
  }
  return 0;
}
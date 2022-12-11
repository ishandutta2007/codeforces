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
int n, m, ans[N], cnt[N];
vector<int> day[N];
int main() {
  int test;
  scanf("%d", &test);
  while(test --) {
    scanf("%d%d", &n, &m);
    rep(i, 1, n) day[i].clear(), cnt[i] = 0;
    rep(i, 1, m) {
      ans[i] = 0;
      int sz, u;
      scanf("%d", &sz);
      while(sz --) {
        scanf("%d", &u);
        day[u].pb(i);
      }
    }
    int mx = 1;
    rep(i, 2, n) if(day[i].size() > day[mx].size()) mx = i;
    rep(i, 1, n) if(mx != i) {
      for(int v : day[i]) {
        if(ans[v]) cnt[ans[v]] --;
        ans[v] = i, cnt[i] ++;
      }
    }
    for(int v : day[mx]) if(!ans[v]) {
      ans[v] = mx; cnt[mx] ++;
    }
    for(int v : day[mx]) if(ans[v] && ans[v] != mx && cnt[mx] < (m + 1) / 2) {
      cnt[ans[v]] --; ans[v] = mx; cnt[mx] ++;
    }
    bool ok = 1;
    rep(i, 1, m) if(!ans[i]) { ok = 0; break ; }
    rep(i, 1, n) if(cnt[i] > (m + 1) / 2) {
      ok = 0; break ;
    }
    if(!ok) puts("NO");
    else {
      puts("YES");
      rep(i, 1, m) printf("%d%c", ans[i], " \n"[i == m]);
    }
  }
  return 0;
}
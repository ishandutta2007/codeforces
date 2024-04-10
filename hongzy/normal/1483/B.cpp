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
int test, n, a[N], L[N], R[N];
bool del[N];
vector<int> ans;
int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}
int main() {
  scanf("%d", &test);
  while(test --) {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", a + i), del[i] = 0;
    int tim = 0;
    queue<pii> q; ans.clear();
    rep(i, 1, n) {
      L[i] = i == 1 ? n : i - 1;
      R[i] = i == n ? 1 : i + 1;
      int r = R[i];
      if(gcd(a[i], a[r]) == 1) {
        q.push(pii(i, r));
      }
    }
    while(q.size()) {
      pii k = q.front(); q.pop();
      if(del[k.fs] || del[k.sc]) continue ;
      del[k.sc] = 1;
      ans.pb(k.sc);
      int l = L[k.sc], r = R[k.sc];
      L[r] = l;
      R[l] = r;
      if(gcd(a[l], a[r]) == 1) {
        q.push({l, r});
      }
    }
    printf("%lu", ans.size());
    for(int v : ans) printf(" %d", v);
    puts("");
  }
  return 0;
}
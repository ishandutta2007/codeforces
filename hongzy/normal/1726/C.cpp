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
int n, f[N];
char s[N];
int find(int u) {
  return u == f[u] ? u : f[u] = find(f[u]);
}
void unite(int u, int v) {
  f[find(u)] = find(v);
}
int main() {
  int t; scanf("%d", &t);
  while(t--) {
    scanf("%d%s", &n, s + 1);
    vector<int> rt(n + 5, 0);
    n <<= 1;
    rep(i, 1, n) f[i] = i;
    int d = 0;
    rep(i, 1, n) {
      if(s[i] == '(') {
        d ++;
        if(rt[d]) unite(rt[d], i);
        rt[d] = i;
      } else {
        if(rt[d]) unite(rt[d], i);
        rt[d + 1] = 0;
        d --;
      }
    }
    int ans = 0;
    rep(i, 1, n) ans += find(i) == i;
    printf("%d\n", ans);
  }
  return 0;
}
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
int t, n;
char s[N];
bool pdl(int u) {
  int last = -2;
  rep(i, 1, u) {
    if(s[i] == '1') {
      if(last == i - 1) return 0;
      last = i;
    }
  }
  return 1;
}
bool pdr(int u) {
  int last = -2;
  rep(i, u, n) {
    if(s[i] == '0') {
      if(last == i - 1) return 0;
      last = i;
    }
  }
  return 1;
}
int main() {
  cin >> t;
  while(t --) {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    bool ok = 0;
    rep(i, 0, n) {
      if(pdl(i) && pdr(i + 1)) {
        if(!(s[i] == '1' && s[i + 1] == '0')) {
          ok = 1; break ;
        }
      }
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
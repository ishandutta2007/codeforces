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

const int N = 1010;
const int mod = 1e9 + 7;
char s[N], t[N];
int n, m;
int main() {
  int test;
  scanf("%d", &test);
  while(test --) {
    scanf("%d%d%s", &n, &m, s + 1);
    rep(i, 1, min(n + 1, m)) {
      rep(j, 1, n) t[j] = ((s[j - 1] == '1') + (s[j + 1] == '1') == 1 || s[j] == '1') ? '1' : '0';
      rep(j, 1, n) s[j] = t[j];
    }
    puts(s + 1);
  }
  return 0;
}
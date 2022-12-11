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
const int M = 6e6 + 10;
const int mod = 1e9 + 7;
int n, a[N];
pair<int, int> s[M];
int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", a + i);
  int m = sqrt(1e7) + 22;
  m = min(m, n);
  rep(i, 1, m) rep(j, i + 1, m) {
    if(s[a[i] + a[j]].fs && s[a[i] + a[j]].fs != i) {
      if(s[a[i] + a[j]].sc != i && s[a[i] + a[j]].sc != j) {
        printf("YES\n%d %d %d %d\n", s[a[i] + a[j]].fs, s[a[i] + a[j]].sc, i, j);
        return 0;
      }
    } else {
      s[a[i] + a[j]] = mp(i, j);
    }
  }
  puts("NO");
  return 0;
}
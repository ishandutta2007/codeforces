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
int n, m, a[N];
int main() {
  int t; scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &m);
    if(m < n) { puts("No"); continue; }
    rep(i, 1, n) a[i] = 1;
    if(n % 2 == 1) {
      puts("Yes");
      a[n] += m - n;
      rep(i, 1, n) printf("%d%c", a[i], " \n"[i == n]);
    } else {
      if((m - n) % 2) { puts("No"); continue; }
      puts("Yes");
      a[n-1] += (m - n) / 2;
      a[n] += (m - n) / 2;
      rep(i, 1, n) printf("%d%c", a[i], " \n"[i == n]);
    }

  }
  return 0;
}
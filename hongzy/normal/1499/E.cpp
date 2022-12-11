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

const int N = 1000 + 10;
const int mod = 998244353;
int f[N][N][2], n, m, la[N], lb[N];
char a[N], b[N];
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int dec(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
inline void ADD(int &x, const int &y) { (x += y) >= mod ? x -= mod : 0; }
inline void DEC(int &x, const int &y) { (x -= y) < 0 ? x += mod : 0; }

int main() {
  scanf("%s%s", a + 1, b + 1);
  n = strlen(a + 1);
  m = strlen(b + 1);
  rep(i, 1, n) {
    la[i] = 1;
    while(la[i] < i && a[i - la[i]] != a[i - la[i] + 1]) la[i] ++;
  }
  rep(i, 1, m) {
    lb[i] = 1;
    while(lb[i] < i && b[i - lb[i]] != b[i - lb[i] + 1]) lb[i] ++;
  }
  int ans = 0;
  rep(i, 1, n) {
    rep(j, 1, m) {
      if(a[i] != b[j]) {
        ADD(f[i][j][0], lb[j]);
        ADD(f[i][j][1], la[i]);
      }
      if(i < n && a[i] != a[i + 1]) {
        ADD(f[i + 1][j][0], f[i][j][0]);
      }
      if(j < m && b[j] != b[j + 1]) {
        ADD(f[i][j + 1][1], f[i][j][1]);
      }
      if(i < n && a[i + 1] != b[j]) {
        ADD(f[i + 1][j][0], f[i][j][1]);
      }
      if(j < m && a[i] != b[j + 1]) {
        ADD(f[i][j + 1][1], f[i][j][0]);
      }
      ADD(ans, f[i][j][0]);
      ADD(ans, f[i][j][1]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
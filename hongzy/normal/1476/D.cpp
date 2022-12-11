#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
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

const int N = 4e5 + 10;
const int mod = 1e9 + 7;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<long long> ran(0, 1ll << 62);
void ucin() {
  ios::sync_with_stdio(0); cin.tie(0);
}
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
int t, n, f[N][2], g[N][2];
char s[N];
int main() {
  scanf("%d", &t);
  while(t --) {
    scanf("%d%s", &n, s + 1);
    f[0][0] = f[0][1] = 0;
    g[n][0] = g[n][1] = 0;
    rep(i, 1, n) {
      f[i][0] = s[i] == 'L' ? f[i - 1][1] + 1 : 0;
      f[i][1] = s[i] == 'R' ? f[i - 1][0] + 1 : 0;
    }
    per(i, n - 1, 0) {
      g[i][0] = s[i + 1] == 'R' ? g[i + 1][1] + 1 : 0;
      g[i][1] = s[i + 1] == 'L' ? g[i + 1][0] + 1 : 0;
    }
    rep(i, 0, n) {
      printf("%d%c", 1 + f[i][0] + g[i][0], " \n"[i == n]);
    }
  }
  return 0;
}
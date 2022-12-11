#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <chrono>
#include <random>
#include <queue>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back

typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned uint;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<ll> range(0, 1ll << 32);
inline void ucin() {
   ios::sync_with_stdio(0); cin.tie(0);
}

template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }

const int N = 4000 + 10;
const int K = 810;
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}

int n, k, a[N][N], w[N][N], t[N][N], f[N], g[N];
void solve(int l, int r, int ql, int qr) {
   if(l > r) return ;
   int mid = (l + r) >> 1, qmid = 0; f[mid] = INF;
   rep(i, ql, min(qr, mid - 1)) {
      int c = g[i] + t[i + 1][mid];
      if(c < f[mid]) { f[mid] = c; qmid = i; }
   }
   solve(l, mid - 1, ql, qmid);
   solve(mid + 1, r, qmid, qr);
}
int main() {
   scanf("%d%d", &n, &k);
   rep(i, 1, n) rep(j, 1, n) scanf("%d", &a[i][j]);
   rep(i, 1, n) per(j, i, 1) w[i][j] = w[i][j + 1] + a[i][j];
   rep(i, 1, n) rep(j, i, n) t[i][j] = t[i][j - 1] + w[j][i];
   fill(g + 1, g + n + 1, INF); g[0] = 0;
   rep(i, 1, k) {
      f[0] = INF; solve(1, n, 0, n - 1);
      copy(f, f + n + 1, g);
   }
   printf("%d\n", g[n]);
   return 0;
}
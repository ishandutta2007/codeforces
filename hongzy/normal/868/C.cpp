#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
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

const int N = 4e5 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int n, k, a[N][5], s[N];
bool G[5][5];
int main() {
   scanf("%d%d", &n, &k);
   rep(i, 1, n) rep(j, 1, k) scanf("%d", &a[i][j]), s[i] += !a[i][j];
   rep(i, 1, k) {
      int s = 0;
      rep(j, 1, n) s |= !a[j][i];
      if(!s) {
         puts("NO"); return 0;
      }
   }
   rep(i, 1, n) if(s[i] >= 3) { puts("YES"); return 0; }
   rep(i, 1, 3) rep(j, i + 1, 4) {
      bool T = 0;
      rep(k, 1, n) if(!a[k][i] && !a[k][j]) {
         T = 1; break ;
      }
      G[i][j] = G[j][i] = T;
   }
   bool tag = 0;
   tag |= G[1][2] && G[3][4];
   tag |= G[1][3] && G[2][4];
   tag |= G[1][4] && G[2][3];
   puts(tag ? "YES" : "NO");
   return 0;
}
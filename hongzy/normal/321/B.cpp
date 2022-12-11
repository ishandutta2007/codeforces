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

const int N = 400 + 10;
int n, m, a[N], b[N], c[N], ans;
int solve() {
   static int A[N], B[N];
   int res = 0;
   rep(i, 1, m) {
      int u = -1; 
      rep(j, 1, b[0]) if(!B[j] && c[i] >= b[j]) {
         u = j; B[j] = 1; break ;
      }
      if(~ u) {
         res -= c[i];
         continue ;
      }
      rep(j, 1, a[0]) if(!A[j] && c[i] >= a[j]) {
         u = j; A[j] = 1; break ;
      }
   }
   bool qwq = 1;
   rep(i, 1, a[0]) qwq &= A[i];
   rep(i, 1, b[0]) qwq &= B[i];
   if(!qwq) return 0;
   rep(i, 1, a[0]) res -= a[i];
   rep(i, 1, m) res += c[i];
   return res;
}
int main() {
   scanf("%d%d", &n, &m);
   char op[10]; int x;
   rep(i, 1, n) {
      scanf("%s%d", op, &x);
      if(* op == 'A') a[++ a[0]] = x;
      else b[++ b[0]] = x + 1;
   }
   rep(i, 1, m) scanf("%d", c + i);
   sort(a + 1, a + a[0] + 1);
   sort(b + 1, b + b[0] + 1);
   sort(c + 1, c + m + 1);
   if(m > n) ans = solve();
   static bool alive[N];
   int res = 0;
   per(i, m, 1) {
      int u = -1;
      rep(j, 1, a[0]) if(c[i] >= a[j] && !alive[j]) {
         alive[j] = 1; u = j; break ;
      }
      if(u == -1) break ;
      res += c[i] - a[u];
   }
   ans = max(ans, res);
   printf("%d\n", ans);
   return 0;
}
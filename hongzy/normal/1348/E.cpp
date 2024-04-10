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

const int N = 500 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int n, k, a[N], b[N], ra, rb, f[N], g[N];
ll sa, sb;
int main() {
   scanf("%d%d", &n, &k);
   rep(i, 1, n) scanf("%d%d", a + i, b + i), sa += a[i], sb += b[i];
   if(sa / k + sb / k == (sa + sb) / k) {
      printf("%lld\n", (sa + sb) / k);
      return 0;
   }
   f[0] = 1; ra = sa % k; rb = sb % k;
   rep(i, 1, n) {
      copy(f, f + k, g);
      rep(j, 0, k - 1) if(f[j])
         rep(u, 1, k - 1)
            if(u <= a[i] && k - u <= b[i]) g[(j + u) % k] = 1;
      copy(g, g + k, f);
   }
   rep(i, k - rb, ra) if(f[i]) {
      printf("%lld\n", (sa + sb) / k); return 0;
   }
   printf("%lld\n", sa / k + sb / k);
   return 0;
}
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

const int N = 4e5 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int n, a[N];
int main() {
   int t, c = 0; scanf("%d", &t);
   while(t --) {
      scanf("%d", &n);
      static bool dp[N];
      fill(dp, dp + 2 * n + 1, 0); dp[0] = 1;
      vector<int> v;
      int la = 0, cnt = 0;
      rep(i, 1, 2 * n) {
         scanf("%d", a + i);
         if(a[i] > la) {
            la = a[i];
            if(cnt) v.pb(cnt);
            cnt = 1;
         } else {
            cnt ++;
         }
      }
      v.pb(cnt);
      for(int x : v) {
         per(i, 2 * n, x) dp[i] |= dp[i - x];
      }
      puts(dp[n] ? "YES" : "NO");
   }   
   return 0;
}
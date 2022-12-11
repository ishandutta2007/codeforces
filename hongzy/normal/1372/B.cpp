#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
// #include <random>
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
typedef pair<ll, int> pll;
 
// unsigned seed = chrono::system_clock::now().time_since_epoch().count();
// mt19937 Rand(seed);
// uniform_int_distribution<ll> range(0, 1ll << 32);
// inline void ucin() {
//    ios::sync_with_stdio(0); cin.tie(0);
// }
 
const int N = 4e5 + 10;
const int mod = 1e9 + 7;
 
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int n;
int main() {
   int t; scanf("%d", &t);
   while(t --) {
      scanf("%d", &n); int x = n, y = 0;
      for(int i = 2; i * i <= x; i ++) {
         if(x % i == 0) {
            y = i; break ;
         }
      }
      if(!y) y = n;
      if(y == n) {
         printf("%d %d\n", 1, n - 1);
      } else {
         printf("%d %d\n", n / y * (1), n / y * (y - 1));
      }
   }
   return 0;
}
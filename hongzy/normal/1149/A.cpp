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
int n, x, c[3];
int main() {
   scanf("%d", &n);
   rep(i, 1, n) scanf("%d", &x), c[x] ++;
   if(!c[1]) {
      rep(i, 1, n) printf("%d ", 2);
   } else {
      int p = 0;
      while(c[1] >= 2 || c[2] >= 1) {
         if(p == 2) {
            if(c[1]) {
               c[1] --; printf("%d ", 1); p ++; continue ;
            }
         }
         if(c[2] >= 1) {
            c[2] --; printf("%d ", 2); p += 2;
         } else {
            c[1] -= 2; printf("%d %d ", 1, 1); p += 2;
         }
      }
      if(c[1] == 1) printf("%d ", 1);
   }
   return 0;
}
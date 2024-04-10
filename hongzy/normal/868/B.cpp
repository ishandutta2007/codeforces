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
int h, s, t, t1, t2;
bool ban[12];
int main() {
   cin >> h >> t >> s >> t1 >> t2; t1 %= 12; t2 %= 12;
   int x = (int)(t / 5.0); ban[x] = 1;
   x = (int) (s / 5.0); ban[x] = 1;
   h %= 12; ban[h] = 1;
   bool b1 = 0, b2 = 0;
   for(int y = t1; y != t2; y = (y + 1) % 12)
      b1 |= ban[y];
   for(int y = t2; y != t1; y = (y + 1) % 12)
      b2 |= ban[y];
   puts(!b1 || !b2 ? "YES" : "NO");
   return 0;
}
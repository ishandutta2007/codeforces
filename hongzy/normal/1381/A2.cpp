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
int n;
char a[N], b[N];
#define ppos(x) a[(rev ? (st - (x) + 1) : (st + (x) - 1))]
bool check(vector<int> &v) {
   for(int x :v) {
      reverse(a + 1, a + x + 1);
      rep(i, 1, x) a[i] ^= 1;
   }
   rep(i, 1, n) if(a[i] != b[i]) return 0;
   return 1;
}
int main() {
   int t, c = 0; scanf("%d", &t);
   while(t --) {
      scanf("%d%s%s", &n, a + 1, b + 1);
      rep(i, 1, n) a[i] -= '0', b[i] -= '0';
      vector<int> pos;
      bool rev = 0, tag = 0, a1tag = 0; int st = 1;
      per(i, n, 1) {
         if(i == 1) {
            if((ppos(1) ^ tag) != b[1]) {
               pos.pb(1);
            }
         } else {
            bool val = ppos(i) ^ tag;
            if(val == b[i]) continue ;
            if((ppos(1) ^ tag) != (b[i] ^ 1)) {
               pos.pb(1);
            }
            pos.pb(i); st = !rev ? st + i - 1 : st - i + 1; rev ^= 1; tag ^= 1;
         }
      }
      printf("%d", (int) pos.size());
      for(int v: pos) printf(" %d", v);
      printf("\n");
      // c++;
      // if(!check(pos)) printf("wa %d\n", c);
   }   
   return 0;
}
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <bitset>
#include <cstdio>
#include <vector>
#include <chrono>
#include <random>
#include <string>
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

const int N = 110;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}

struct String {
   string pre, suf;
   bitset<1024 + 10> tag[10];
   void init(char *s) {
      int n = strlen(s + 1);
      rep(i, 1, n) {
         int z = 0;
         rep(k, 1, 9) {
            if(i + k - 1 > n) break ;
            z = (z << 1) + (s[i + k - 1] & 15);
            tag[k][z] = 1;
         }
      }
      rep(i, 1, min(n, 9)) pre.pb(s[i]);
      rep(i, max(1, n - 8), n) suf.pb(s[i]);
   }
   void merge(String A, String B) {
      rep(k, 1, 9) tag[k] = A.tag[k] | B.tag[k];
      pre = A.pre + B.pre; pre.resize(min((int) pre.size(), 9));
      suf = A.suf + B.suf; while(suf.size() > 9) suf.erase(suf.begin());
      int L = A.suf.size(), R = B.pre.size();
      rep(i, 1, 8) if(i <= L) rep(j, 1, 8) if(j <= R) {
         if(i + j > 9) break ;
         int z = 0;
         rep(k, L - i, L - 1) z = (z << 1) + (A.suf[k] & 15);
         rep(k, 0, j - 1) z = (z << 1) + (B.pre[k] & 15);
         tag[i + j][z] = 1;
      }
   }
   int result() {
      rep(k, 1, 9) {
         if(tag[k].count() != (1 << k)) {
            return k - 1;
         }
      }
      return 9;
   }
} s[N * 2];
int n, m;
int main() {
   scanf("%d", &n);
   static char str[N];
   rep(i, 1, n) {
      scanf("%s", str + 1);
      s[i].init(str);
   }
   scanf("%d", &m);
   rep(i, 1, m) {
      int x, y;
      scanf("%d%d", &x, &y);
      s[n + i].merge(s[x], s[y]);
      printf("%d\n", s[n + i].result());
   }
   return 0;
}
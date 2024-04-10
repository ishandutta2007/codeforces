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

const int N = 34;
int n, a[N][N], m, ans;
bool rev[N][N];
inline int calc(int x, int y) {
   return rev[x][y] ? - a[x][y] : a[x][y];
}
int main() {
   scanf("%d", &n); m = (n + 1) >> 1;
   rep(i, 1, n) rep(j, 1, n) scanf("%d", &a[i][j]);
   for(int s = 0; s < (1 << m); s ++) {
      rep(i, 0, m - 1) rev[m][i + 1] = s >> i & 1;
      rep(i, m + 1, n) rev[m][i] = rev[m][m] ^ rev[m][i - m];
      int cur = 0;
      rep(i, 1, n) cur += calc(m, i);
      rep(i, 1, m - 1) {
         int res = 0;
         rep(r, 0, 1) {
            rev[i][m] = r; rev[m + i][m] = rev[m][m] ^ r;
            int now = calc(i, m) + calc(i + m, m);
            rep(j, 1, m - 1) {
               int x = 0;
               rep(c, 0, 1) {
                  rev[i][j] = c;
                  rev[i][j + m] = rev[i][j] ^ rev[i][m];
                  rev[i + m][j] = rev[i][j] ^ rev[m][j];
                  rev[i + m][j + m] = rev[i + m][j] ^ rev[i + m][m];
                  x = max(x, calc(i, j) + calc(i, j + m) + calc(i + m, j) + calc(i + m, j + m));
               }
               now += x;
            }
            res = max(res, now);
         }
         cur += res;
      }
      ans = max(ans, cur);
   }
   printf("%d\n", ans);
   return 0;
}
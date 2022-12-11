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

const int M = 255;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int n, q, len[5], f[M][M][M], r[N][26];
char s[N], t[4][M];
int main() {
   scanf("%d%d%s", &n, &q, s + 1);
   rep(i, 0, 25) r[n + 1][i] = r[n + 2][i] = n + 2;
   per(i, n, 1) {
      s[i] -= 'a';
      rep(j, 0, 25) r[i][j] = s[i] == j ? i : r[i + 1][j];
   }
   f[0][0][0] = 0;
   char op[5], ch[5];
   rep(i, 1, q) {
      int x; scanf("%s%d", op, &x);
      if(*op == '+') {
         scanf("%s", ch);
         t[x][++ len[x]] = *ch - 'a';
         rep(i, x == 1 ? len[1] : 0, len[1])
            rep(j, x == 2 ? len[2] : 0, len[2])
               rep(k, x == 3 ? len[3] : 0, len[3]) {
                  f[i][j][k] = n + 1;
                  if(i) f[i][j][k] = min(f[i][j][k], r[ f[i - 1][j][k] + 1 ][t[1][i]]);
                  if(j) f[i][j][k] = min(f[i][j][k], r[ f[i][j - 1][k] + 1 ][t[2][j]]);
                  if(k) f[i][j][k] = min(f[i][j][k], r[ f[i][j][k - 1] + 1 ][t[3][k]]);
               }
      }
      if(*op == '-') len[x] --;
      puts(f[len[1]][len[2]][len[3]] <= n ? "YES" : "NO");
   }
   return 0;
}
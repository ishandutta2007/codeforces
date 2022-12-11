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

const int N = 200 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int n, m, lx = N, ly = N, rx, ry;
char s[N][N];
int main() {
   scanf("%d%d", &n, &m);
   rep(i, 1, n) {
      scanf("%s", s[i] + 1);
      rep(j, 1, m) if(s[i][j] == 'B') {
         lx = min(lx, i); ly = min(ly, j);
         rx = max(lx, i); ry = max(ly, j);
      }
   }
   printf("%d %d\n", (lx + rx) / 2, (ly + ry) / 2);
   return 0;
}
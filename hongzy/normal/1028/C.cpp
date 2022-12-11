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

const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 2e9 + 10;

int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
struct node {
   int l, r;
   node inc(node x) {
      return (node) {max(l, x.l), min(r, x.r)};
   }
} x[N], y[N];
struct pt {
   node x, y;
   bool out() {
      if(x.l <= x.r && y.l <= y.r) {
         printf("%d %d\n", x.l, y.l);
         return 1;
      }
      return 0;
   }
   pt inc(pt b) {
      return {x.inc(b.x), y.inc(b.y)};
   }
} pre[N], suf[N];
int n, m;
int main() {
   scanf("%d", &n);
   int x1, y1, x2, y2;
   rep(i, 1, n) {
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      x[i].l = x1; x[i].r = x2;
      y[i].l = y1; y[i].r = y2;
   }
   pre[0] = suf[n + 1] = {{- INF, INF}, {-INF, INF}};
   rep(i, 1, n) pre[i] = pre[i - 1].inc({x[i], y[i]});
   per(i, n, 1) suf[i] = suf[i + 1].inc({x[i], y[i]});
   rep(i, 1, n) if((pre[i - 1].inc(suf[i + 1])).out()) return 0;
   return 0;
}
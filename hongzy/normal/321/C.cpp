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

const int N = 2e5 + 10;

vector<int> G[N];

int n, sz[N], f[N], size, ans[N], rt, col[N];
bool vis[N];

void findrt(int u, int fa = 0) {
   sz[u] = 1; f[u] = 0;
   for(auto v : G[u]) {
      if(!vis[v] && v != fa) {
         findrt(v, u); sz[u] += sz[v];
         f[u] = max(f[u], sz[v]);
      }
   }
   f[u] = max(f[u], size - sz[u]);
   if(!rt || f[u] < f[rt]) rt = u;
}

void solve(int u, int d = 0) {
   vis[u] = 1; int all = size, szu = sz[u]; col[u] = d + 'A';
   for(auto v : G[u]) {
      if(!vis[v]) {
         size = sz[v] > szu ? all - szu : sz[v]; rt = 0; findrt(v); solve(rt, d + 1);
      }
   }
}

int main() {
   scanf("%d", &n);
   for(int u, v, w, i = 1; i < n; i ++) {
      scanf("%d%d", &u, &v);
      G[u].pb(v); G[v].pb(u);
   }
   size = n; rt = 0; findrt(1); solve(rt);
   rep(i, 1, n) putchar(col[i]), putchar(' ');
   return 0;
}
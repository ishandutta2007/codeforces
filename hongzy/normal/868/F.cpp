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
const ll INF = 1e18;
int n, k, cnt[N], a[N], L = 1, R = 0;
ll g[N], f[N], cur;
void ins(int u) { cur += cnt[u] ++; }
void del(int u) { cur -= -- cnt[u]; }
void gto(int l, int r) {
   while(R < r) ins(a[++ R]);
   while(L > l) ins(a[-- L]);
   while(R > r) del(a[R --]);
   while(L < l) del(a[L ++]);
}
void solve(int l, int r, int ql, int qr) {
   if(l > r) return ;
   int mid = (l + r) >> 1, qmid = 0; f[mid] = INF;
   rep(i, ql, min(qr, mid - 1)) {
      gto(i + 1, mid);
      ll c = g[i] + cur;
      if(f[mid] > c) { f[mid] = c; qmid = i; }
   }
   solve(l, mid - 1, ql, qmid);
   solve(mid + 1, r, qmid, qr);
}
int main() {
   scanf("%d%d", &n, &k);
   rep(i, 1, n) scanf("%d", a + i);
   fill(g + 1, g + n + 1, INF); g[0] = 0;
   rep(i, 1, k) {
      f[0] = INF;
      solve(1, n, 0, n - 1);
      copy(f, f + n + 1, g);
   }
   printf("%lld\n", f[n]);
   return 0;
}
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

const int N = 1e5 + 10;
int n, s, l, a[N], ans, dp[N << 2];
int st[N][20], st2[N][20], lg[N];
void build() {
   rep(i, 1, n) st[i][0] = st2[i][0] = a[i];
   rep(i, 2, n) lg[i] = lg[i >> 1] + 1;
   rep(j, 1, lg[n]) rep(i, 1, n - (1 << j) + 1) {
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      st2[i][j] = min(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);
   }
}
int query(int l, int r) {
   int k = lg[r - l + 1];
   return max(st[l][k], st[r - (1 << k) + 1][k]);
}
int query2(int l, int r) {
   int k = lg[r - l + 1];
   return min(st2[l][k], st2[r - (1 << k) + 1][k]);
}
void build(int u, int l, int r) {
   if(l == r) { dp[u] = l == 0 ? 0 : N; return ; }
   int mid = (l + r) >> 1;
   build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
   dp[u] = min(dp[u << 1], dp[u << 1 | 1]);
}
void modify(int u, int l, int r, int qp, int v) {
   if(l == r) return dp[u] = v, (void) 0;
   int mid = (l + r) >> 1;
   if(qp <= mid) modify(u << 1, l, mid, qp, v);
   else modify(u << 1 | 1, mid + 1, r, qp, v);
   dp[u] = min(dp[u << 1], dp[u << 1 | 1]);
}
int querym(int u, int l, int r, int ql, int qr) {
   if(l == ql && r == qr) return dp[u];
   int mid = (l + r) >> 1;
   if(qr <= mid) return querym(u << 1, l, mid, ql, qr);
   else if(ql > mid) return querym(u << 1 | 1, mid + 1, r, ql, qr);
   else {
      return min(querym(u << 1, l, mid, ql, mid),
      querym(u << 1 | 1, mid + 1, r, mid + 1, qr));
   }
}
int find(int u) {
   int l = 1, r = u;
   while(l <= r) {
      int mid = (l + r) >> 1;
      if(query(mid, u) - query2(mid, u) <= s) r = mid - 1;
      else l = mid + 1;
   }
   return r + 1;
}
int main() {
   scanf("%d%d%d", &n, &s, &l);
   rep(i, 1, n) scanf("%d", a + i);
   build(); build(1, 0, n); int f = 0;
   rep(i, 1, n) {
      int x = find(i); //[x - 1, i - l] 
      if(x - 1 > i - l) {
         f = N; continue ;
      }
      f = querym(1, 0, n, x - 1, i - l) + 1;
      if(f > N) {
         f = N; continue ;
      }
      modify(1, 0, n, i, f);
   }
   printf("%d\n", f >= N ? -1 : f);
   return 0;
}
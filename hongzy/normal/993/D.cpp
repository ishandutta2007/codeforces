#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
 
typedef long double db;
typedef long long ll;

const int N = 60;
const db INF = 1e17;

struct node {
   int a, b;
} a[N];
int n;
db curk;
bool cmp(node x, node y) {
   if(x.a != y.a) return x.a > y.a;
   return x.a - curk * x.b - (y.a - curk * y.b) < -1e-10;
}
db dp[N][N], s[N];
bool check(db k) {
   curk = k; sort(a + 1, a + n + 1, cmp);
   rep(i, 1, n) s[i] = s[i - 1] + a[i].a - k * a[i].b;
   rep(i, 0, n) rep(j, 0, n) dp[i][j] = INF;
   dp[0][0] = 0;
   for(int i = 1, j; i <= n; i = j + 1) {
      j = i;
      while(j < n && a[j + 1].a == a[j].a) j ++;
      rep(k, 0, i - 1) if(dp[i - 1][k] < INF) {
         rep(u, 0, j - i + 1) {
            if(j - i + 1 - u <= k) {
               int t = k - (j - i + 1 - u) + u;
               dp[j][t] = min(dp[j][t], dp[i - 1][k] + s[i - 1 + u] - s[i - 1]);
            }
         }
      }
   }
   rep(i, 0, n) if(dp[n][i] <= 0) return 1;
   return 0;
}
int main() {
   scanf("%d", &n);
   rep(i, 1, n) scanf("%d", &a[i].a);
   rep(i, 1, n) scanf("%d", &a[i].b);
   db l = 0, r = 2e8, mid;
   while(r - l > 1e-7) {
      mid = (l + r) / 2;
      if(check(mid)) r = mid;
      else l = mid;
   }
   ll res = (ll) ceil(l * 1000);
   printf("%lld\n", res);
   return 0;
}
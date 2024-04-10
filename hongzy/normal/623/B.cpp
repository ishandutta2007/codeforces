#include <functional>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair

typedef double db;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 10;
const ll INF = 1e18;
int n, a[N], p[N], c;
ll ans = INF, ca, cb, dp[N][3];
void divide(int x) {
   for(int i = 2; i * i <= x; i ++) if(x % i == 0) {
      p[++ c] = i;
      while(x % i == 0) x /= i;
   }
   if(x > 1) p[++ c] = x;
}
void check(int p) {
   dp[0][0] = 0; dp[0][1] = dp[0][2] = INF;
   rep(i, 1, n) {
      ll cost = a[i] % p == 0 ? 0 : ((a[i] % p == 1 || a[i] % p == p - 1) ? cb : INF);
      dp[i][0] = dp[i - 1][0] + cost;
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + ca;
      dp[i][2] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + cost;
      rep(j, 0, 2) dp[i][j] = min(dp[i][j], INF);
   }
   rep(i, 0, 2) ans = min(ans, dp[n][i]);
}
int main() {
   scanf("%d%lld%lld", &n, &ca, &cb);
   rep(i, 1, n) scanf("%d", a + i);
   rep(i, -1, 1) divide(a[1] + i), divide(a[n] + i);
   sort(p + 1, p + c + 1); c = unique(p + 1, p + c + 1) - p - 1;
   rep(i, 1, c) check(p[i]);
   printf("%lld\n", ans);
   return 0;
}
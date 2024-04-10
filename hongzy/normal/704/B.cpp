#include <cstring>
#include <cstdio>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
template<typename T> inline void chkmin(T &a, const T &b) { if(a > b) a = b; }
template<typename T> inline void chkmax(T &a, const T &b) { if(a < b) a = b; }
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
int s, t, n, x[N], a[N], b[N], c[N], d[N];
ll dp[2][N];
int main() {
   scanf("%d%d%d", &n, &s, &t);
   rep(i, 1, n) scanf("%d", x + i);
   rep(i, 1, n) scanf("%d", a + i), a[i] += x[i];
   rep(i, 1, n) scanf("%d", b + i), b[i] -= x[i];
   rep(i, 1, n) scanf("%d", c + i), c[i] += x[i];
   rep(i, 1, n) scanf("%d", d + i), d[i] -= x[i];
   int cur = 0; memset(dp, 0x0f, sizeof dp); dp[0][0] = 0;
   rep(i, 1, n) {
      cur ^= 1; memset(dp[cur], 0x0f, sizeof dp[cur]);
      if(i == s) {
         rep(j, 0, i - 1) {
            chkmin(dp[cur][j + 1], dp[cur ^ 1][j] + d[i]); //s
            if(j && (i == n || j > (t < i))) chkmin(dp[cur][j], dp[cur ^ 1][j] + c[i]); //s
         }
      } else if(i == t) {
         rep(j, 0, i - 1) {
            chkmin(dp[cur][j + 1], dp[cur ^ 1][j] + b[i]); //t
            if(j && (i == n || j > (s < i))) chkmin(dp[cur][j], dp[cur ^ 1][j] + a[i]); //t
         }
      } else {
         rep(j, 0, i - 1) {
            chkmin(dp[cur][j + 1], dp[cur ^ 1][j] + b[i] + d[i]); //i
            if(j > (t < i)) chkmin(dp[cur][j], dp[cur ^ 1][j] + a[i] + d[i]); //i
            if(j > (s < i)) chkmin(dp[cur][j], dp[cur ^ 1][j] + b[i] + c[i]); //i
            if(j >= 2 && (i == n || j > (s < i) + (t < i))) chkmin(dp[cur][j - 1], dp[cur ^ 1][j] + a[i] + c[i]); //i
         }
      }
   }
   printf("%lld\n", dp[cur][1]);
   return 0;
}
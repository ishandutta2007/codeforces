#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
template<typename T>
void chkmin(T &x, const T &y) { if(x > y) x = y; }
const int N = 1e4 + 5, INF = 2 * N;
char s[N], t[N];
short dp[N][N], a[N];
int n, m;
int main() {
   scanf("%s%s", s + 1, t + 1);
   n = strlen(s + 1); m = strlen(t + 1);
   for(int i = 1; i <= n; i ++) {
      int y = 0;
      for(int j = i; j <= n; j ++) {
         if(s[j] == '.') {
            if(!y) break ;
            else {
               y --; a[i] ++;
               if(!y) break ;
            }
         } else {
            a[i] ++; y ++;
         }
      }
      if(y) a[i] = 0;
      // printf("%d ", a[i]);
   }
   for(int i = 0; i <= n; i ++) fill(dp[i], dp[i] + m + 1, INF);
   dp[0][0] = 0;
   for(int i = 0; i <= n; i ++) {
      for(int j = 0; j <= m; j ++) if(dp[i][j] < INF) {
         if(i < n) chkmin(dp[i + 1][j], short(dp[i][j] + 1));
         if(i < n && j < m && s[i + 1] == t[j + 1]) chkmin(dp[i + 1][j + 1], dp[i][j]);
         if(j && i < n && s[i + 1] == '.') chkmin(dp[i + 1][j - 1], dp[i][j]);
         if(a[i + 1]) chkmin(dp[i + a[i + 1]][j], dp[i][j]);
      }
   }
   printf("%d\n", (int) dp[n][m]);
   return 0;
}
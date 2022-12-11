#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 105;
const int mo = 1e9 + 9;

void upd(int &x, const int &y) {
   (x += y) >= mo ? x -= mo : 0;
}

namespace ac {

int ch[N][4], fail[N], id = 1, tag[N];
int dir(char c) {
   if(c == 'A') return 0;
   if(c == 'T') return 1;
   if(c == 'G') return 2;
   return 3;
}
void ins(char *s) {
   int u = 1, l = 0;
   for(; *s; s ++) {
      int &v = ch[u][dir(*s)];
      u = v ? v : v = ++ id; l ++;
   }
   tag[u] = l;
}
void build() {
   static int q[N];
   int hd = 0, bk = 0, v; fail[1] = 1;
   for(int i = 0; i < 4; i ++)
      if(v = ch[1][i]) {
         q[bk ++] = v; fail[v] = 1;
      } else ch[1][i] = 1;
   while(hd < bk) {
      int u = q[hd ++];
      tag[u] = max(tag[u], tag[fail[u]]);
      for(int i = 0; i < 4; i ++)
         if(v = ch[u][i]) {
            q[bk ++] = v; fail[v] = ch[fail[u]][i]; 
         } else ch[u][i] = ch[fail[u]][i];
   }
}
int dp[1010][11][N];
int sol(int n) {
   dp[0][0][1] = 1;
   for(int i = 0; i < n; i ++) {
      for(int j = 0; j <= 10; j ++) {
         for(int k = 1; k <= id; k ++) if(dp[i][j][k]) {
            for(int d = 0; d < 4; d ++) {
               int v = ch[k][d];
               if(tag[v] > j) upd(dp[i + 1][0][v], dp[i][j][k]);
               else if(j != 10) upd(dp[i + 1][j + 1][v], dp[i][j][k]);
            }
         }
      }
   }
   int ans = 0;
   for(int i = 1; i <= id; i ++)
      upd(ans, dp[n][0][i]);
   return ans;
}

}

int main() {
   static char s[N];
   int n, m; scanf("%d%d", &m, &n);
   for(int i = 1; i <= n; i ++) {
      scanf("%s", s); ac::ins(s);
   }
   ac::build();
   printf("%d\n", ac::sol(m));
   return 0;
}
#include <algorithm>
#include <cstdio>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define fs first
#define sc second
#define mp make_pair
typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n, m, q, B, c, L[N], R[N];
pii dp[N][12];
char s[N][12];
bool dead(int x, int y) {
   return (s[x][y] == '<' && s[x][y - 1] == '>') || (s[x][y] == '>' && s[x][y + 1] == '<');
}
void build(int u) {
   rep(i, L[u], R[u]) {
      rep(j, 1, m) {
         if(dead(i, j)) dp[i][j] = mp(-1, -1);
         else if(s[i][j] == '^') dp[i][j] = i == L[u] ? mp(i - 1, j) : dp[i - 1][j];
         else if(s[i][j] == '<') dp[i][j] = j == 1 ? mp(i, 0) : dp[i][j - 1];
      }
      per(j, m, 1) if(s[i][j] == '>') dp[i][j] = j == m ? mp(i, m + 1) : dp[i][j + 1];
   }
}
int main() {
   scanf("%d%d%d", &n, &m, &q);
   for(B = 1; B * B <= n; B ++) ;
   // rep(i, 1, n) dp[i][0] = mp(i, 0), dp[i][m + 1] = mp(i, m + 1);
   // rep(i, 1, m) dp[0][i] = mp(0, i), dp[n + 1][i] = mp(n + 1, i);
   rep(i, 1, n) {
      scanf("%s", s[i] + 1);
      int b = (i - 1) / B + 1;
      if(!L[b]) L[b] = i;
      R[b] = i;
   }
   c = (n - 1) / B + 1;
   rep(i, 1, c) build(i);
   char op[8]; int x, y;
   rep(i, 1, q) {
      scanf("%s%d%d", op, &x, &y);
      if(*op == 'C') {
         scanf("%s", op); s[x][y] = *op;
         build((x - 1) / B + 1);
      } else {
         while(x >= 1 && y >= 1 && x <= n && y <= m) {
            pii t = dp[x][y];
            x = t.fs; y = t.sc;
         }
         printf("%d %d\n", x, y);
      }
   }
   return 0;
}
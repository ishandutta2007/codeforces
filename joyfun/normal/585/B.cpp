#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t, n, k;
char str[3][105];
int dp[105][3];

int main() {
    scanf("%d", &t);
    while (t--) {
        memset(dp, 0, sizeof(dp));
        scanf("%d%d", &n, &k);
        for (int i = 0; i < 3; i++) {
            scanf("%s", str[i]);
            if (str[i][0] == 's') {
                dp[0][i] = 1;
                str[i][0] = '.';
            }
        }
       //  for (int j = 0; j < 3; j++)printf("%d %d %d\n", 0, j, dp[0][j]);
        for (int i = 1; i < n; i++) {
           for (int j = 0; j < 3; j++) {
                if (!dp[i - 1][j]) continue;
               if (i % 3 == 0 || i % 3 == 2) {
                   if (str[j][i] == '.') dp[i][j] = 1;
               } else {
                   for (int k = 0; k < 3; k++) {
                        if (j == 0 && k == 2) continue;
                        if (j == 2 && k == 0) continue;
                       if (str[j][i] == '.' && str[k][i] == '.')
                            dp[i][k] = 1;
                   }
               }
           }
          // for (int j = 0; j < 3; j++)printf("%d %d %d\n", i, j, dp[i][j]);
        }
        int flag = 0;
        for (int i = 0; i < 3; i++) if (dp[n - 1][i]) flag = 1;
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}
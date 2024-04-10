#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
char str[maxn], A[3][255];
int n, m, sz[3], nxt[26][maxn], dp[255][255][255];

inline int chkmin(int& x, int y) {
  return x < y ? x : x = y;
}

int main() {
  scanf("%d %d %s", &n, &m, str + 1);
  for (int j = 0; j < 26; j++) {
    for (int i = n, pos = n + 1; ~i; i--) {
      nxt[j][i] = pos;
      if (str[i] == j + 'a') pos = i;
    }
  }
  dp[0][0][0] = 0;
  char op[3]; int x;
  while (m--) {
    scanf("%s %d", op, &x), x--;
    if (*op == '+') {
      scanf("%s", op);
      A[x][++sz[x]] = *op;
      int s0 = x == 0 ? sz[0] : 0;
      int s1 = x == 1 ? sz[1] : 0;
      int s2 = x == 2 ? sz[2] : 0;
      for (int i = s0; i <= sz[0]; i++) {
        for (int j = s1; j <= sz[1]; j++) {
          for (int k = s2; k <= sz[2]; k++) {
            dp[i][j][k] = n + 1;
            if (i && dp[i - 1][j][k] <= n) chkmin(dp[i][j][k], nxt[A[0][i] - 'a'][dp[i - 1][j][k]]);
            if (j && dp[i][j - 1][k] <= n) chkmin(dp[i][j][k], nxt[A[1][j] - 'a'][dp[i][j - 1][k]]);
            if (k && dp[i][j][k - 1] <= n) chkmin(dp[i][j][k], nxt[A[2][k] - 'a'][dp[i][j][k - 1]]);
          }
        }
      }
    } else {
      sz[x]--;
    }
    puts(dp[sz[0]][sz[1]][sz[2]] <= n ? "YES" : "NO");
  }
  return 0;
}
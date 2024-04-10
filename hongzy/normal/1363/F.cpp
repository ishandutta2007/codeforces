#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 2020;
int n, cntS[N][26], cntT[N][26], dp[N][N];
char s[N], t[N];
int main() {
  int test;
  scanf("%d", &test);
  rep(T, 1, test) {
    scanf("%d%s%s", &n, s + 1, t + 1);
    rep(i, 0, 25) cntS[n + 1][i] = cntT[n + 1][i] = 0;
    per(i, n, 1) {
      s[i] -= 'a'; t[i] -= 'a';
      rep(j, 0, 25) cntS[i][j] = cntS[i + 1][j] + (s[i] == j);
      rep(j, 0, 25) cntT[i][j] = cntT[i + 1][j] + (t[i] == j);
    }
    bool bk = 0;
    rep(i, 0, 25) if(cntS[1][i] ^ cntT[1][i]) bk = 1, i = 25;
    if(bk) { puts("-1"); continue; }
    rep(i, 0, n) dp[0][i] = 0;
    rep(i, 1, n) {
      rep(j, i, n) {
        if(s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1];
        else {
          dp[i][j] = dp[i - 1][j] + 1;
          if(j > i && cntS[i + 1][t[j]] > cntT[j + 1][t[j]])
            dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
      }
    }
    printf("%d\n", dp[n][n]);
  }
  return 0;
}
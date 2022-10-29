// KINGPONYHEAD
# include<bits/stdc++.h>

using namespace std;

const int N = 100000 + 77;
char S[N];
int n , dp[N][2][2];
inline void Test() {
   scanf("%s" , S + 1);
   n = strlen(S + 1);
   if(n <= 1) {
      printf("0\n");
      return ;
   }
   dp[2][0][0] = 0;
   if(S[1] == S[2])
      dp[2][0][0] = N;
   dp[2][1][0] = dp[2][0][1] = 1;
   dp[2][1][1] = 2;
   for(int i = 3;i <= n;++ i) {
      dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = N;
      for(int a = 0;a < 2;++ a)
         for(int b = 0;b < 2;++ b)
            for(int c = 0;c < 2;++ c) {
               if(S[i] == S[i - 1] && a == 0 && b == 0)
                  continue ;
               if(S[i] == S[i - 2] && a == 0 && c == 0)
                  continue ;
               dp[i][a][b] = min(dp[i][a][b] , dp[i - 1][b][c] + a);
            }
   }
   printf("%d\n" , min(min(dp[n][0][0] , dp[n][0][1]) , min(dp[n][1][0] , dp[n][1][1])));
   for(int i = 0;i <= n;++ i)
      for(int j = 0;j < 2;++ j)
         for(int k = 0;k < 2;++ k)
            dp[i][j][k] = 0;
}
int main() {
   int te;
   scanf("%d"  ,& te);
   while(te --)
      Test();
   return 0;
}
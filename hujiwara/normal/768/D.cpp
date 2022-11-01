#include <bits/stdc++.h>
using namespace std;

const long double EPS=0.5e-10;

int main()
{
  int k,q;
  scanf("%d%d",&k,&q);
  static double dp[10100][1010]={0};
  dp[0][0]=1.;
  for(int i=0;i+1<10100;i++){
    for(int j=0;j<=k;j++){
      dp[i+1][j]+=dp[i][j]*j/k;
      dp[i+1][j+1]+=dp[i][j]*(k-j)/k;
    }
  }
  while(q--){
    double p;
    scanf("%lf",&p);
    p/=2000;
    int R=0;
    while(dp[R][k]<p-EPS){
      R++;
    }
    printf("%d\n",R);
  }
  return 0;
}
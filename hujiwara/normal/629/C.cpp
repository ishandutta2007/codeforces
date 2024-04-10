#include <cstdio>

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int s=n-m;
  char S[100010];
  scanf("%s",S);
  int M=0,MM=0;
  for(int i=0;i<m;i++){
    if(S[i]=='('){
      M++;
    }
    else{
      M--;
    }
    if(MM>M){
      MM=M;
    }
  }
  long long mod=1000000007ll;
  static long long dp[2010][2010]={0};
  dp[0][0]=1;
  for(int i=1;i<=s;i++){
    dp[i][0]=dp[i-1][1];
    for(int j=1;j<=i;j++){
      dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%mod;
    }
  }
  long long ans=0ll;
  for(int i=0;i<=s;i++){
    for(int j=-MM;j<=i&&j+M<=s-i;j++){
      ans+=dp[i][j]*dp[s-i][j+M]%mod;
      ans%=mod;
    }
  }
  printf("%d\n",(int)ans);
  return 0;
}
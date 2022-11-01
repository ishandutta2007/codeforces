#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static char s[20][100010];
  for(int i=0;i<n;i++){
    scanf("%s",s+i);
  }
  static int M[100000];
  for(int j=0;j<m;j++){
    M[j]=0;
    for(int i=0;i<n;i++){
      M[j]|=(s[i][j]-'0')<<i;
    }
  }
  static int dp[21][1<<20]={0};
  static int al[21][1<<20]={0};
  for(int j=0;j<m;j++){
    dp[0][M[j]]++;
  }
  for(int I=0;I<1<<n;I++){
    for(int i=0;i<n;i++){
      dp[1][I]+=dp[0][I^(1<<i)];
    }
  }
  for(int k=2;k<=n;k++){
    for(int I=0;I<1<<n;I++){
      dp[k][I]=0;
      for(int i=0;i<n;i++){
	dp[k][I]+=dp[k-1][I^(1<<i)];
      }
      dp[k][I]+=(k-2-n)*dp[k-2][I];
      dp[k][I]/=k;
    }
  }
  int ans=n*m;
  for(int I=0;I<1<<n;I++){
    int S=0;
    for(int k=0;k<=n;k++){
      S+=min(k,n-k)*dp[k][I];
    }
    ans=min(ans,S);
  }
  printf("%d\n",ans);
  return 0;
}
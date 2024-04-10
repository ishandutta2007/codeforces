#include <bits/stdc++.h>
using namespace std;

void upmin(int &a,int b){a=min(a,b);}

const int INF=1000000000;

int main()
{
  int n,k,s;
  scanf("%d%d%d",&n,&k,&s);
  int q[150];
  for(int i=0;i<n;i++){
    scanf("%d",q+i);
  }
  static int dp[2][151][150*149/2+1];
  bool b=0;
  dp[b][0][0]=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<=i+1;j++){
      for(int x=0;x<=i*(i+1)/2;x++){
	dp[!b][j][x]=INF;
      }
    }
    for(int j=0;j<=i;j++){
      for(int x=0;x<=i*(i-1)/2;x++){
	//printf("%d %d %d %d\n",i,j,x,dp[b][j][x]);
	upmin(dp[!b][j][x],dp[b][j][x]);
	upmin(dp[!b][j+1][x+max(0,i-j)],dp[b][j][x]+q[i]);
      }
    }
    b=!b;
  }
  int ans=INF;
  for(int x=0;x<=min(s,n*(n-1)/2);x++){
    upmin(ans,dp[b][k][x]);
  }
  printf("%d\n",ans);
  return 0;
}
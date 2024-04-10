#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  char C[16][2];
  int r[16],b[16];
  int SR=0ll,SB=0ll;
  for(int i=0;i<n;i++){
    scanf("%s%d%d",C[i],r+i,b+i);
    SR+=r[i];
    SB+=b[i];
  }
  static int dp[1<<16][300];
  int N=n*(n+1)/2;
  for(int i=0;i<(1<<n);i++){
    for(int j=0;j<=N;j++){
      dp[i][j]=-1000;
    }
  }
  dp[0][0]=0ll;
  for(int I=0;I<(1<<n);I++){
    int R=0,B=0;
    for(int i=0;i<n;i++){
      if((I>>i)&1){
	if(C[i][0]=='R'){
	  R++;
	}
	else{
	  B++;
	}
      }
    }
    for(int i=0;i<n;i++){
      if((I>>i)&1){
	continue;
      }
      int J=I|(1<<i);
      int rr=min(r[i],R),bb=min(b[i],B);
      for(int j=0;j<=N-rr;j++){
	dp[J][j+rr]=max(dp[J][j+rr],dp[I][j]+bb);
      }
    }
  }
  int ans=max(SR,SB);
  for(int j=0;j<=N;j++){
    if(dp[(1<<n)-1][j]>=0){
      ans=min(ans,max(SR-j,SB-dp[(1<<n)-1][j]));
    }
  }
  printf("%d\n",ans+n);
  return 0;
}
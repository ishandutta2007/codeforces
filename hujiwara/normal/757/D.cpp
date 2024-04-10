#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007ll;
void ad(long long &a,long long b){a+=b;a%=mod;}

int main()
{
  int n;
  scanf("%d",&n);
  char s[80];
  scanf("%s",s);
  static long long dp[6][1<<20]={0};
  for(int i=0;i<6;i++){
    dp[i][0]=1;
  }
  static bool K[1<<20];
  for(int b=1;b<=20;b++){
    K[(1<<b)-1]=1;
  }
  long long ans=0;
  for(int i=0;i<n;i++){
    for(int I=0;I<1<<20;I++){
      if(dp[i%6][I]==0){
	continue;
      }
      if(s[i]=='1'){
	int r=0;
	for(int k=0;k<5&&i+k<n;k++){
	  r=2*r+(s[i+k]-'0');
	  if(0<r&&r<=20){
	    int J=(I|(1<<(r-1)));
	    ad(dp[(i+k+1)%6][J],dp[i%6][I]);
	    if(K[J]){
	      ad(ans,dp[i%6][I]);
	    }
	  }
	}
      }
      else{
	ad(dp[(i+1)%6][I],dp[i%6][I]);
      }
      dp[i%6][I]=0;
    }
    dp[i%6][0]=1;
  }
  printf("%lld\n",ans);
  return 0;
}
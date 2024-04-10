#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int M=409;
int n,ans=26*26;
int a[M];
int dp[M][M][3],pr[M][M][3],sum[M][M];
void add(int &x,int y){x=x+y;if(x>mod)x-=mod;if(x<0)x+=mod;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=26;++i)scanf("%d",&a[i]);
	dp[1][0][1]=dp[0][1][2]=1;
	dp[0][0][0]=24;
	for(int i=3;i<=n;++i)ans=25ll*ans%mod;
	for(int i=2;i<=n;++i){
		memcpy(pr,dp,sizeof(dp));
		memset(dp,0,sizeof(dp));
		for(int j=0;j<i;++j)
		for(int k=0;k<i-j;++k){
			if(n/2+1==i){
				dp[j][k][0]=24ll*((pr[j][k][0]+pr[j][k][1])%mod+pr[j][k][2])%mod;
				dp[j+1][k][1]=((pr[j][k][0]+pr[j][k][1])%mod+pr[j][k][2])%mod;
				dp[j][k+1][2]=((pr[j][k][0]+pr[j][k][1])%mod+pr[j][k][2])%mod;
				continue;
			}
			dp[j][k][0]=((24ll*pr[j][k][1]%mod+24ll*pr[j][k][2]%mod)%mod+23ll*pr[j][k][0]%mod)%mod;
			dp[j+1][k][1]=(pr[j][k][0]+pr[j][k][2])%mod;
			dp[j][k+1][2]=(pr[j][k][0]+pr[j][k][1])%mod;
		}
	}
	for(int j=n;j>=0;--j)
	for(int k=n;k>=0;--k){
		for(int l=0;l<3;++l){
			add(sum[j][k],dp[j][k][l]);
		}
		add(sum[j][k],sum[j][k+1]);
		add(sum[j][k],sum[j+1][k]);
		add(sum[j][k],-sum[j+1][k+1]);
	}
	for(int i=1;i<=26;++i)add(ans,-sum[a[i]+1][0]);
	for(int j=1;j<=25;++j){
		for(int k=j+1;k<=26;++k){
			add(ans,sum[a[j]+1][a[k]+1]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
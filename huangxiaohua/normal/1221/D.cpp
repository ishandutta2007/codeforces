#include<bits/stdc++.h>
using namespace std;
 
long long dp[300500][3];
int i,t,n,sb[300500][2];
 
 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d%d",&sb[i][0],&sb[i][1]);
		}
		for(i=1;i<=n;i++){
			if(sb[i][0]-sb[i-1][0]==2){
				dp[i][2]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+sb[i][1]*2;
				dp[i][1]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+sb[i][1]*1;
				dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
				continue;
			}
			if(sb[i][0]-sb[i-1][0]==1){
				dp[i][2]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+sb[i][1]*2;
				dp[i][1]=min(dp[i-1][0],dp[i-1][1])+sb[i][1]*1;
				dp[i][0]=min(dp[i-1][0],dp[i-1][2]);
				continue;
			}
			if(sb[i][0]-sb[i-1][0]==0){
				dp[i][2]=min(dp[i-1][0],dp[i-1][1])+sb[i][1]*2;
				dp[i][1]=min(dp[i-1][0],dp[i-1][2])+sb[i][1]*1;
				dp[i][0]=min(dp[i-1][1],dp[i-1][2]);
				continue;
			}
			if(sb[i][0]-sb[i-1][0]==-1){
				dp[i][2]=min(dp[i-1][0],dp[i-1][2])+sb[i][1]*2;
				dp[i][1]=min(dp[i-1][1],dp[i-1][2])+sb[i][1]*1;
				dp[i][0]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
				continue;
			}
			if(sb[i][0]-sb[i-1][0]==-2){
				dp[i][2]=min(dp[i-1][1],dp[i-1][2])+sb[i][1]*2;
				dp[i][1]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+sb[i][1]*1;
				dp[i][0]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
				continue;
			}
			else{
				dp[i][2]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+sb[i][1]*2;
				dp[i][1]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+sb[i][1]*1;
				dp[i][0]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
			}
		}
		printf("%lld\n",min(min(dp[n][0],dp[n][1]),dp[n][2]));
	}
}
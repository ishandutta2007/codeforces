#include<bits/stdc++.h>
using namespace std;

int i,n,t,q;
long long res,a[300500],dp[300500][2];

int main(){
	scanf("%d",&t);
	
	while(t--){
		scanf("%d%d",&n,&q);res=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			dp[i][0]=dp[i][1]=0;
		}
		for(i=1;i<=n;i++){
			dp[i][0]=max(max(dp[i-1][1]+a[i],dp[i-1][0]),a[i]);
			dp[i][1]=max(dp[i-1][0]-a[i],dp[i-1][1]);
			//printf("%d %d\n",dp[i][0],dp[i][1]);
		}
		printf("%lld\n",max(dp[n][1],dp[n][0]));
	}
}
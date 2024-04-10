#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,a[5050],b[5050];
long long dp[5050],res,sb1,sb2;

int main(){
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof(dp));res=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){scanf("%d",&b[i]);}
		for(i=1;i<=n;i++){scanf("%d",&a[i]);}
		for(i=1;i<=n;i++){
			for(j=i-1;j>=1;j--){
				if(b[i]==b[j]){continue;}
				sb1=max(dp[i],dp[j]+abs(a[i]-a[j]));
				sb2=max(dp[j],dp[i]+abs(a[i]-a[j]));
				dp[i]=sb1;dp[j]=sb2;
			}
		}
		for(i=1;i<=n;i++){res=max(res,dp[i]);}
		printf("%lld\n",res);
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<int,int> mp;

int i,j,k,t,n,res,m,dp[200500],tmp;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);m=res=0;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			dp[k]++;
		}
		
		for(i=200000;i>=1;i--){
			tmp=dp[i];
			for(j=2;i*j<=200000;j++){
				dp[i]=max(dp[i],tmp+dp[i*j]);
			}
			res=max(res,dp[i]);
		}
		printf("%d\n",n-res);
	}
}
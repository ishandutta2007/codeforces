#include<bits/stdc++.h>
typedef long long ll;
const int MAXN=50;
int n;
ll k;
int limit[MAXN+5];
ll sum;
ll dp[MAXN/2+5][2][2];
void work(){
	dp[0][0][0]=1;
	for(int i=1;i<=n/2;++i){
		memset(dp[i],0,sizeof(dp[i]));
		if(limit[i]!=1&&limit[n-i+1]!=1){
			dp[i][0][1]+=dp[i-1][0][0]+dp[i-1][0][1];
			dp[i][1][1]+=dp[i-1][1][0]+dp[i-1][1][1];
		}
		if(limit[i]!=1&&limit[n-i+1]!=0){
			dp[i][1][0]+=dp[i-1][0][0]+dp[i-1][1][0];
			dp[i][1][1]+=dp[i-1][0][1]+dp[i-1][1][1];
		}
		if(limit[i]!=0&&limit[n-i+1]!=1){
			dp[i][1][0]+=dp[i-1][1][0];
			dp[i][1][1]+=dp[i-1][1][1];
		}
		if(limit[i]!=0&&limit[n-i+1]!=0){
			dp[i][0][1]+=dp[i-1][0][1];
			dp[i][1][1]+=dp[i-1][1][1];
		}
	}
	if(n&1)
		if(limit[n/2+1]==0)
			sum=dp[n/2][0][0]+dp[n/2][1][0]+dp[n/2][0][1]+dp[n/2][1][1];
		else if(limit[n/2+1]==1)
			sum=dp[n/2][0][1]+dp[n/2][1][1];
		else
			sum=dp[n/2][0][0]+dp[n/2][1][0]+dp[n/2][0][1]*2+dp[n/2][1][1]*2;
	else
		sum=dp[n/2][0][0]+dp[n/2][1][0]+dp[n/2][0][1]+dp[n/2][1][1];
}
int main(){
	memset(limit,-1,sizeof(limit));
	scanf("%d%I64d",&n,&k);
	++k;
	limit[1]=0;
	work();
	if(sum<k){
		puts("-1");
		return 0;
	}
	for(int i=2;i<=n;++i){
		limit[i]=0;
		work();
		if(sum<k){
			k-=sum;
			limit[i]=1;
		}
	}
	for(int i=1;i<=n;++i)
		putchar('0'+limit[i]);
	return 0;
}
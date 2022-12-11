#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long dp[5100][5100];
int n,a[5100],b[5100],c[5100],d[5100],s,t,tot,x[5100];
const long long inf=1e16;
long long solve(){
	int tot=0; long long ans=inf;
	memset(dp,0x3f,sizeof dp); dp[0][0]=0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=n;j++)
			if (dp[i-1][j]<=inf){
				if (i==s){
					int S=j,T=tot+S;
					if (T) dp[i][S]=min(dp[i][S],dp[i-1][j]+x[i]+c[i]);
					dp[i][S+1]=min(dp[i][S+1],dp[i-1][j]-x[i]+d[i]);
				} else if (i==t){
					int S=j,T=tot+S;
					if (S) dp[i][S-1]=min(dp[i][S-1],dp[i-1][j]+x[i]+a[i]);
					dp[i][S]=min(dp[i][S],dp[i-1][j]-x[i]+b[i]);
				} else {
					int S=j,T=tot+S;
					if (S) dp[i][S]=min(dp[i][S],dp[i-1][j]+a[i]+d[i]);
					if (T) dp[i][S]=min(dp[i][S],dp[i-1][j]+b[i]+c[i]);
					if (T&&S) dp[i][S-1]=min(dp[i][S-1],dp[i-1][j]+x[i]*2+a[i]+c[i]);
					dp[i][S+1]=min(dp[i][S+1],dp[i-1][j]-x[i]*2+b[i]+d[i]);
				}
			}
		if (i==s) tot--;
		if (i==t) tot++;
		if (i!=n&&tot==0) dp[i][0]=inf+1e9;
	}
	return dp[n][0];
}
int main(){
	scanf("%d%d%d",&n,&s,&t);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);
	printf("%I64d\n",solve());
	return 0;
}
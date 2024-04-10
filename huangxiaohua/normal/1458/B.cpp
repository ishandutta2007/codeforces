#include<bits/stdc++.h>
using namespace std;

bool vis[105][10050];
int i,j,k,m,n,t,dp[105][10050],sum,a[105],b[105],sum2;
double res[105];

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		sum+=b[i]*2;
	}
	dp[0][0]=sum/2;
	vis[0][0]=1;
	for(i=1;i<=n;i++){
		sum2+=a[i];
		for(j=i;j>=1;j--){
			for(k=0;a[i]+k<=sum2+1;k++){
				if(vis[j-1][k]){
					vis[j][k+a[i]]=1;
					dp[j][k+a[i]]=max(dp[j][k+a[i]],dp[j-1][k]+b[i]);
				}
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=100*i;j++){
			res[i]=max(res[i],min(j*1.0,dp[i][j]/2.0));
		}
		printf("%.11lf ",res[i]);
	}
}
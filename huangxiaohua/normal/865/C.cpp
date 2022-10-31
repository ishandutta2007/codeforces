#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize(2)

int i,j,n,k,a[55],b[55],m,t;
double p[55],dp[55][5050],md,l,r,tmp;

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d%d%lf",&a[i],&b[i],&p[i]);
		p[i]/=100;
	}
	l=0;r=1145141919810893364364.0;
	for(i=1;i<=m;i++){
		dp[n+1][i]=i;
	}
	t=100;
	while(t--){
		md=(l+r)/2;
		for(i=n;i>=1;i--){
			for(j=0;j<=m;j++){
				if(i==1){
					if(j+b[i]>m){dp[i][j]=dp[i+1][j+a[i]]+(1-p[i])*(j+b[i])/p[i];}
					else{dp[i][j]=p[i]*dp[i+1][j+a[i]]+(1-p[i])*dp[i+1][j+b[i]];}
					break;
				}
				if(j+a[i]>m){dp[i][j]=j+md;continue;}
				if(j+b[i]>m){
					dp[i][j]=min(j+md,p[i]*dp[i+1][j+a[i]]+(1-p[i])*(j+b[i]+md));
					continue;
				}
				dp[i][j]=min(j+md,p[i]*dp[i+1][j+a[i]]+(1-p[i])*dp[i+1][j+b[i]]);
			}
		}
		
		if(dp[1][0]>md){l=md;}
		else{r=md;}
	}
	printf("%.12lf",dp[1][0]);
}
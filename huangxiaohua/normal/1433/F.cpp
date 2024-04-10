#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,n,t,dp[75][75][75][75],dp2[75][75],res[75][75],a[75][75],k,x,l,m;
 
int main() {
	scanf("%d%d%d",&n,&m,&x);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	for(j=0;j<=m;j++){
		for(l=1;l<=x-1;l++){
			for(i=1;i<=n;i++){
				for(k=0;k<=m/2;k++){
					dp[i][j][k][l]=-999999;
				}
			}
		}
	}
	
	for(i=1;i<=70;i++){
		for(j=1;j<=70;j++){
			dp2[i][j]=-999999;
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			for(k=1;k<=m/2;k++){
				for(l=0;l<=x-1;l++){
					dp[i][j][k][l]=max(dp[i][j-1][k][l],dp[i][j-1][k-1][((l-a[i][j])%x+x)%x]+a[i][j]);
					dp2[i][l]=max(dp2[i][l],dp[i][j][k][l]);
					//printf("%d %d %d %d %d\n",i,j,k,l,dp[i][j][k][l]);
				}
			}
		}
	}
	for(i=1;i<=x-1;i++){
		for(j=0;j<=70;j++){
			res[j][i]=-999999;
		}
	}
	for(i=1;i<=n;i++){
		for(j=0;j<=x-1;j++){
			for(k=0;k<=x-1;k++){
				res[i][(j+k)%x]=max(res[i][(j+k)%x],res[i-1][j]+dp2[i][k]);
			}
			/*printf("dp%d %d %d\n",i,j,dp2[i][j]);
			printf("res%d %d %d\n",i,j,res[i][j]);*/
		}
		
	}
	printf("%d\n",res[n][0]);return 0;
}
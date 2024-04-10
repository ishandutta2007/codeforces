#include <bits/stdc++.h> 
using namespace std;

int dp[205][205][205],n,k,i,j,l,res,jb,jb2;
char sb[666],a,b;

int main(){
	scanf("%d%d\n",&n,&k);
	gets(sb+1);
	a=getchar();b=getchar();
	
	if(a==b){
		for(i=1;i<=n;i++){
			if(sb[i]==a){jb++;}
		}
		jb2=min(n,jb+k);
		printf("%d\n",(jb2-1)*jb2/2);return 0;
	}
	
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			for(l=0;l<=n;l++){
				dp[i][j][l]=-9999999;
			}
		}
	}
	dp[0][0][0]=0;
	for(i=1;i<=n;i++){
		dp[i][0][0]=0;
		for(j=0;j<=k;j++){
			for(l=0;l<=n;l++){
				if(sb[i]==a){
					dp[i][j][l+1]=max(dp[i-1][j][l],dp[i][j][l+1]);
					dp[i][j+1][l]=max(dp[i-1][j][l]+l,dp[i][j+1][l]);
					continue;
				}
				if(sb[i]==b){
					dp[i][j+1][l+1]=max(dp[i-1][j][l],dp[i][j+1][l+1]);
					dp[i][j][l]=max(dp[i-1][j][l]+l,dp[i][j][l]);
					continue;
				}
				else{
					dp[i][j][l]=max(dp[i][j][l],dp[i-1][j][l]);
					dp[i][j+1][l+1]=max(dp[i-1][j][l],dp[i][j+1][l+1]);
					dp[i][j+1][l]=max(dp[i-1][j][l]+l,dp[i][j+1][l]);
				}
			}
		}
	}

	for(j=0;j<=k;j++){
			for(l=0;l<=n;l++){
				res=max(res,dp[n][j][l]);
			}
		}
	printf("%d\n",res);
}
#include<bits/stdc++.h>
int dp[21][21][4];
int n,t;
int ans;
int main(){
	scanf("%d%d",&n,&t);
	for(int i=0;i<4;++i)
		for(int j=i+1;j<4;++j)
			++dp[2][0][j];
	for(int i=3;i<=n;++i)
		for(int j=0;j<=t*2-1;++j)
			for(int k=0;k<4;++k){
				if(j&1)
					for(int l=k+1;l<4;++l)
						dp[i][j][k]+=dp[i-1][j][l]+(j?dp[i-1][j-1][l]:0);
				else
					for(int l=0;l<k;++l)
						dp[i][j][k]+=dp[i-1][j][l]+(j?dp[i-1][j-1][l]:0);
			}
	for(int i=0;i<4;++i)
		ans+=dp[n][t*2-1][i];
	printf("%d\n",ans);
	return 0;
}
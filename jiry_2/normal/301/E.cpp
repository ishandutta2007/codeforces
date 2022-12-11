#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int C[101][101],mo=1e9+7,dp[55][101][101][101],n,m,kk,ans;
int main(){
	scanf("%d%d%d",&n,&m,&kk);
	for (int i=0;i<=n;i++){
		C[i][0]=1;
		for (int j=1;j<=i;j++) C[i][j]=min(C[i-1][j-1]+C[i-1][j],200);
	}
	for (int i=1;i<=n;i++) dp[1][i][i][1]=1;
	for (int i=1;i<=m;i++){
		if (i*2-2>n) break; 
		for (int j=1;j<=n;j++){
			for (int k1=1;k1<=kk;k1++){
				ans=(ans+1ll*dp[i][j][0][k1]*(m-i+1))%mo;
			}
			for (int k=1;k<=j;k++)
				for (int k1=1;k1<=kk;k1++){ 
					if (dp[i][j][k][k1]==0) continue;
					for (int k2=k;k2<=n-j;k2++){
						int k3=k1*C[k2-1][k2-k]; if (k3>kk) continue;
						dp[i+1][j+k2][k2-k][k3]=(dp[i+1][j+k2][k2-k][k3]+dp[i][j][k][k1])%mo;
					}
				}
		}
	}
	cout<<ans<<endl; return 0;
}
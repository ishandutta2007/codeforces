#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int x[600],n,dp[510][510];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<=n+1;i++) dp[i][i-1]=0;
	for (int i=1;i<=n;i++) dp[i][i]=1;
	for (int i=2;i<=n;i++)
		for (int l=1;l<=n-i+1;l++){
			int r=l+i-1; dp[l][r]=1e9;
			int k1=l,k2=r; 
			while (k1<=k2&&x[k1]==x[k2]){
				k1++; k2--; dp[l][r]=min(dp[l][r],dp[k1][k2]+1);
				if (k1<=k2){
					dp[l][r]=min(dp[l][r],min(dp[k1+1][k2],dp[k1][k2-1])+1);
					dp[l][r]=min(dp[l][r],dp[k1][k2]);
				}
			}
			for (int k=l;k<r;k++) if (x[l]==x[k]) dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
		//	cout<<"fa "<<l<<" "<<r<<" "<<dp[l][r]<<endl;
		}
	printf("%d\n",dp[1][n]);
	return 0;
}
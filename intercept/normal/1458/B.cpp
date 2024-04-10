#include<bits/stdc++.h>
using namespace std;
int n;
int b[109],a[109];
double dp[2][109][10009];
bool vis[2][109][10009];
int main(){
	vis[0][0][0]=1;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int o=i&1;
		scanf("%d %d",&b[i],&a[i]);
		for(int k=0;k<=i;++k){
			for(int j=0;j<=10000;++j){
				dp[o][k][j]=0;
				vis[o][k][j]=0;
			}
		}
		for(int k=0;k<=i;++k){
			for(int j=0;j<=10000;++j){
				if(vis[o^1][k][j])dp[o][k][j]=dp[o^1][k][j]+1.0*a[i]/2,vis[o][k][j]=1;
				if(k>=1&&j>=b[i]&&vis[o^1][k-1][j-b[i]]){
					dp[o][k][j]=max(dp[o][k][j],dp[o^1][k-1][j-b[i]]+a[i]);
					vis[o][k][j]=1;
				}
			}
		}
	}
	for(int k=1;k<=n;++k){
		int o=n&1;
		double ma=0;
		for(int j=0;j<=10000;++j)ma=max(ma,min(dp[o][k][j],1.0*j));
		printf("%.9lf ",ma);
	}
	return 0;
}
/*
2
6 5
6 5

*/
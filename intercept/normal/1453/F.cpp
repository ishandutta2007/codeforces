#include<bits/stdc++.h>
using namespace std;
const int M=3009;
int n;
int a[M],dp[M][M];
void work(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		for(int j=0;j<=n;++j){
			dp[i][j]=1e9;
		}
	}
	dp[1][1]=0;
	for(int i=1;i<=n;++i){
		int cnt=0;
		for(int j=i-1;j>=1;--j){
			if(j+a[j]>=i){
				dp[i][j+a[j]]=min(dp[i][j+a[j]],dp[j][i-1]+cnt);
				cnt++;
			}
		}
		for(int j=1;j<=n;++j)dp[i][j]=min(dp[i][j],dp[i][j-1]);
	}
	printf("%d\n",dp[n][n]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int M=2009;
int n,m;
int a[M],b[M],c[M<<1],p[M<<1];
int dp[M<<1][M];
int main(){
	scanf("%d%d",&n,&m);p[0]=n;m+=n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	for(int i=1;i<=m;++i)scanf("%d",&c[i]);
	for(int i=1;i<=n;++i)p[i]=p[i-1]>>1;
	memset(dp,-0X3F,sizeof(dp));
	for(int i=0;i<=m;++i)dp[i][0]=0; 
	for(int i=n;i>=1;--i){
		int o=a[i];
		for(int j=n;j>=1;--j)dp[o][j]=max(dp[o][j],dp[o][j-1]+c[o]-b[i]);
		for(int j=o;j<=m;++j){
			for(int k=0;k<=p[j-o];++k){
				dp[j+1][k/2]=max(dp[j+1][k/2],dp[j][k]+k/2*c[j+1]);
			}
		}
	}
	printf("%d\n",dp[m][0]);
	return 0;
}
/*********************************************************************
	Problem:CF258D
	Author:hydd
	Date:2020/7/14
*********************************************************************/
#include<cstdio>
using namespace std;
int n,m,p[1100];
double ans,dp[1100][1100];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (p[i]>p[j]) dp[i][j]=1;
			else dp[i][j]=0;
	int a,b; double tmp;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		for (int j=1;j<=n;j++)
			if (j!=a&&j!=b){
				tmp=(dp[a][j]+dp[b][j])/2;
				dp[a][j]=tmp; dp[b][j]=tmp;
			}
		for (int j=1;j<=n;j++)
			if (j!=a&&j!=b){
				tmp=(dp[j][a]+dp[j][b])/2;
				dp[j][a]=tmp; dp[j][b]=tmp;
			}
		dp[a][b]=0.5; dp[b][a]=0.5;
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			ans+=dp[i][j];
	printf("%.8lf\n",ans);
	return 0;
}
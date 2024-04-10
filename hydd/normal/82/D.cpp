/*********************************************************************
 * Source
 * ProblemCF82D
 * Authorhydd
 * Date2020/9/8
 * EncodingSimplified Chinese (GB2312)
*********************************************************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
//#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
int n,a[1100],dp[1100][1100];
int dfs(int i,int j){
	if (~dp[i][j]) return dp[i][j];
	if (j==n+1) return dp[i][j]=a[i];
	if (j==n) return dp[i][j]=max(a[i],a[j]);
	dp[i][j]=dfs(j+1,j+2)+max(a[i],a[j]);
	dp[i][j]=min(dp[i][j],dfs(j,j+2)+max(a[i],a[j+1]));
	dp[i][j]=min(dp[i][j],dfs(i,j+2)+max(a[j],a[j+1]));
	return dp[i][j];
}
void print(int i,int j){
	if (j==n+1){ printf("%d\n",i); return;}
	if (j==n){ printf("%d %d\n",i,j); return;}
	if (dp[i][j]==dp[j+1][j+2]+max(a[i],a[j])){
		printf("%d %d\n",i,j);
		print(j+1,j+2); return;
	}
	if (dp[i][j]==dp[j][j+2]+max(a[i],a[j+1])){
		printf("%d %d\n",i,j+1);
		print(j,j+2); return;
	}
	if (dp[i][j]==dp[i][j+2]+max(a[j],a[j+1])){
		printf("%d %d\n",j,j+1);
		print(i,j+2); return;
	}
}
int main(){
	scanf("%d",&n); memset(dp,-1,sizeof(dp));
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	printf("%d\n",dfs(1,2)); print(1,2);
	return 0;
}
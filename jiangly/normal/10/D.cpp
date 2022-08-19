#include<bits/stdc++.h>
const int MAXN=500;
int n,m,ans;
int a[MAXN+5],b[MAXN+5];
int dp[MAXN+5][MAXN+5];
int prev[MAXN+5][MAXN+5];
int p;
int st[MAXN+5],top;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
		scanf("%d",&b[i]);
	a[0]=-1;
	b[0]=-1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[i]!=b[j]){
				dp[i][j]=dp[i-1][j];
				prev[i][j]=j;
			}else
				for(int k=0;k<=j-1;++k)
					if(a[i]>b[k]&&dp[i-1][k]+1>dp[i][j]){
						dp[i][j]=dp[i-1][k]+1;
						prev[i][j]=k;
					}
	for(int i=1;i<=m;++i)
		if(dp[n][i]>ans){
			ans=dp[n][i];
			p=i;
		}
	for(int i=n,q=0;i&&p;q=p,p=prev[i--][p])
		if(p!=q)
			st[++top]=b[p];
	printf("%d\n",ans);
	for(;top;--top)
		printf("%d ",st[top]);
	return 0;
}
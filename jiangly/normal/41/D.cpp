#include<bits/stdc++.h>
const int MAXN=100,MAXK=10;
int n,m,k,ans=-1,p;
int a[MAXN][MAXN];
int dp[MAXN][MAXN][MAXK+1];
bool prev[MAXN][MAXN][MAXK+1];
int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%1d",&a[i][j]);
	for(int i=0;i<m;++i)
		dp[n-1][i][a[n-1][i]%(k+1)]=a[n-1][i];
	for(int i=n-2;i>=0;--i)
		for(int j=0;j<m;++j)
			for(int l=0;l<=k;++l){
				if(j!=0&&dp[i+1][j-1][l]!=-1&&dp[i+1][j-1][l]+a[i][j]>dp[i][j][(l+a[i][j])%(k+1)]){
					dp[i][j][(l+a[i][j])%(k+1)]=dp[i+1][j-1][l]+a[i][j];
					prev[i][j][(l+a[i][j])%(k+1)]=0;
				}
				if(j+1!=m&&dp[i+1][j+1][l]!=-1&&dp[i+1][j+1][l]+a[i][j]>dp[i][j][(l+a[i][j])%(k+1)]){
					dp[i][j][(l+a[i][j])%(k+1)]=dp[i+1][j+1][l]+a[i][j];
					prev[i][j][(l+a[i][j])%(k+1)]=1;
				}
			}
	for(int i=0;i<m;++i)
		if(dp[0][i][0]!=-1&&dp[0][i][0]>ans){
			ans=dp[0][i][0];
			p=i;
		}
	printf("%d\n",ans);
	if(ans!=-1){
		static char st[MAXN];
		int top=0,sum=0;
		for(int i=0;i<n-1;++i){
			st[top++]=prev[i][p][sum]?'L':'R';
			sum=(sum-a[i][p]%(k+1)+k+1)%(k+1);
			p+=st[top-1]=='L'?1:-1;
		}
		printf("%d\n",p+1);
		while(top)
			putchar(st[--top]);
	}
	return 0;
}
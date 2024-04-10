#include<bits/stdc++.h>
using namespace std;
const int M=4009;
int n,m,top;
int a[M],s[M],siz[M],c[M][2];
long long dp[M][M];
void dfs(int u){
	if(!u)return;
	siz[u]++;
	dp[u][1]=1ll*(m-1)*a[u];
	for(auto v:{c[u][0],c[u][1]}){
		dfs(v);
		for(int i=siz[u];i>=0;--i){
			for(int j=siz[v];j>=0;--j){
				dp[u][i+j]=max(dp[u][i+j],dp[u][i]+dp[v][j]-2ll*i*j*a[u]);
			}
		}
		siz[u]+=siz[v];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		while(top&&a[s[top]]>a[i])c[i][0]=s[top],top--;
		c[s[top]][1]=i;
		s[++top]=i;
	}
	dfs(c[0][1]);
	printf("%lld\n",dp[c[0][1]][m]);
	return 0;
}
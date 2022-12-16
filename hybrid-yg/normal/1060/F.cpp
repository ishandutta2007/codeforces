#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,i,u,v,siz[55],head[55],Next[105],adj[105],k;
long double inv[55],dp[55][55],tmp[55],fac[55];
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int fa)
{
	int j,k,l;
	siz[i]=0;
	for(j=head[i];j;j=Next[j])
		if(adj[j]!=fa)
			dfs(adj[j],i);
	dp[i][0]=1;
	for(j=head[i];j;j=Next[j])
		if(adj[j]!=fa)
		{
			for(k=0;k<=siz[i]+siz[adj[j]];++k)
				tmp[k]=0;
			for(k=0;k<=siz[i];++k)
				for(l=0;l<=siz[adj[j]];++l)
					tmp[k+l]=(tmp[k+l]+dp[i][k]*dp[adj[j]][l]*inv[l]*inv[siz[adj[j]]-l]);
			siz[i]+=siz[adj[j]];
			for(k=0;k<=siz[i];++k)
				dp[i][k]=tmp[k];
		}
	for(j=0;j<=siz[i];++j)
		dp[i][j]=dp[i][j]*fac[j]*fac[siz[i]-j];
	if(fa)
	{
		++siz[i];
		for(j=0;j<=siz[i];++j)
			tmp[j]=0;
		for(j=0;j<siz[i];++j)
			for(k=0;k<=siz[i];++k)
				if(k>j)
					tmp[k]=tmp[k]+dp[i][k-1];
				else
					tmp[k]=tmp[k]+dp[i][j]/2;
		for(j=0;j<=siz[i];++j)
			dp[i][j]=tmp[j];
	}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		scanf("%d %d",&u,&v);
		Push(u,v);
		Push(v,u);
	}
	inv[0]=fac[0]=1;
	for(i=1;i<=n;++i)
	{
		inv[i]=inv[i-1]/i;
		fac[i]=fac[i-1]*i;
	}
	for(i=1;i<=n;++i)
	{
		dfs(i,0);
		printf("%.12LF\n",dp[i][0]*inv[n-1]);
	}
}
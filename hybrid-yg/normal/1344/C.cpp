#include<bits/stdc++.h>
using namespace std;
const int N=500005,E=524288;
const int M=1000000007;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int n,i,a[N],f[N],t,j,u[N],v[N],w[N],head[N],Next[N],adj[N],p[N],q[N],l,r,dp[N],ans,k,m;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d",&u[i],&v[i]);
		Push(u[i],v[i]);
		w[max(u[i],v[i])]=1;
		++p[v[i]];
	}
	l=1;
	for(i=1;i<=n;++i)
		if(!p[i])
			q[++r]=i;
	memset(dp,0x7f,sizeof(dp));
	for(i=1;i<=n;++i)
		dp[i]=i;
	while(l<=r)
	{
		for(i=head[q[l]];i;i=Next[i])
		{
			--p[adj[i]];
			dp[adj[i]]=min(dp[adj[i]],dp[q[l]]);
			if(p[adj[i]]==0)
				q[++r]=adj[i];
		}
		++l;
	}
	if(r!=n)
	{
		puts("-1");
		return 0;
	}
	for(i=1;i<=n;++i)
		if(dp[i]<i)
			w[i]=1;
	memset(head,0,sizeof(head));
	k=0;
	for(i=1;i<=m;++i)
	{
		Push(v[i],u[i]);
		++p[u[i]];
	}
	l=1;r=0;
	memset(dp,0x7f,sizeof(dp));
	for(i=1;i<=n;++i)
		if(!p[i])
			q[++r]=i;
	for(i=1;i<=n;++i)
		dp[i]=i;
	while(l<=r)
	{
		for(i=head[q[l]];i;i=Next[i])
		{
			--p[adj[i]];
			dp[adj[i]]=min(dp[adj[i]],dp[q[l]]);
			if(p[adj[i]]==0)
				q[++r]=adj[i];
		}
		++l;
	}
	if(r!=n)
	{
		puts("-1");
		return 0;
	}
	for(i=1;i<=n;++i)
		if(dp[i]<i)
			w[i]=1;
	for(i=1;i<=n;++i)
		ans+=w[i]^1;
	cout<<ans<<endl;
	for(i=1;i<=n;++i)
		putchar(w[i]?'E':'A');
}
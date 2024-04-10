#include<bits/stdc++.h>
using namespace std;
const int N=100005,mod=1e9+7;
int n,a[N],b[N],c[N],vis[N],ans,h,z;
vector<int>e[N];
void dfs(int u)
{
	vis[u]=1;
	h|=c[u];
	z++;
	for(auto v:e[u])
		if(!vis[v])
			dfs(v);
}
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=0;i<=n;i++)
	{
		e[i].clear();
		c[i]=vis[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		c[x]=1;
	}
	for(int i=1;i<=n;i++)
		e[a[i]].push_back(b[i]),e[b[i]].push_back(a[i]);
	ans=1;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			h=z=0;
			dfs(i);
			if(!h&&z>1)
				ans=ans*2%mod;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}
// Hydro submission #62d2a14bb36e4a12382aff48@1657971019859
#include<bits/stdc++.h> 
using namespace std; 
int hd[200001],go[400001],nxt[400001],dis[400001],a[200001],b[200001],p[200001],f[200001],l;
void Add(int u,int v)
{
	nxt[++l]=hd[u],hd[u]=l,go[l]=v;
}
void dfs(int k,int fa)
{
	dis[k]=dis[fa]+1;f[k]=fa;
	for(int i=hd[k];i;i=nxt[i])
	if(go[i]!=fa) dfs(go[i],k);
}
int main()
{
	int n,m,u,v,i;
	cin>>n;m=n-1;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v;
		Add(u,v);
		Add(v,u);
	}
	dfs(1,0);
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(dis[a[i]]<dis[a[i-1]])
		{
			printf("No\n");
			return 0;
		}
		p[a[i]]=i;
		b[i]=f[a[i]];
	}
	l=unique(b+1,b+n+1)-b-1;
	for(i=1;i<=l;i++)
	if(p[b[i]]<p[b[i-1]])
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int n,m,M,i,j,k,a[MAXN],u[MAXN],v[MAXN],h[MAXN],ne[MAXN<<1],p[MAXN<<1],w[MAXN<<1],c[MAXN];
bool dfs(int x)
{
	for(int i=h[x];i;i=ne[i])if(!~c[p[i]])
	{
		c[p[i]]=c[x]^w[i];
		if(!dfs(p[i]))return 0;
	}
	else if(c[p[i]]^w[i]^c[x])return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&j);
		while(j--)
		{
			scanf("%d",&k);
			if(u[k])v[k]=i;
			else u[k]=i;
		}
	}
	for(i=1;i<=m;i++)
	{
		p[++M]=v[i];
		ne[M]=h[u[i]];
		w[M]=!a[i];
		h[u[i]]=M;
		p[++M]=u[i];
		ne[M]=h[v[i]];
		w[M]=!a[i];
		h[v[i]]=M;
	}
	memset(c,-1,sizeof(c));
	for(i=1;i<=n;i++)if(!~c[i])
	{
		c[i]=0;
		if(!dfs(i))
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
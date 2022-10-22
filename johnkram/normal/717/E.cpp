#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAXN 200005
int n,m,i,j,k,h[MAXN],ne[MAXN<<1],p[MAXN<<1],f[MAXN],a[MAXN];
bool dfs(int x)
{
	printf("%d ",x);
	for(int i=h[x];i;i=ne[i])if(p[i]!=f[x])
	{
		f[p[i]]=x;
		a[p[i]]=!a[p[i]];
		if(dfs(p[i]))a[x]=!a[x];
		else printf("%d %d ",x,p[i]);
		printf("%d ",x);
	}
	return a[x];
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		a[i]=max(a[i],0);
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&j,&k);
		p[++m]=k;
		ne[m]=h[j];
		h[j]=m;
		p[++m]=j;
		ne[m]=h[k];
		h[k]=m;
	}
	if(!dfs(1))printf("%d 1 %d ",p[h[1]],p[h[1]]);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n,m,i,j,k,a[MAXN],h[MAXN],ne[MAXN<<1],p[MAXN<<1],f[MAXN],c[MAXN],d[MAXN];
void dfs(int x)
{
	c[x]=a[x];
	for(int i=h[x];i;i=ne[i])if(p[i]!=f[x])
	{
		f[p[i]]=x;
		dfs(p[i]);
		if(c[p[i]]!=a[x])c[x]=0;
	}
}
void work(int x)
{
	int i,j;
	if(d[x]==a[x])
	{
		for(i=h[x],j=0;i;i=ne[i])if(p[i]!=f[x]&&c[p[i]]!=a[x])j++;
		if(!j)
		{
			for(i=h[x];i;i=ne[i])if(p[i]!=f[x])d[p[i]]=a[x];
		}
		else if(j==1)for(i=h[x],j=0;i;i=ne[i])if(p[i]!=f[x]&&c[p[i]]!=a[x])d[p[i]]=a[x];
	}
	for(i=h[x];i;i=ne[i])if(p[i]!=f[x])work(p[i]);
}
int main()
{
	scanf("%d",&n);
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
	for(i=1;i<=n;i++)scanf("%d",a+i);
	dfs(1);
	d[1]=a[1];
	work(1);
	for(i=1;i<=n;i++)
	{
		for(j=h[i];j;j=ne[j])if(p[j]!=f[i]&&!c[p[j]])break;
		if(!j&&d[i])
		{
			puts("YES");
			printf("%d\n",i);
			return 0;
		}
	}
	puts("NO");
	return 0;
}
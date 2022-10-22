#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int n,m,i,j,k,d[MAXN],h[MAXN],ne[MAXN<<1],p[MAXN<<1],f[MAXN],c[MAXN];
void dfs(int x)
{
	for(int i=h[x],j=1;i;i=ne[i])if(p[i]!=f[x])
	{
		f[p[i]]=x;
		for(;j==c[x]||j==c[f[x]];j++);
		c[p[i]]=j++;
		dfs(p[i]);
	}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&j,&k);
		d[j]++;
		d[k]++;
		p[++m]=k;
		ne[m]=h[j];
		h[j]=m;
		p[++m]=j;
		ne[m]=h[k];
		h[k]=m;
	}
	for(i=j=1;i<=n;i++)if(d[i]>d[j])j=i;
	cout<<d[j]+1<<endl;
	c[1]=1;
	dfs(1);
	for(i=1;i<=n;i++)printf("%d ",c[i]);
	return 0;
}
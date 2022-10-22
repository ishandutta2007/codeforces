#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int f[MAXN],h[MAXN],ne[MAXN<<1],p[MAXN<<1],n,m,i,j,s[MAXN];
void dfs(int x)
{
	s[x]=1;
	for(int i=h[x];i;i=ne[i])if(p[i]!=f[x])
	{
		f[p[i]]=x;
		dfs(p[i]);
		s[x]+=s[p[i]];
	}
}
void work(int x)
{
	int i;
	for(i=h[x];i;i=ne[i])if(p[i]!=f[x]&&!(s[p[i]]&1))work(p[i]);
	printf("%d\n",x);
	for(i=h[x];i;i=ne[i])if(p[i]!=f[x]&&(s[p[i]]&1))work(p[i]);
}
int main()
{
	scanf("%d",&n);
	if(!(n&1))
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&j);
		if(!j)continue;
		p[++m]=j;
		ne[m]=h[i];
		h[i]=m;
		p[++m]=i;
		ne[m]=h[j];
		h[j]=m;
	}
	f[1]=0;
	dfs(1);
	work(1);
	return 0;
}
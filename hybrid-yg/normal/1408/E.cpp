#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,i,t,k,a[N],b[N],f[N],j,x;
long long ans=0;
struct str{
	int u,v,w;
}e[N];
bool cmp(str a,str b)
{
	return a.w>b.w;
}
int Find(int x)
{
	return f[x]?f[x]=Find(f[x]):x;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&m,&n);
	for(i=1;i<=m;++i)
		scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
		scanf("%d",&b[i]);
	for(i=1;i<=m;++i)
	{
		scanf("%d",&t);
		for(j=1;j<=t;++j)
		{
			scanf("%d",&x);
			ans+=a[i]+b[x];
			e[++k]=(str){i+n,x,a[i]+b[x]};
		}
	}
	sort(e+1,e+1+k,cmp);
	for(i=1;i<=k;++i)
	{
		int a=Find(e[i].u),b=Find(e[i].v);
		if(a!=b)
		{
			f[a]=b;
			ans-=e[i].w;
		}
	}
	cout<<ans;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=500005,M=998244353;
int t,i,ans[N],p,f[N],e[N],u,v,n,m,a,b,siz[N];
int Find(int x)
{
	if(f[x]==0)
		return x;
	return f[x]=Find(f[x]);
}
void uniot(int u,int v)
{
	int x=Find(u),y=Find(v);
	if(x!=y)
	{
		siz[y]+=siz[x];
		e[y]|=e[x];
		f[x]=y;
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&n,&m,&a,&b);
		for(i=1;i<=n;++i)
		{
			f[i]=e[i]=0;
			siz[i]=1;
		}
		for(i=1;i<=m;++i)
		{
			scanf("%d %d",&u,&v);
			if(v==a||v==b)
				swap(u,v);
			if((u==a||u==b)&&(v==a||v==b))
				continue;
			if(u==a)
				e[Find(v)]|=1;
			if(u==b)
				e[Find(v)]|=2;
			if(u!=a&&u!=b)
				uniot(u,v);
		}
		int s1=0,s2=0;
		for(i=1;i<=n;++i)
			if(f[i]==0&&i!=a&&i!=b)
			{
				if(e[i]==1)
					s1+=siz[i];
				if(e[i]==2)
					s2+=siz[i];
			}
		printf("%lld\n",1ll*s1*s2);
	}
}
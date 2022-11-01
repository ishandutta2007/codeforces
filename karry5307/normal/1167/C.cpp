#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=5e5+51;
ll n,m,kk,syk,ccc;
ll ffa[MAXN],sz[MAXN];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
inline ll find(ll x)
{
	return x==ffa[x]?x:ffa[x]=find(ffa[x]);
}
inline void merge(ll x,ll y)
{
	ll fx=find(x),fy=find(y);
	if(fx!=fy)
	{
		ffa[fy]=fx,sz[fx]+=sz[fy],sz[fy]=0;
	}
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		ffa[i]=i,sz[i]=1;
	}
	for(register int i=1;i<=m;i++)
	{
		kk=read(),syk=0;
		for(register int i=1;i<=kk;i++)
		{
			ccc=read(),syk?merge(syk,ccc):(void)1,syk=ccc;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		printf("%d ",sz[find(i)]);
	}
}
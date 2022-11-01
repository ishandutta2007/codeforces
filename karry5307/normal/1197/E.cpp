#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=1e9+7;
struct Edge{
	ll to,prev,dist;
};
struct Item{
	ll in,out;
	inline bool operator <(const Item &rhs)const
	{
		return this->in<rhs.in;
	}
};
Edge ed[MAXN<<1];
Item item[MAXN];
ll cnt,tot,ub;
li res,minn=0x3f3f3f3f3f3f3f3f;
ll last[MAXN],inQueue[MAXN];
li dis[MAXN],path[MAXN];
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
inline void addEdge(ll from,ll to,ll dist)
{
	ed[++tot].prev=last[from];
	ed[tot].to=to;
	ed[tot].dist=dist;
	last[from]=tot;
}
inline ll lb(ll x)
{
	ll l=1,r=cnt,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		item[mid].in>=x?r=mid:l=mid+1;
	}
	return item[l].in>=x?l:-1;
}
inline void toposort()
{
	memset(dis,0x3f,sizeof(dis)),dis[0]=0,path[0]=1;
	for(register int i=0;i<=cnt;i++)
	{
		for(register int j=last[i];j;j=ed[j].prev)
		{
			if(dis[ed[j].to]>dis[i]+ed[j].dist)
			{
				dis[ed[j].to]=dis[i]+ed[j].dist;
				path[ed[j].to]=path[i];
			}
			else
			{
				if(dis[ed[j].to]==dis[i]+ed[j].dist)
				{
					path[ed[j].to]=(path[ed[j].to]+path[i])%MOD;
				}
			}
		}
	}
}
int main()
{
	cnt=read();
	for(register int i=1;i<=cnt;i++)
	{
		item[i].out=read(),item[i].in=read();
	}
	sort(item+1,item+cnt+1);
	for(register int i=0;i<cnt;i++)
	{
		addEdge(i,i+1,item[i+1].in-item[i].in);
	}
	for(register int i=1;i<=cnt;i++)
	{
		ub=lb(item[i].out);
		if(ub!=-1)
		{
			addEdge(i,ub,item[ub].in-item[i].out);
		}
	}
	toposort();
	for(register int i=1;i<=cnt;i++)
	{
		if(item[i].out>item[cnt].in)
		{
			minn=min(minn,dis[i]);
		}
	}
	for(register int i=1;i<=cnt;i++)
	{
		if(item[i].out>item[cnt].in&&dis[i]==minn)
		{
			res=(res+path[i])%MOD;
		}
	}
	printf("%lld\n",res);
}
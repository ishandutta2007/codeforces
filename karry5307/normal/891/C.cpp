#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=6e5+51;
struct Edge{
	ll from,to,dist,id;
	inline bool operator <(const Edge &rhs)const
	{
		return this->dist<rhs.dist;
	}
};
Edge ed[MAXN],edd[MAXN];
ll nc,ec,qcnt,cnt,x,y;
ll boss[MAXN];
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
inline void setup(ll cnt)
{
	for(register int i=1;i<=cnt;i++)
	{
		boss[i]=i;
	}
}
inline ll findb(ll node)
{
	if(node==boss[node])
	{
		return node;
	}
	return boss[node]=findb(boss[node]);
}
inline bool check()
{
	cnt=read();
	for(register int i=0;i<cnt;i++)
	{
		edd[i]=ed[read()-1];
	}
	sort(edd,edd+cnt);
	for(register int i=0,j=0;j<cnt;i=j=j+1)
	{
		while(j<cnt-1&&edd[j+1].dist==edd[i].dist)
		{
			j++;
		}
		for(register int k=i;k<=j;k++)
		{
			boss[edd[k].from]=edd[k].from,boss[edd[k].to]=edd[k].to;
		}
		for(register int k=i;k<=j;k++)
		{
			x=findb(edd[k].from),y=findb(edd[k].to);
			if(x==y)
			{
				return 0;
			}
			boss[findb(y)]=findb(x);
		}
	}
	return 1;
}
inline bool cmp(Edge x,Edge y)
{
	return x.id<y.id;
}
int main()
{
	nc=read(),ec=read(),setup(nc);
	for(register int i=0;i<ec;i++)
	{
		ed[i].from=read(),ed[i].to=read(),ed[i].dist=read(),ed[i].id=i;
	}
	sort(ed,ed+ec);
	for(register int i=0,j=0;i<ec;i=j=j+1)
	{
		while(j<ec-1&&ed[j+1].dist==ed[i].dist)
		{
			j++;
		}
		for(register int k=i;k<=j;k++)
		{
			ed[k].from=findb(ed[k].from),ed[k].to=findb(ed[k].to);
		}
		for(register int k=i;k<=j;k++)
		{
			x=findb(ed[k].from),y=findb(ed[k].to);
			if(x!=y)
			{
				boss[findb(y)]=findb(x);
			}
		}
	}
	sort(ed,ed+ec,cmp),qcnt=read();
	for(register int i=0;i<qcnt;i++)
	{
		puts(check()?"YES":"NO");
	}
}
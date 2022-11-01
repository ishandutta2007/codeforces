#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=2e6+51;
struct Edge{
	ll to,prev;
};
Edge ed[MAXN<<1];
stack<ll>st;
ll cnt,limit,p,q,tot,num,sccCnt,x,y,kk,l,r;
ll last[MAXN<<1],dfn[MAXN<<1],low[MAXN<<1],belong[MAXN<<1],ins[MAXN<<1];
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
inline void addEdge(ll from,ll to)
{
	ed[++tot].prev=last[from];
	ed[tot].to=to;
	last[from]=tot;
}
inline ll yes(ll x)
{
	return x<<1;
}
inline ll no(ll x)
{
	return x<<1|1;
}
inline void Tarjan(ll node)
{
	ll nd;
	dfn[node]=low[node]=++num;
	st.push(node),ins[node]=1;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(!dfn[ed[i].to])
		{
			Tarjan(ed[i].to);
			low[node]=min(low[node],low[ed[i].to]);
		}
		else
		{
			if(ins[ed[i].to])
			{
				low[node]=min(low[node],dfn[ed[i].to]);
			}
		}
	}
	if(dfn[node]==low[node])
	{
		sccCnt++;
		do
		{
			nd=st.top(),st.pop();
			ins[nd]=0,belong[nd]=sccCnt;
		}
		while(node!=nd);
	}
}
int main()
{
	p=read(),cnt=read(),limit=read(),q=read();
	for(register int i=0;i<p;i++)
	{
		x=read()-1,y=read()-1;
		addEdge(no(x),yes(y)),addEdge(no(y),yes(x));
	}
	for(register int i=0;i<limit;i++)
	{
		addEdge(yes(cnt+i),yes(cnt+i+1));
		addEdge(no(cnt+i+1),no(cnt+i));
	}
	for(register int i=0;i<cnt;i++)
	{
		l=read(),r=read();
		addEdge(yes(i),no(cnt+l-1)),addEdge(yes(cnt+l-1),no(i));
		addEdge(yes(i),yes(cnt+r)),addEdge(no(cnt+r),no(i));
	}
	for(register int i=0;i<q;i++)
	{
		x=read()-1,y=read()-1;
		addEdge(yes(x),no(y)),addEdge(yes(y),no(x));
	}
	addEdge(yes(cnt),no(cnt));
	for(register int i=0;i<=no(cnt+limit);i++)
	{
		if(!dfn[i])
		{
			Tarjan(i);
		}
	}
	for(register int i=0;i<=cnt+limit;i++)
	{
		if(belong[yes(i)]==belong[no(i)])
		{
			return puts("-1"),0;
		}
	}
	for(register int i=0;i<cnt;i++)
	{
		kk+=(belong[yes(i)]<belong[no(i)]);
	}
	for(register int i=1;i<=limit;i++)
	{
		if(belong[yes(cnt+i)]<belong[no(cnt+i)])
		{
			printf("%d %d\n",kk,i);
			break;
		}
	}
	for(register int i=0;i<cnt;i++)
	{
		if(belong[yes(i)]<belong[no(i)])
		{
			printf("%d ",i+1);
		}
	}
}
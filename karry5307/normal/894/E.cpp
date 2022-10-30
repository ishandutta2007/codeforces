#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1e6+51;
struct Edge{
	ll to,prev,dist;
};
Edge ed[MAXN];
stack<ll>st;
ll nc,ec,tot,sccCnt,dfst,tp;
ll last[MAXN],from[MAXN],to[MAXN],dist[MAXN],dfn[MAXN],low[MAXN];
ll inStack[MAXN],bel[MAXN],dp[MAXN],wt[MAXN];
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
template <class T>
inline T Min(T x,T y)
{
	return x<y?x:y;
}
template <class T>
inline T Max(T x,T y)
{
	return x>y?x:y;
}
inline void addEdge(ll from,ll to,ll dist)
{
	ed[++tot].prev=last[from];
	ed[tot].to=to;
	ed[tot].dist=dist;
	last[from]=tot;
}
inline void Tarjan(ll node)
{
	dfn[node]=low[node]=++dfst,st.push(node),inStack[node]=1;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(!dfn[ed[i].to])
		{
			Tarjan(ed[i].to),low[node]=Min(low[node],low[ed[i].to]);
		}
		else
		{
			if(inStack[ed[i].to])
			{
				low[node]=Min(low[node],dfn[ed[i].to]);
			}
		}
	}
	if(dfn[node]==low[node])
	{
		sccCnt++;
		do
		{
			tp=st.top(),st.pop(),inStack[tp]=0,bel[tp]=sccCnt; 
		}
		while(tp!=node);
	}
}
inline ll calc(ll k)
{
	ll t=sqrt(0.25+2*k)-0.5;
	return (t+1)*k-t*(t+1)*(t+2)/6;
}
inline ll dfs(ll node)
{
	if(dp[node])
	{
		return dp[node];
	}
	for(register int i=last[node];i;i=ed[i].prev)
	{
		dp[node]=Max(dp[node],ed[i].dist+dfs(ed[i].to));
	}
	return (dp[node]+=wt[node]);
}
int main()
{
	nc=read(),ec=read();
	for(register int i=0;i<ec;i++)
	{
		from[i]=read(),to[i]=read(),dist[i]=read();
		addEdge(from[i],to[i],dist[i]);
	}
	for(register int i=1;i<=nc;i++)
	{
		if(!dfn[i])
		{
			Tarjan(i);	
		}	
	}
	memset(last,tot=0,sizeof(last));
	for(register int i=0;i<ec;i++)
	{
		if(bel[from[i]]==bel[to[i]])
		{
			wt[bel[from[i]]]+=calc(dist[i]);
			continue;
		}
		addEdge(bel[from[i]],bel[to[i]],dist[i]);
	}
	printf("%lld\n",dfs(bel[read()]));
}
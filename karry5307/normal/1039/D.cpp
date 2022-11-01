#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e5+51;
struct Edge{
	ll to,prev;
};
Edge ed[MAXN<<1];
ll nc,tot,p,from,to;
ll last[MAXN],fa[MAXN],dp[MAXN],res[MAXN];
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
inline T Max(T x,T y)
{
	return x>y?x:y;
}
inline void addEdge(ll from,ll to)
{
	ed[++tot].prev=last[from];
	ed[tot].to=to;
	last[from]=tot;
}
inline void dfs(ll node,ll f,ll x)
{
	fa[node]=f;
	ll maxn=0,maxn2=0;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=f)
		{
			dfs(ed[i].to,node,x);
			if(dp[ed[i].to]>maxn)
			{
				maxn2=maxn,maxn=dp[ed[i].to];
			}
			else
			{
				maxn2=Max(maxn2,dp[ed[i].to]);
			}
		}
	}
	if(maxn+maxn2+1>=x)
	{
		dp[node]=0,p++;
	}
	else
	{
		dp[node]=maxn+1;
	}
}
inline void solve(ll l,ll r,ll lx,ll rx)
{
	if(l>r||lx>rx)
	{
		return;
	}
	if(lx==rx)
	{
		for(register int i=l;i<=r;i++)
		{
			res[i]=lx;
		}
		return;
	}
	ll mid=(l+r)>>1;
	p=0,dfs(1,0,mid),res[mid]=p;
	solve(l,mid-1,p,rx),solve(mid+1,r,lx,p);
}
int main()
{
	nc=read();
	for(register int i=1;i<nc;i++)
	{
		from=read(),to=read();
		addEdge(from,to),addEdge(to,from);
	}
	solve(1,nc,0,nc);
	for(register int i=1;i<=nc;i++)
	{
		printf("%d\n",res[i]);
	}
}
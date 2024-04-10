#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
struct Edge{
	ll to,prev;
};
Edge ed[MAXN<<1];
ll n,tot,from,to,res,val;
ll last[MAXN],p[MAXN][2],u[MAXN],v[MAXN],c[MAXN];
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
inline void dfs(ll node,ll fa)
{
	ll vx,x;
	c[node]=min(c[node],c[fa]),p[node][u[node]]=u[node]^v[node];
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if((vx=ed[i].to)!=fa)
		{
			dfs(vx,node),p[node][0]+=p[vx][0],p[node][1]+=p[vx][1];
		}
	}
	x=min(p[node][0],p[node][1]),res+=2*x*c[node];
	p[node][0]-=x,p[node][1]-=x;
}
int main()
{
	n=read(),c[0]=0x3f3f3f3f3f3f3f3f;
	for(register int i=1;i<=n;i++)
	{
		c[i]=read(),u[i]=read(),v[i]=read(),val+=u[i]-v[i];
	}
	for(register int i=0;i<n-1;i++)
	{
		from=read(),to=read(),addEdge(from,to),addEdge(to,from);
	}
	dfs(1,0),printf("%lld\n",val!=0?-1:res);
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=5e5+51,MOD=998244353,INV2=499122177;
struct Edge{
	ll to,prev;
};
Edge ed[MAXN<<1];
ll n,tot,from,to,res,c;
ll last[MAXN],f[MAXN];
namespace FastIO{
	char buf[MAXN*5],*st=buf,*ed=buf;
	inline char gc()
	{
		return st==ed&&(ed=(st=buf)+fread(buf,1,2500000,stdin),ed==st)?0:*st++; 
	}
}
using FastIO::gc;
inline ll read()
{
    register ll num=0;
    register char ch=gc();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=gc();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=gc();
    }
    return num;
}
inline void addEdge(ll from,ll to)
{
	ed[++tot].prev=last[from];
	ed[tot].to=to;
	last[from]=tot;
}
inline void dfs(ll node,ll fa)
{
	ll prod=1;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=fa)
		{
			dfs(ed[i].to,node),prod=(li)prod*(1+f[ed[i].to])%MOD*INV2%MOD;
		}
	}	 
	res=(res+(f[node]=MOD+1-prod))%MOD;
}
int main()
{
	n=read(),c=1;
	for(register int i=0;i<n-1;i++)
	{
		from=read(),to=read(),addEdge(from,to),addEdge(to,from),c=(c+c)%MOD;
	}
	dfs(1,0),printf("%d\n",(li)res*(c+c)%MOD);
}
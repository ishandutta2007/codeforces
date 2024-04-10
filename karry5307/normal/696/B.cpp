#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n;
ll sz[MAXN],f[MAXN];
vector<ll>vg[MAXN];
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
inline void dfs(ll node)
{
	sz[node]=1;
	for(register int i:vg[node])
	{
		dfs(i),sz[node]+=sz[i];
	}
}
inline void dfs2(ll node,ll fa)
{
	f[node]=node==1?2:f[fa]+sz[fa]-sz[node]+1;
	for(register int i:vg[node])
	{
		dfs2(i,node);
	}
}
int main()
{
	n=read();
	for(register int i=2;i<=n;i++)
	{
		vg[read()].push_back(i);
	}	
	dfs(1),dfs2(1,0);
	for(register int i=1;i<=n;i++)
	{
		printf("%d.%d ",f[i]>>1,5*(f[i]&1));
	}
}
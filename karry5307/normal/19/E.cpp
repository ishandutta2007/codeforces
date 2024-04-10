#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef pair<ll,ll> pii;
const ll MAXN=2e5+51;
vector<ll>res;
ll n,m,u,v,r,rr;
ll vis[MAXN],vis2[MAXN],col[MAXN],d[MAXN];
vector<pii>vg[MAXN];
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
inline void dfs(ll x,ll c)
{
	ll u,v;
	col[x]=c,vis[x]=1;
	for(auto i:vg[x])
	{
		tie(u,v)=i,!vis[u]?vis2[v]=1,dfs(u,c^1):(void)1;
		if(!vis2[v])
		{
			vis2[v]=1,col[x]==col[u]?r++,rr=v,d[x]++,d[u]--:(d[u]++,d[x]--);
		}
	}
}
inline void dfs2(ll x)
{
	ll u;
	vis[x]=1;
	for(auto i:vg[x])
	{
		if(!vis[u=i.first])
		{
			dfs2(u),d[u]==r?res.push_back(i.second):(void)1,d[x]+=d[u];
		}
	}
}
int main()
{
    n=read(),m=read();
    for(register int i=1;i<=m;i++)
    {
    	u=read(),v=read();
    	vg[u].push_back({v,i}),vg[v].push_back({u,i});
	}
	for(register int i=1;i<=n;i++)
	{
		!vis[i]?dfs(i,2):(void)1;
	}
	if(!r)
	{
		printf("%d\n",m);
		for(register int i=1;i<=m;i++)
		{
			printf("%d ",i);
		}
		return 0;
	}
	memset(vis,0,sizeof(vis));
	for(register int i=1;i<=n;i++)
	{
		!vis[i]?dfs2(i):(void)1;	
	} 
	r==1?res.push_back(rr):(void)1,sort(res.begin(),res.end());
	printf("%d\n",res.size());
	for(register int i:res)
	{
		printf("%d ",i);
	}
}
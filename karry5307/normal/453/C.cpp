#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
vector<ll>res;
ll n,m,u,v,r,x;
ll vis[MAXN],col[MAXN],ffa[MAXN],f[MAXN];
vector<ll>vg[MAXN],vg2[MAXN];
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
inline void dfs(ll x)
{
	vis[x]=1;
	for(register int i:vg[x])
	{
		!vis[i]?vg2[x].push_back(i),dfs(i):(void)1;
	}
}
inline void upd(ll x)
{
	res.push_back(x),col[x]^=1;
}
inline void dfs2(ll x)
{
	upd(x);
	for(register int i:vg2[x])
	{
		dfs2(i),upd(x),col[i]?upd(i),upd(x):(void)1;
	}
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		ffa[i]=i;
	}
	for(register int i=1;i<=m;i++)
	{
		u=read(),v=read(),vg[u].push_back(v),vg[v].push_back(u);
		u=find(u),v=find(v),u!=v?ffa[v]=u:1;
	}
	for(register int i=1;i<=n;i++)
	{
		col[i]=read(),f[find(i)]|=col[i];
	}
	for(register int i=1;i<=n;i++)
	{
		r+=f[i];
	}
	if(r!=1)
	{
		return puts(r?"-1":"0");
	}
	for(register int i=1;i<=n;i++)
	{
		if(f[find(i)])
		{
			x=i;
			break;
		}
	}
	dfs(x),dfs2(x),col[x]?res.pop_back():(void)1,printf("%d\n",res.size());
	for(register int i:res)
	{
		printf("%d ",i);
	}
}
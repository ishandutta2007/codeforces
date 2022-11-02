#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
vector<ll>r;
queue<ll>q;
ll n,m,c,top;
ll x[MAXN],deg[MAXN],vis[MAXN],ip[MAXN];
vector<ll>vg[MAXN],vgr[MAXN];
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
inline void dfs(ll x)
{
	if(vis[x])
	{
		return;
	}
	vis[x]=1;
	for(register int i:vg[x])
	{
		dfs(i);
	}
	r.push_back(x);
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=m;i++)
	{
		x[i]=read();
	}
	for(register int i=1;i<=n;i++)
	{
		!(deg[i]=read())?q.push(i):(void)1;
		for(register int j=1;j<=deg[i];j++)
		{
			vg[i].push_back(c=read()),vgr[c].push_back(i);
		}
	}
	while(!q.empty())
	{
		ip[top=q.front()]=1,q.pop();
		for(register int i:vgr[top])
		{
			!--deg[i]?q.push(i):(void)1;	
		}	
	} 
	for(register int i=1;i<=m;i++)
	{
		if(!ip[x[i]])
		{
			return puts("-1"),0;
		}
		dfs(x[i]);
	}
	printf("%d\n",r.size());
	for(register int i:r)
	{
		printf("%d ",i);
	}
}
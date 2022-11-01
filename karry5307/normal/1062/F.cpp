#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=3e5+51;
ll n,m,r,res;
ll u[MAXN],v[MAXN],deg[MAXN],f[MAXN],vis[MAXN];
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
inline void calc(ll x,ll y)
{
	for(register int i:vg[y])
	{
		if(deg[i]==1)
		{
			return (void)(vis[x]=1);	
		}	
	}	
	f[x]+=r;
}
inline void toposort()
{
	queue<ll>q;
	ll top,sz;
	for(register int i=1;i<=n;i++)
	{
		!deg[i]?r--,q.push(i):(void)1;
	}
	while(!q.empty())
	{
		top=q.front(),sz=q.size(),q.pop();
		sz==1?f[top]+=r:1,sz==2?calc(top,q.front()):(void)1;
		for(register int i:vg[top])
		{
			!--deg[i]?r--,q.push(i):(void)1;
		}
	}
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read(),vg[u[i]].push_back(v[i]),deg[v[i]]++;
	}
	r=n,toposort();
	for(register int i=1;i<=n;i++)
	{
		vg[i].clear();
	}
	for(register int i=1;i<=m;i++)
	{
		vg[v[i]].push_back(u[i]),deg[u[i]]++;
	}
	r=n,toposort();
	for(register int i=1;i<=n;i++)
	{
		res+=f[i]>=n-2;
	}
	printf("%d\n",res);
}
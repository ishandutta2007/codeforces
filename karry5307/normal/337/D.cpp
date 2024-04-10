#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,m,c,u,v,res;
vector<ll>vg[MAXN];
ll d[MAXN],d2[MAXN],x[MAXN];
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
inline void dfs(ll node,ll fa,ll *d)
{
	d[node]=d[fa]+1;
	for(register int i:vg[node])
	{
		i!=fa?dfs(i,node,d):(void)1;
	}
}
int main()
{
	n=read(),m=read(),c=read();
	for(register int i=1;i<=m;i++)
	{
		x[i]=read();
	}
	for(register int i=0;i<n-1;i++)
	{
		u=read(),v=read(),vg[u].push_back(v),vg[v].push_back(u);
	}
	d[0]=d2[0]=-1,dfs(1,0,d),u=v=0;
	for(register int i=1;i<=m;i++)
	{
		d[x[i]]>d[u]?u=x[i]:1;
	}
	dfs(u,0,d);
	for(register int i=1;i<=m;i++)
	{
		d[x[i]]>d[v]?v=x[i]:1;
	}
	dfs(v,0,d2);
	for(register int i=1;i<=n;i++)
	{
		res+=(d[i]<=c&&d2[i]<=c);
	}
	printf("%d\n",res);
}
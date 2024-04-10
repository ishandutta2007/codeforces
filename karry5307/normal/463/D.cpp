#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e3+51;
ll n,m,res,p;
ll f[MAXN],calc[MAXN],rp[MAXN],x[MAXN][MAXN];
vector<ll>g[MAXN];
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
inline ll dfs(ll x)
{
	if(calc[x])
	{
		return f[x];
	}
	for(register int i=0;i<g[x].size();i++)
	{
		f[x]=max(f[x],dfs(g[x][i]));
	}
	calc[x]=1,f[x]++;
	return f[x];
}
int main()
{
	n=read(),m=read(),memset(x,0x3f,sizeof(x));
	for(register int i=1;i<=m;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			p=read(),rp[p]=j;
		}
		for(register int j=1;j<=n;j++)
		{
			for(register int k=1;k<=n;k++)
			{
				x[j][k]&=(rp[j]<rp[k]);
			}
		}
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			if(x[i][j])
			{
				g[i].emplace_back(j);
			}
		}
	}
	for(register int i=1;i<=n;i++)
	{
		res=max(res,dfs(i));
	}
	printf("%d\n",res);
}
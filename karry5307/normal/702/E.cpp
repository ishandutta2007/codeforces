#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll n,kk;
ll f[MAXN][41],g[MAXN][41],h[MAXN][41];
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
inline void jump(ll x,ll kk)
{
	ll sm=0,mn=0x3f3f3f3f;
	for(register int i=40;i>=0;i--)
	{
		kk>=(1ll<<i)?kk-=(1ll<<i),sm+=f[x][i],mn=min(mn,g[x][i]),x=h[x][i]:1;
	}
	printf("%lld %lld\n",sm,mn);
}
int main()
{
	n=read(),kk=read();
	for(register int i=1;i<=n;i++)
	{
		h[i][0]=read()+1;
	}
	for(register int i=1;i<=n;i++)
	{
		f[i][0]=g[i][0]=read();
	}
	for(register int j=1;j<=40;j++)
	{
		for(register int i=1;i<=n;i++)
		{
			h[i][j]=h[h[i][j-1]][j-1],f[i][j]=f[i][j-1]+f[h[i][j-1]][j-1];
			g[i][j]=min(g[i][j-1],g[h[i][j-1]][j-1]);
		}
	}
	for(register int i=1;i<=n;i++)
	{
		jump(i,kk);
	}
}
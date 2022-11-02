#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e3+51,MOD=1e9+7;
ll n,u,v;
ll x[MAXN],mp[MAXN],f[MAXN][MAXN];
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
int main()
{
	n=read(),f[0][0]=1;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),f[i][0]=(li)f[i-1][0]*i%MOD;
		x[i]!=-1?mp[x[i]]=1:1;
	}
	for(register int i=2;i<=n;i++)
	{
		f[0][i]=((li)i*f[0][i-1]+(i&1?MOD-1:1))%MOD;
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			f[i][j]=((li)i*f[i-1][j]+(li)j*f[i][j-1])%MOD;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		x[i]==-1?mp[i]?u++:v++:1;
	}
	printf("%d",f[u][v]);
}
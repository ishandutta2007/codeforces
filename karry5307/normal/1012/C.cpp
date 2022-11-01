#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=5e3+51;
ll n,res,lc,rc;
ll h[MAXN],f[MAXN][MAXN][2][2];
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
inline ll calc(ll x)
{
	return max(x,0);
}
int main()
{
	n=read(),h[0]=0x7fffffff;
	for(register int i=1;i<=n;i++)
	{
		h[i]=read(),f[i][0][1][0]=0x3f3f3f3f;
		for(register int j=1;j<=(n+1)>>1;j++)
		{
			f[i][j][0][0]=f[i][j][0][1]=0x3f3f3f3f;
			f[i][j][1][0]=f[i][j][1][1]=0x3f3f3f3f;
		}
	}
	f[1][0][0][0]=f[1][1][0][1]=0;
	for(register int i=2;i<=n;i++)
	{
		for(register int j=1;j<=(i+1)>>1;j++)
		{
			f[i][j][0][0]=min(f[i-1][j][0][0],f[i-1][j][1][0]);
			lc=f[i-1][j-1][0][0]+calc(h[i-1]-h[i]+1);
			rc=f[i-1][j-1][1][0]+calc(min(h[i-2]-1,h[i-1])-h[i]+1);
			f[i][j][0][1]=min(lc,rc);
			f[i][j][1][0]=f[i-1][j][0][1]+calc(h[i]-h[i-1]+1);
		}
	}
	for(register int i=1;i<=(n+1)>>1;i++)
	{
		res=0x3f3f3f3f;
		for(register int j=0;j<2;j++)
		{
			for(register int k=0;k<2;k++)
			{
				res=min(res,f[n][i][j][k]);
			}
		}
		printf("%d ",res);
	}
	puts("");
}
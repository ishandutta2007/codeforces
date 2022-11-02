#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=51,MOD=1e9+7,INV2=5e8+4;
ll n,res;
ll fact[MAXN],finv[MAXN],d[MAXN],f[MAXN][MAXN],g[MAXN][MAXN][MAXN];
ll c[2];
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
inline ll qpow(ll base,ll exponent)
{
	ll res=1;
	while(exponent)
	{
		if(exponent&1)
		{
			res=(li)res*base%MOD;
		}
		base=(li)base*base%MOD,exponent>>=1;
	}
	return res;
}
inline void setup(ll cnt)
{
	fact[0]=fact[1]=finv[0]=1;
	for(register int i=2;i<=cnt;i++)
	{
		fact[i]=(li)fact[i-1]*i%MOD;
	}
	finv[cnt]=qpow(fact[cnt],MOD-2);
	for(register int i=cnt-1;i;i--)
	{
		finv[i]=(li)finv[i+1]*(i+1)%MOD;
	}
}
inline ll binom(ll m,ll n)
{
	return (li)fact[m]*finv[n]%MOD*finv[m-n]%MOD;
}
inline void calc()
{
	ll x;
	g[0][0][0]=1;
	for(register int i=0;i<=n;i++)
	{
		for(register int j=0;j<=n-i;j++)
		{
			if(i==0&&j==0)
			{
				continue;
			}
			if(!i)
			{
				for(register int k=2;k<j;k++)
				{
					x=(li)g[0][i][j-k-1]*binom(j-1,k)%MOD*fact[k]%MOD*INV2%MOD;
					g[0][i][j]=(g[0][i][j]+x)%MOD;
				}
			}
			else
			{
				if(i>=2)
				{
					g[0][i][j]=(g[0][i][j]+(li)(i-1)*g[0][i-2][j]%MOD)%MOD;
				}
				if(j>=1)
				{
					g[0][i][j]=(g[0][i][j]+(li)j*g[0][i][j-1]%MOD)%MOD;
				}
			}
		}
	}
	for(register int i=1;i<n;i++)
	{
		for(register int p=1,j;p<n-i;p++)
		{
			for(register int k=0;k<=p;k++)
			{
				j=p-k;
				if(j)
				{
					g[i][j][k]=(g[i][j][k]+(li)j*g[i-1][j-1][k]%MOD)%MOD;
				}
				if(k)
				{
					g[i][j][k]=(g[i][j][k]+(li)k*g[i-1][j+1][k-1]%MOD)%MOD;
				}
			}
		}
	}
}
int main()
{
	setup(n=read()),calc();
	for(register int i=1;i<=n;i++)
	{
		d[i]=read();
	}
	f[d[1]+1][d[1]]=1;
	for(register int i=d[1]+2;i<=n;i++)
	{
		for(register int j=1;j<=i-d[1]-1;j++)
		{
			c[0]=c[1]=0;
			for(register int k=1;k<i-j;k++)
			{
				c[d[i-j-k+1]==3]++;
				f[i][j]=(f[i][j]+(li)g[j][c[0]][c[1]]*f[i-j][k]%MOD)%MOD;
			}
		}
	}
	c[0]=c[1]=0;
	for(register int i=1;i<n;i++)
	{
		c[d[n-i+1]==3]++;
		res=(res+(li)f[n][i]*g[0][c[0]][c[1]]%MOD)%MOD;
	}
	printf("%d\n",res);
}
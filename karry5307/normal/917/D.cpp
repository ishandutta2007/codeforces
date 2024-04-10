#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=151,MOD=1e9+7;
ll n,w,fd,rr;
ll x[MAXN],y[MAXN],mat[MAXN][MAXN],f[MAXN],g[MAXN],r[MAXN];
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
inline void add(ll x,ll y,ll w)
{
	mat[x][x]=(mat[x][x]+w)%MOD,mat[y][y]=(mat[y][y]+w)%MOD;
	mat[x][y]=(mat[x][y]-w+MOD)%MOD,mat[y][x]=(mat[y][x]-w+MOD)%MOD;
}
inline ll det()
{
	ll pivot,cof,res=1,sgn=1;
	for(register int i=1;i<n;i++)
	{
		pivot=n;
		for(register int j=i;j<n;j++)
		{
			if(mat[j][i])
			{
				pivot=i;
				break;	
			}
		}
		if(pivot==n)
		{
			return 0;
		}
		pivot!=i?swap(mat[pivot],mat[i]),sgn*=-1:1;
		for(register int j=i+1;j<n;j++)
		{
			cof=(li)mat[j][i]*qpow(mat[i][i],MOD-2)%MOD;
			for(register int k=i;k<n;k++)
			{
				mat[j][k]=(mat[j][k]-(li)mat[i][k]*cof%MOD+MOD)%MOD;
			}
		}
		res=(li)res*mat[i][i]%MOD;
	}
	return sgn==1?res:(MOD-res)%MOD;
}
inline ll calc(ll w)
{
	memset(mat,0,sizeof(mat));
	for(register int i=1;i<=n;i++)
	{
		for(register int j=i+1;j<=n;j++)
		{
			add(i,j,1);
		}
	}
	for(register int i=1;i<=n-1;i++)
	{
		add(x[i],y[i],w-1);
	}
	return det();
}
inline void mul(ll x)
{
	g[fd+1]=0;
	for(register int i=fd-1;i>=0;i--)
	{
		g[i+1]=(g[i+1]+g[i])%MOD,g[i]=(li)g[i]*(MOD-x)%MOD;
	}
	fd++;
}
inline void div(ll x)
{
	ll invl=qpow(x,MOD-2);
	for(register int i=0;i<fd;i++)
	{
		g[i]=(MOD-(li)g[i]*invl%MOD)%MOD,g[i+1]=(g[i+1]-g[i]+MOD)%MOD;
	}
	fd--;
}
int main()
{
	n=read(),g[0]=fd=1;
	for(register int i=1;i<=n-1;i++)
	{
		x[i]=read(),y[i]=read();
	}
	for(register int i=1;i<=n;i++)
	{
		r[i]=calc(i),mul(i);
	}
	for(register int i=1;i<=n;i++)
	{
		div(i),rr=1;
		for(register int j=1;j<=n;j++)
		{
			j!=i?rr=(li)rr*(i-j+MOD)%MOD:1;
		}
		rr=(li)r[i]*qpow(rr,MOD-2)%MOD;
		for(register int i=0;i<fd;i++)
		{
			f[i]=(f[i]+(li)rr*g[i])%MOD;
		}
		mul(i);
	}
	for(register int i=0;i<n;i++)
	{
		printf("%d ",f[i]);
	}
}
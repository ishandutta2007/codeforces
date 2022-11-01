#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e3+51,MOD=1e9+7;
ll length,width,space,res,k;
ll mat[MAXN][MAXN],mat2[MAXN][MAXN],row[MAXN],col[MAXN];
ll x[MAXN][MAXN],y[MAXN][MAXN]; 
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
int main()
{
	length=read(),width=read();
	for(register int i=1;i<=length;i++)
	{
		row[i]=read();
		for(register int j=1;j<=row[i];j++)
		{
			mat[i][j]=1;
		}
	}
	for(register int i=1;i<=width;i++)
	{
		col[i]=read();
		for(register int j=1;j<=col[i];j++)
		{
			mat[j][i]=1;
		}
	}
	for(register int i=1;i<=length;i++)
	{
		res=0;
		for(register int j=1;j<=width;j++)
		{
			if(mat[i][j])
			{
				res++;
			}
			else
			{
				break;
			}
		}
		if(res!=row[i])
		{
			puts("0");
			return 0;
		}
	}
	for(register int i=1;i<=width;i++)
	{
		res=0;
		for(register int j=1;j<=length;j++)
		{
			if(mat[j][i])
			{
				res++;
			}
			else
			{
				break;
			}
		}
		if(res!=col[i])
		{
			puts("0");
			return 0;
		}
	}
	for(register int i=2;i<=length;i++)
	{
		for(register int j=row[i]+2;j<=width;j++)
		{
			if(!mat[i][j])
			{
				x[i][j]=1;
			}
		}
	}
	for(register int i=2;i<=width;i++)
	{
		for(register int j=col[i]+2;j<=length;j++)
		{
			if(!mat[j][i])
			{
				y[j][i]=1;
			}
		}
	}
	res=0;
	for(register int i=1;i<=length;i++)
	{
		for(register int j=1;j<=width;j++)
		{
			if(x[i][j]&y[i][j])
			{
				res++;
			}
		}
	}
	printf("%d\n",res?qpow(2,res):1);
}
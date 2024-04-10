#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=151,MOD=1e9+7;
struct Matrix{
	ll num[MAXN][MAXN];
	Matrix()
	{
		memset(num,0,sizeof(num));
	}
	inline ll* operator [](const ll &x)
	{
		return num[x];
	}
	inline const ll* operator [](const ll &x)const
	{
		return num[x];
	}
};
Matrix mat,x;
ll n,kk,r,d;
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
inline Matrix operator *(Matrix x,Matrix y)
{
	Matrix res;
	for(register int i=1;i<=r;i++)
	{
		for(register int j=1;j<=r;j++)
		{
			for(register int k=1;k<=r;k++)
			{
				res[i][j]=(res[i][j]+(li)x[i][k]*y[k][j])%MOD;
			}
		}
	}
	return res;
}
inline Matrix qpow(Matrix base,ll exponent)
{
	Matrix res;
	for(register int i=1;i<=r;i++)
	{
		res[i][i]=1;
	}
	while(exponent)
	{
		if(exponent&1)
		{
			res=res*base;
		}
		base=base*base,exponent>>=1;
	}
	return res;
}
int main()
{
	kk=read(),n=read(),x[1][1]=1;
	for(register int i=1;i<=kk;i++)
	{
		r=max(r,d=read()),mat[d][1]++;
	}
	for(register int i=2;i<=r;i++)
	{
		mat[i-1][i]=1;
	}
	mat[++r][1]=1,x[1][r]=mat[r][r]=1,x=x*qpow(mat,n);printf("%d\n",x[1][1]);
}
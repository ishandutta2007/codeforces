#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=1e9+7;
struct Matrix{
	ll num[6][6];
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
Matrix mat,mat2,x,x2;
ll f1,f2,f3,c,res;
li n;
inline li read()
{
    register li num=0,neg=1;
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
inline Matrix operator *(Matrix x,Matrix y)
{
	Matrix res;
	for(register int i=1;i<=5;i++)
	{
		for(register int j=1;j<=5;j++)
		{
			for(register int k=1;k<=5;k++)
			{
				res[i][j]=(res[i][j]+(li)x[i][k]*y[k][j]%(MOD-1))%(MOD-1);
			}
		}
	}
	return res;
}
inline Matrix qpow(Matrix base,li exponent)
{
	Matrix res;
	for(register int i=1;i<=5;i++)
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
	n=read(),f1=read(),f2=read(),f3=read(),c=read(),res=1;
	mat[1][1]=mat[2][1]=mat[3][1]=mat[1][2]=mat[2][3]=mat[4][4]=mat[5][4]=1;
	mat[5][5]=x[1][5]=mat2[1][1]=1,mat[4][1]=2,mat[5][1]=MOD-5,x[1][4]=3;
	mat2[2][1]=mat2[3][1]=mat2[1][2]=mat2[2][3]=x2[1][3]=1;
	res=qpow(c,(x*qpow(mat,n-3))[1][1]);
	res=(li)res*qpow(f1,(x2*qpow(mat2,n-3))[1][1])%MOD,x2[1][3]=0,x2[1][2]=1;
	res=(li)res*qpow(f2,(x2*qpow(mat2,n-3))[1][1])%MOD,x2[1][2]=0,x2[1][1]=1;
	res=(li)res*qpow(f3,(x2*qpow(mat2,n-3))[1][1])%MOD,printf("%d\n",res);
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=61,MOD=1e9+7;
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
ll m,kk,res;
li n;
ll mp[151];
char ch[3];
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
inline Matrix operator *(Matrix x,Matrix y)
{
	Matrix res;
	for(register int i=1;i<=m;i++)
	{
		for(register int j=1;j<=m;j++)
		{
			for(register int k=1;k<=m;k++)
			{
				res[i][j]=(res[i][j]+(li)x[i][k]*y[k][j]%MOD)%MOD;
			}
		}
	}
	return res;
}
inline Matrix qpow(Matrix base,li exponent)
{
	Matrix res;
	for(register int i=1;i<=m;i++)
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
	for(register int i=0;i<26;i++)
	{
		mp[i+'a']=i+1,mp[i+'A']=i+27;
	}
	n=read(),m=read(),kk=read();
	for(register int i=1;i<=m;i++)
	{
		x[1][i]=1;
		for(register int j=1;j<=m;j++)
		{
			mat[i][j]=1;
		}
	}
	for(register int i=1;i<=kk;i++)
	{
		scanf("%s",ch+1),mat[mp[ch[1]]][mp[ch[2]]]=0;
	}
	x=x*qpow(mat,n-1);
	for(register int i=1;i<=m;i++)
	{
		res=(res+x[1][i])%MOD;
	}
	printf("%d\n",res);
}
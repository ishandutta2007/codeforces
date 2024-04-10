/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-09-29 21:09:17
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
const int N=310;
#define i64 long long
const i64 mod=1000000007;
i64 n,k,C[N][N],f[N][N],p[N],P[N];
i64 power(i64 a,i64 b,i64 p)
{
	i64 r=1;
	while(b)
	{
		if(b&1)
			r=r*a%p;
		a=a*a%p;
		b>>=1;
	}
	return r;
}
int main()
{
	n=read();
	k=read();
	fr(i,0,n)
		C[i][i]=C[i][0]=1;
	fr(i,1,n)
		fr(j,1,i-1)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	f[0][0]=1;
	fr(i,0,n)
	{
		p[i]=power(k,i,mod);
		P[i]=power(k-1,i,mod);
	}
	fr(i,1,n)
		fr(j,1,n)
			fr(l,0,j)
				f[i][j]=(f[i][j]+f[i-1][l]*C[n-l][j-l]%mod*(p[l]+mod-(l==j?P[l]:0))%mod*P[n-j])%mod;
/*	fr(i,1,n)
		fr(j,1,n)
			printf("%I64d%c",f[i][j],j==n?'\n':' ');*/
	printf("%I64d\n",f[n][n]);
	return 0;
}
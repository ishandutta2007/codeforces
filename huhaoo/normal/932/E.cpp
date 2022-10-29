/***************************************************************
	File name: E.cpp
	Author: huhao
	Create time: Tue 09 Jun 2020 02:49:08 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
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
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
#define i64 long long
const int N=5010,mod=1000000007,i2=(mod+1)/2;
i64 n,k,s[N][N],ans;
i64 power(i64 a,i64 b,i64 p)
{
	i64 r=1;
	for(;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p;
	return r;
}
int main()
{
	n=read(); k=read(); s[0][0]=1;
	fr(i,1,k) fr(j,1,i) s[i][j]=(s[i-1][j]*j+s[i-1][j-1])%mod;
	for(i64 j=0,Ans=power(2,n,mod);j<=k;Ans=Ans*i2%mod*(n-j)%mod,j++) ans+=s[k][j]*Ans%mod;
	printf("%lld\n",ans%mod);
	return 0;
}
/***************************************************************
	File name: D.cpp
	Author: huhao
	Create time: Thu 14 May 2020 03:55:21 PM CST
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
const int N=300010,mod=998244353;
i64 power(i64 a,i64 b,i64 p)
{
	i64 r=1;
	for(;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p;
	return r;
}
i64 inv(i64 a){ return power(a%mod+mod,mod-2,mod); }
i64 n,f[N],m,a[N],ans,A[N],B[N];
// f_i  im
int main()
{
	n=read();
	fr(i,1,n) m+=(a[i]=read());
	fr(i,0,m-1)
	{
		i64 I=inv(m+n*i-2*i-i*(n-1)%mod*(i?A[i-1]:0));
		A[i]=(m-i)*I%mod; B[i]=((n-1)*m%mod+i*(n-1)%mod*(i?B[i-1]:0)%mod)*I%mod;
	}
	fd(i,m-1,0) f[i]=(f[i+1]*A[i]+B[i])%mod;
//	fr(i,0,m-1) printf("%d%c",(int)f[i],i==m-1?'\n':' ');
	ans=(mod+1-n)*f[0]%mod;
	fr(i,1,n) ans=(ans+f[a[i]]+mod)%mod;
	ans=ans*inv(n)%mod;
	printf("%d\n",(int)ans);
	return 0;
}
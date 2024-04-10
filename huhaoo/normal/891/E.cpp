/***************************************************************
	File name: E.cpp
	Author: huhao
	Create time: Wed 10 Jun 2020 08:13:16 PM CST
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
const int N=5010,mod=1000000007;
i64 power(i64 a,i64 b,i64 p)
{
	i64 r=1;
	for(;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p;
	return r;
}
i64 inv(i64 a){ return power(a,mod-2,mod); }
i64 n,k,I[N],f[N],F[N],g[N],a[N],ans;
inline i64 Mod(i64 a){ return a>=mod?a-mod:a; }
inline i64 &Add(i64 &a,i64 b){ return a=Mod(a+b); }
void dp(i64 *F,i64 *f,i64 a)
{
	fr(i,0,n) F[i]=0;
	fr(i,0,n-1)
	{
		Add(F[i+1],mod-f[i]);
		Add(F[i],f[i]*a%mod);
	}
}
void idp(i64 *F,i64 *f,i64 a)
{
	F[n]=0;
	fd(i,n-1,0) F[i]=Mod(mod-(f[i+1]-a*F[i+1])%mod);
}
int main()
{
	n=read(); k=read();
	fr(i,1,n) a[i]=read();
	fr(i,1,n) I[i]=inv(i);
	f[0]=1;
	fr(i,1,n)
	{
		dp(F,f,a[i]);
		fr(j,0,i) f[j]=F[j];
	}
	fr(i,1,n)
	{
		idp(F,f,a[i]);
		fr(j,0,n-1) Add(g[j],F[j]);
	}
//	fr(i,0,n) printf("%lld%c",g[i],i==end_i?'\n':' ');
	fr(i,0,n-1)
	{
		i64 A=inv(i+1)*power(n,mod-1-1-i,mod)%mod;
		fr(j,0,i) A=A*(k-j)%mod;
		Add(ans,g[i]*A%mod);
	}
	printf("%lld\n",ans);
	return 0;
}
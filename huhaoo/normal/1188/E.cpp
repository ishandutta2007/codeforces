/***************************************************************
	File name: E.cpp
	Author: huhao
	Create time: Thu 11 Mar 2021 02:24:19 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<assert.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
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
const int N=1000010,mod=998244353;
i64 n,f[N],F[N],m;
i64 a[N],c[N];
i64 ans;
i64 power(i64 a,i64 b,i64 p)
{
	i64 r=1;
	for(;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p;
	return r;
}
i64 C(i64 a,i64 b){ return f[a]*F[b]%mod*F[a-b]%mod; }
i64 Q(i64 a,i64 b){ return C(a+b-1,a-1); }
int main()
{
	n=1000000; f[0]=1; fr(i,1,n) f[i]=f[i-1]*i%mod;
	F[n]=power(f[n],mod-2,mod); fd(i,n,1) F[i-1]=F[i]*i%mod;
	n=read();
	fr(i,1,n) m+=(a[i]=read());
	fr(i,1,n) c[a[i]]++;
	fr(i,1,m) c[i]+=c[i-1];
	std::sort(a+1,a+n+1);
	int flag=0;
	fr(i,1,n) if(c[i-1]>i){ flag=1; break; }
	if(flag)
	{
		ans=1;
		fr(i,1,n)
			if(c[i-1]<=i) ans+=Q(n,i-c[i-1]);
			else break;
	}
	else
	{
		i64 t=0;
		memset(c,0,sizeof(c));
		fr(i,1,n){ c[a[i]%n]++; t+=a[i]%n; }
		fr(i,0,n-1)
		{
			ans+=Q(n,(m-t)/n);
			t-=n; t+=c[i]*n;
		}
	}
	printf("%lld\n",ans%mod);
	return 0;
}
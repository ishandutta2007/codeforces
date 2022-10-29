/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-12-27 22:52:24
****************************************************************/
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
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#define i64 long long
i64 power(i64 a,i64 b,i64 p)
{
	i64 r=1;
	while(b)
	{
		if(b&1) r=r*a%p;
		a=a*a%p; b>>=1;
	}
	return r;
}
const int N=1000010,mod=998244353;
i64 inv(i64 a){ return power(a,mod-2,mod); }
i64 n,p1[N],p2[N],ans;
int main()
{
	n=read();
	fr(i,1,n)
	{
		int m=read();
		fr(j,1,m)
		{
			int p=read();
			p1[p]+=inv(n); p2[p]+=inv(n)*inv(m)%mod;
		}
	}
	fr(i,1,1000000) ans+=(p1[i]%mod)*(p2[i]%mod)%mod;
	printf("%d\n",int(ans%mod));
	return 0;
}
/**************************************************************
	File name: 1043F.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 11/2/2018, 3:36:37 PM
**************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
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
#define mod 998244353
#define N 300010
long long n,a,c[N],f[N],p[N],t[N],m;
long long power(long long x,long long y,long long p)
{
	long long r=1;
	while(y)
	{
		if(y&1)r=r*x%p;
		x=x*x%p;
		y>>=1;
	}
	return r;
}
int main()
{
	n=read();
	fr(i,1,n)
	{
		a=read();
		c[a]++;
	}
	m=300000;
	fr(i,1,m)
		fr(j,2,m/i)
			c[i]+=c[i*j];
	p[0]=1;
	fr(i,1,m)p[i]=p[i-1]*i%mod;
	t[m]=power(p[m],mod-2,mod);
	fd(i,m,1)t[i-1]=t[i]*i%mod;
	fr(i,1,7)
	{
		fd(j,m,1)
		{
			if(c[j]>=i)
				f[j]=p[c[j]]*t[i]%mod*t[c[j]-i]%mod;
			else f[j]=0;
			fr(k,2,m/j)f[j]=(f[j]-f[j*k]+mod)%mod;
		}
		if(f[1]>0){printf("%d\n",i);return 0;}
	}
	printf("-1\n");
	return 0;
}
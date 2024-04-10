/**************************************************************
	File name: 1045H.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 1/9/2019, 2:49:19 PM
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
#define N 100010
#define mod 1000000007
char x[N],y[N];
long long a,b,c,d;
long long f[N],pf[N],n;
long long C(long long a,long long b)
{
	return f[a]*pf[b]%mod*pf[a-b]%mod;
}
long long calc(long long a,long long b)
{
	if(b==0)
		return a==0;
	return C(a+b-1,b-1);
}
long long calc(char *s,long long a,long long b,long long c,long long d,long long op)
{
	while(s[1]=='0')
		s++;
	long long l=strlen(s+1);
	if(l<=a+b+c+d)
		return 0;
	if(b!=c&&b+1!=c)
		return 0;
	if(l>a+b+c+d+1)
	{
		return calc(d,b+1)*calc(a,c);
	}
	long long r=0;
	fr(i,2,l)
		if(s[i]=='0')
		{
			if(s[i-1]=='0')
				a--;
			else
				c--;
		}
		else
		{
			if(s[i-1]=='0')
			{
				if(a>0)
					if(b==c||b==c+1)
						r=(r+calc(d,b)*calc(a-1,c+1))%mod;
			}
			else
			{
				if(c>0)
					if(b+1==c||b==c)
					{
						r=(r+calc(d,b)*calc(a,c))%mod;
					}
			}
			if(s[i-1]=='0')
				b--;
			else
				d--;
			if(a<0||b<0||c<0||d<0)
				break;
		}
	return (r+(a==0&&b==0&&c==0&&d==0)*op)%mod;
}
long long pow(long long a,long long b,long long m)
{
	long long r=1;
	a%=m;
	while(b)
	{
		if(b&1)
			r=r*a%m;
		a=a*a%m;
		b>>=1;
	}
	return r;
}
int main()
{
	scanf("%s",x+1);
	scanf("%s",y+1);
	a=read();
	b=read();
	c=read();
	d=read();
	n=100001;
	f[0]=1;
	fr(i,1,n)
		f[i]=f[i-1]*i%mod;
	pf[n]=pow(f[n],mod-2,mod);
	fd(i,n-1,0)
		pf[i]=pf[i+1]*(i+1)%mod;
	printf("%lld\n",(calc(y,a,b,c,d,1)-calc(x,a,b,c,d,0)+mod)%mod);
	return 0;
}
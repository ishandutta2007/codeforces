/****************************************************************
	File name: 1096G.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 1/1/2019, 4:05:09 PM
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(long long i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(long long i=(a),_end_=(b);i>=_end_;i--)
long long read()
{
	long long r=0,t=1,c=getchar();
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
#define N 4000010
#define mod 998244353
long long r[N],l,a[N],b[N],ans[N],l1,la,n,k;
#define g 3
#define gp 332748118
long long pow(long long a,long long b,long long p)
{
	long long r=1;
	while(b)
	{
		if(b&1)
			r=r*a%p;
		a=a*a%p;
		b>>=1;
	}
	return r;
}
void NTT(long long *a,int opt)
{
	fr(i,0,(1<<l)-1)
		if(i<r[i])
			swap(a[i],a[r[i]]);
	fr(i,0,l-1)
	{
		long long wn=pow(opt==1?g:gp,(mod-1)>>(i+1),mod);
		for(int j=0;j<(1<<l);j+=(1<<(i+1)))
		{
			long long w=1;
			fr(k,0,(1<<i)-1)
			{
				long long x=a[j+k],y=w*a[j+k+(1<<i)]%mod;
				a[j+k]=(x+y)%mod;
				a[j+k+(1<<i)]=(x-y+mod)%mod;
				w=w*wn%mod;
			}
		}
	}
	if(opt==-1)
	{
		int inv=pow(1<<l,mod-2,mod);
		fr(i,0,(1<<l)-1)
			a[i]=a[i]*inv%mod;
	}
}
long long c[N];
void times(long long *a,long long &n,long long *b,long long m)
{
	n=n+m;
	fr(i,0,m)
		c[i]=b[i];
	while((1<<l)<=n)
		l++;
	fr(i,1,(1<<l)-1)
		r[i]=((i&1)<<(l-1))|(r[i>>1]>>1);
	NTT(a,1);
	NTT(b,1);
	fr(i,0,(1<<l)-1)
		a[i]=a[i]*b[i]%mod;
	NTT(a,-1);
	fr(i,0,m)
		b[i]=c[i];
	fr(i,n+1,(1<<l)-1)
		a[i]=0;
	fr(i,m+1,(1<<l)-1)
		b[i]=0;
}
int main()
{
	n=read()/2;
	k=read();
	fr(i,1,k)
		a[read()]=1;
	fr(i,0,9)
		if(a[i])
			l1=i;
	ans[la=0]=1;
	while(n)
	{
		if(n&1)
			times(ans,la,a,l1);
		fr(i,0,l1)b[i]=a[i];
		times(a,l1,b,l1);
		n>>=1;
	}
	long long a=0;
	fr(i,0,la)
		a=(a+ans[i]*ans[i])%mod;
	printf("%lld\n",a);
	return 0;
}
/***************************************************************
	File name: 438E.cpp
	Author: huhao
	Create time: Mon 14 Oct 2019 07:35:30 PM CST
***************************************************************/
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
		r=r*10+c-48;
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
		if(b&1)
			r=r*a%p;
		a=a*a%p;
		b>>=1;
	}
	return r;
}
const int N=(1<<19)|10;
const i64 mod=998244353,g=3;
const i64 gi=power(g,mod-2,mod);
namespace NTT
{
	i64 r[N],l;
	void init(int n)
	{
		l=0;
		while((1<<l)<n)
			l++;
		fr(i,0,(1<<l)-1)
			r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	}
	void NTT(i64 *a,i64 opt)
	{
		fr(i,0,(1<<l)-1)
			if(i<r[i])
				swap(a[i],a[r[i]]);
		fr(i,0,l-1)
		{
			i64 wn=power(opt==1?g:gi,(mod-1)>>(i+1),mod);
			for(int j=0;j<(1<<l);j+=(1<<(i+1)))
			{
				i64 w=1;
				fr(k,0,(1<<i)-1)
				{
					i64 x=a[j+k],y=w*a[j+k+(1<<i)]%mod;
					a[j+k]=(x+y)%mod;
					a[j+k+(1<<i)]=(x-y+mod)%mod;
					w=w*wn%mod;
				}
			}
		}
		if(opt==-1)
		{
			i64 I=power(1<<l,mod-2,mod);
			fr(i,0,(1<<l)-1)
				a[i]=a[i]*I%mod;
		}
	}
	i64 I1[N],I2[N];
	void inv(i64 *b,i64 *a,i64 n)
	{
		if(n==1)
		{
			b[0]=power(a[0],mod-2,mod);
			return;
		}
		inv(b,a,(n+1)>>1);
		init(n+n);
		fr(i,0,(1<<l)-1)
			I1[i]=I2[i]=0;
		fr(i,0,n-1)
		{
			I1[i]=a[i];
			I2[i]=b[i];
		}
		NTT(I1,1);
		NTT(I2,1);
		fr(i,0,(1<<l)-1)
			I1[i]=I1[i]*I2[i]%mod*I2[i]%mod;
		NTT(I1,-1);
		fr(i,0,n-1)
			b[i]=(b[i]*2-I1[i]+mod)%mod;
	}
	i64 S1[N],S2[N];
	const i64 i2=power(2,mod-2,mod);
	void sqrt(i64 *b,i64 *a,i64 n)
	{
		if(n==1)
		{
			b[0]=1;//a[0]=1
			return;
		}
		sqrt(b,a,(n+1)>>1);
		fr(i,0,(1<<l)-1)
			S1[i]=S2[i]=0;
		inv(S1,b,n);
		fr(i,0,n-1)
		{
			S1[i]=S1[i]*i2%mod;
			S2[i]=b[i];
		}
		init(n+n);
		NTT(S1,1);
		NTT(S2,1);
		fr(i,0,(1<<l)-1)
			S2[i]=S2[i]*S2[i]%mod;
		NTT(S2,-1);
		fr(i,n,(1<<l)-1)
			S2[i]=0;
		fr(i,0,n-1)
			S2[i]=(S2[i]+a[i])%mod;
		NTT(S2,1);
		fr(i,0,(1<<l)-1)
			S1[i]=S1[i]*S2[i]%mod;
		NTT(S1,-1);
		fr(i,0,n-1)
			b[i]=S1[i];
	}
}
i64 m,n,C[N],F[N],A[N],B[N];
int main()
{
	m=read();
	n=read()+1;
	fr(i,1,m)
		C[read()]=1;
	fr(i,0,n-1)
		A[i]=((i==0)-4*C[i]%mod+mod)%mod;
	NTT::sqrt(B,A,n);
	B[0]++;
	memset(A,0,sizeof(A));
	NTT::inv(A,B,n);
	fr(i,0,n-1)
		A[i]=(A[i]*2+(i==0?mod-1:0))%mod;
	fr(i,1,n-1)
		printf("%lld\n",A[i]);	
	return 0;
}
/*
10 100
9 95 37 56 39 86 59 5 68 82
 */
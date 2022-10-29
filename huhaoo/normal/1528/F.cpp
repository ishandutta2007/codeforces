/***************************************************************
	File name: F.cpp
	Author: huhao
	Create time: Sat 19 Jun 2021 08:07:45 AM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<assert.h>
#define i64 long long
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
const int N=1<<18|10,mod=998244353,g=3;
inline i64 Mod(i64 a){ return a>=mod?a-mod:a; }
i64 power(i64 a,i64 b,i64 p=mod)
{
    i64 r=1;
    for(;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p;
    return r;
}
i64 l,r[N],w[N];
void init(int n)
{
    l=0;
    while((1<<l)<n) l++;
    fr(i,0,(1<<l)-1) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
    w[0]=1;
    w[1]=power(g,(mod-1)>>l,mod);
    fr(i,2,(1<<l)) w[i]=w[i-1]*w[1]%mod;
}
void ntt(i64 *a,int opt)
{
    fr(i,0,(1<<l)-1) if(i<r[i]) std::swap(a[i],a[r[i]]);
    fr(i,0,l-1)
    {
        static int W[N];
        fr(k,0,(1<<i)-1) W[k]=w[opt==1?k<<(l-i-1):(1<<l)-(k<<(l-i-1))];
        for(int j=0; j<(1<<l); j+=(1<<(i+1))) fr(k,0,(1<<i)-1)
        {
            i64 x=a[j+k],y=a[j+k+(1<<i)]*W[k]%mod;
            a[j+k]=Mod(x+y); a[j+k+(1<<i)]=Mod(x-y+mod);
        }
    }
    i64 I=power(1<<l,mod-2,mod);
    if(opt==-1) fr(i,0,(1<<l)-1) a[i]=a[i]*I%mod;
}
i64 f[N],F[N],_f[N];
int n,m; i64 ans;
i64 A[N],B[N],s[N];
int main()
{
	m=read(); n=read(); f[0]=1;
	fr(i,1,n) f[i]=f[i-1]*i%mod;
	F[n]=power(f[n],mod-2);
	fd(i,n,1) F[i-1]=F[i]*i%mod;
	_f[0]=1;
	fr(i,1,n) _f[i]=_f[i-1]*(m-i+1)%mod;
	fr(i,0,n)
	{
		A[i]=(i&1?mod-1:1)*F[i]%mod;
		B[i]=power(i,n)*F[i]%mod;
	}
	init(n+n+1); ntt(A,1); ntt(B,1);
	fr(i,0,(1<<l)-1) s[i]=A[i]*B[i]%mod;
	ntt(s,-1);
//	fr(i,0,n) printf("%lld%c",s[i],i==end_i?'\n':' ');
	fr(i,1,std::min(n,m)) ans=(ans+s[i]*_f[i]%mod*power(m+1,m-i))%mod;
	printf("%lld\n",ans);
	return 0;
}
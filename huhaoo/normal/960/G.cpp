/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-02-17 16:00:30
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
const int N=1<<19|10,mod=998244353;
i64 power(i64 a,i64 b,i64 p)
{
	i64 r=1; a%=p;
	for(;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p;
	return r;
}
i64 inv(i64 a){ return power(a,mod-2,mod); }
const i64 g=3,G=inv(g);
namespace C
{
	i64 f[N],F[N];
	void init(int n)
	{
		f[0]=1;
		fr(i,1,n) f[i]=f[i-1]*i%mod;
		F[n]=inv(f[n]);
		fd(i,n,1) F[i-1]=F[i]*i%mod;
	}
	i64 inv(int n){ return n==0?1:f[n-1]*F[n]%mod; }
	i64 C(int a,int b){ return f[a]*F[b]%mod*F[a-b]%mod; }
}
namespace poly
{
	int l,r[N];
	i64 w[N];
	void init(int n)
	{
		l=0;
		while((1<<l)<=n) l++;
		fr(i,0,(1<<l)-1) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
		w[0]=1; w[1]=power(g,(mod-1)>>l,mod);
		fr(i,2,(1<<l)) w[i]=w[i-1]*w[1]%mod;
	}
	i64 Mod(i64 a){ return a>=mod?a-mod:a; }
	void NTT(i64 *a,int opt)
	{
		fr(i,0,(1<<l)-1) if(i<r[i]) std::swap(a[i],a[r[i]]);
		fr(i,0,l-1) for(int j=0;j<(1<<l);j+=(1<<(i+1))) fr(k,0,(1<<i)-1)
		{
			i64 x=a[j+k],y=a[j+k+(1<<i)]*w[opt==1?k<<(l-i-1):(1<<l)-(k<<(l-i-1))]%mod;
			a[j+k]=Mod(x+y); a[j+k+(1<<i)]=Mod(x-y+mod);
		}
		if(opt==-1)
		{
			i64 I=inv(1<<l);
			fr(i,0,(1<<l)-1) a[i]=a[i]*I%mod;
		}
	}
	i64 A[N],B[N];
	void Inv(i64 *o,i64 *a,int n)
	{
		if(n==1){ *o=inv(*a); return ; }
		fr(i,0,n-1) o[i]=0;
		Inv(o,a,(n+1)>>1);
		// o=2o'-ao'^2
		init(n+n+1);
		fr(i,0,(1<<l)-1) A[i]=B[i]=0;
		fr(i,0,n-1){ A[i]=a[i]; B[i]=o[i]; }
		NTT(A,1); NTT(B,1);
		fr(i,0,(1<<l)-1) A[i]=(2*B[i]-A[i]*B[i]%mod*B[i]%mod+mod)%mod;
		NTT(A,-1);
		fr(i,0,n-1) o[i]=A[i];
	}
	i64 _C[N],D[N];
	void ln(i64 *o,i64 *a,int n)
	{
		init(n+n+1); fr(i,0,(1<<l)-1) _C[i]=D[i]=0;
		fr(i,0,n-2) _C[i]=a[i+1]*(i+1)%mod;
		_C[n-1]=0; Inv(D,a,n);
	//	fr(i,0,n-1) fprintf(stderr,"%d%c",int(a[i]),i==n-1?'\n':' ');
	//	fr(i,0,n-1) fprintf(stderr,"%d%c",int(C[i]),i==n-1?'\n':' ');
	//	fr(i,0,n-1) fprintf(stderr,"%d%c",int(D[i]),i==n-1?'\n':' ');
		init(n+n+1); NTT(_C,1); NTT(D,1);
		fr(i,0,(1<<l)-1) _C[i]=_C[i]*D[i]%mod;
		NTT(_C,-1);
		fr(i,1,n-1) o[i]=_C[i-1]*C::inv(i)%mod;
		o[0]=0;
	}
	i64 E[N],F[N];
	void exp(i64 *o,i64 *a,int n)
	{
		// o=o'-(ln o'-a)o'
		if(n==1){ *o=1; return ; }
		fr(i,0,n-1) o[i]=0;
		exp(o,a,(n+1)>>1);
		init(n+n+1);
		fr(i,0,(1<<l)-1) E[i]=F[i]=0;
		ln(E,o,n);
		fr(i,0,n-1){ E[i]=(a[i]-E[i]+mod)%mod; F[i]=o[i]; }
		E[0]++;
		init(n+n+1); NTT(E,1); NTT(F,1);
		fr(i,0,(1<<l)-1) E[i]=E[i]*F[i]%mod;
		NTT(E,-1);
		fr(i,0,n-1) o[i]=E[i];
	}
}
using poly::init; using poly::NTT; using poly::Inv; using poly::ln; using poly::exp; using poly::l;
i64 _A[N],_B[N],_C[N];
void solve(i64 *a,int n)
{
	if(n==1)
	{
		a[0]=0; a[1]=1; return;
	}
	if(n&1)
	{
		solve(a,n-1);
		fd(i,n-1,0){ a[i+1]=(a[i+1]+a[i])%mod; a[i]=a[i]*(n-1)%mod; }
		return ;
	}
	n/=2; solve(a,n);
	init(n+n+1);
	fr(i,0,(1<<l)-1) _A[i]=_B[i]=_C[i]=0;
	fr(i,0,n)
	{
		_A[i]=a[i]; _B[i]=C::f[i]*a[i]%mod; _C[n-i]=power(n,i,mod)*C::F[i]%mod;
	}
	NTT(_B,1); NTT(_C,1);
	fr(i,0,(1<<l)-1) _C[i]=_C[i]*_B[i]%mod;
	NTT(_C,-1);
	fr(i,0,(1<<l)-1) _B[i]=0;
	fr(i,0,n) _B[i]=_C[i+n]*C::F[i]%mod;
	NTT(_B,1); NTT(_A,1);
	fr(i,0,(1<<l)-1) _A[i]=_A[i]*_B[i]%mod;
	NTT(_A,-1);
	fr(i,0,n+n) a[i]=_A[i];
}
i64 n,a[N];
int main()
{
	n=read(); C::init(n+n);
	if(n==1){ printf("%d\n",read()==1&&read()==1); return 0; }
	solve(a,n-1);
	int x=read(),y=read();
	if(!x||!y||(x==1&&y==1)) printf("0\n");
	else printf("%lld\n",a[x+y-2]*C::C(x+y-2,x-1)%mod);
	return 0;
}
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
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
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#include<complex>
#include<vector>
#define comp std::complex<long double>
const int N=1<<17|10;
const long double pi=3.14159265358979353;
int n,m,mod;
i64 ans;
comp a[N],b[N];
i64 power(i64 a,i64 b)
{
	i64 r=1; a%=mod;
	for(;b;b>>=1,a=a*a%mod) if(b&1) r=r*a%mod;
	return r;
}
int l,r[N];
void init(int n){ l=0; while((1<<l)<n) l++; fr(i,0,(1<<l)-1) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1)); }
void fft(comp *a,int opt)
{
	fr(i,0,(1<<l)-1) if(i<r[i]) std::swap(a[i],a[r[i]]);
	fr(i,0,l-1)
	{
		static comp w[N];
		fr(k,0,(1<<i)-1) w[k]={std::cos(pi*k/(1<<i)),opt*sin(pi*k/(1<<i))};
		for(int j=0;j<(1<<l);j+=(1<<(i+1))) fr(k,0,(1<<i)-1)
		{
			comp x=a[j+k],y=a[j+k+(1<<i)]*w[k];
			a[j+k]=x+y; a[j+k+(1<<i)]=x-y;
		}
	}
}
void mul(i64 *A,i64 *B,i64 *C,int op=0)
{
	if(op)
	{
		static i64 _a[N],_b[N];
		fr(i,0,n-1){ _a[i]=A[i]; _b[i]=B[i]; C[i]=0; }
		fr(i,0,n-1) fr(j,0,2) if(i+j<n) C[i+j]=(C[i+j]+_a[i]*_b[j])%mod;
		return ;
	}
	init(n+n);
	fr(i,0,(1<<l)-1) a[i]=b[i]=0;
	fr(i,0,n-1){ a[i]=A[i]; b[i]=B[i]; } //{ a[i]=A[i]>=mod/2?A[i]-mod:A[i]; b[i]=B[i]>=mod/2?B[i]-mod:B[i]; }
	fft(a,1);
	if(A==B) fr(i,0,(1<<l)-1) b[i]=a[i];
	else fft(b,1);
	fr(i,0,(1<<l)-1) a[i]=a[i]*b[i];
	fft(a,-1);
//	fr(i,0,n-1) printf("%I64d%c",A[i],i==n-1?'\n':' ');
//	fr(i,0,n-1) printf("%I64d%c",B[i],i==n-1?'\n':' ');
	fr(i,0,n-1) C[i]=(((i64)(a[i].real()/(1<<l)+0.5))%mod+mod)%mod;
//	fr(i,0,n-1) printf("%I64d%c",C[i],i==n-1?'\n':' ');
}
int q[N],Q;
i64 f[N],g[N],h[N];
int main()
{
	n=read(); m=read(); mod=read();
	n--; n-=(n&1);
	for(int t=2;t<=m;t<<=1)
	{
		Q++; q[Q]=m/t-2; ans++;
		if(q[Q]<=0){ Q--; continue; }
		q[Q]=(q[Q]+1)/2;
	}
	if(!Q){ printf("%I64d\n",ans); return 0; }
	h[0]=1; h[1]=2; h[2]=1; n++;
	if(q[Q]==1)
	{
		f[0]=1; f[1]=2; f[2]=1;
		g[0]=1;
	}
	else
	{
		f[0]=1; f[1]=4; f[2]=6; f[3]=4; f[4]=1;
		g[0]=2; g[1]=2; g[2]=1;
	}
//	printf("%d\n",n);
	fr(i,0,n-1) ans=(ans+g[i])%mod;
	fr(i,0,n-2) ans=(ans+g[i])%mod;
//	fr(j,0,n-1) printf("%I64d%c",g[j],j==n-1?'\n':' ');
//	fr(i,1,Q) printf("%d%c",q[i],i==Q?'\n':' ');
	fd(i,Q-1,1)
	{
//		printf("%d  %d\n",i,q[i]);
		f[0]++; mul(f,g,g); f[0]--; mul(f,f,f);
		fr(j,1,q[i]-q[i+1]*2)
		{
			mul(g,h,g,1); g[0]++; mul(f,h,f,1);
		}
		fr(j,0,n-1) ans=(ans+g[j])%mod;
		fr(j,0,n-2) ans=(ans+g[j])%mod;
//		fr(j,0,n-1) printf("%I64d%c",f[j],j==n-1?'\n':' ');
//		fr(j,0,n-1) printf("%I64d%c",g[j],j==n-1?'\n':' ');
	}
	printf("%I64d\n",ans%mod);
	return 0;
}
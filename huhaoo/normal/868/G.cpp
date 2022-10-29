/***************************************************************
	File name: G.cpp
	Author: huhao
	Create time: Tue 23 Mar 2021 02:33:04 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<assert.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
i64 read()
{
	i64 r=0,t=1,c=getchar();
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
#include<array>
const int mod=1000000007,i2=(mod+1)/2;
#define vec std::array<i64,6>
#define info std::array<vec,3>
i64 power(i64 a,i64 b,i64 p)
{
	i64 r=1; a%=mod;
	for(;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p;
	return r;
}
i64 inv(i64 a){ return power(a,mod-2,mod); }
vec R,U,E;
vec operator+(vec a,vec b)
{
	return {(a[0]+b[0]*a[1])%mod,a[1]*b[1]%mod,(a[2]+(b[2]+b[0]*a[3])%mod*a[1])%mod,(a[3]+b[3])%mod,(a[4]+(b[4]+b[0]*a[5])%mod*a[1])%mod,(a[5]+b[5])%mod};
}
vec operator*(vec a,i64 b) // b>0
{
	if(b<=0) assert(0);
	vec r=a; b--;
	for(;b;b>>=1,a=a+a) if(b&1) r=r+a;
	return r;
}
i64 p[1000],q;
void gcd(i64 n,i64 m)
{
	if(!m) return ;
	if(n>m)
	{
		gcd(m,n); p[++q]=-1; return ;
	}
	i64 k=m/n; gcd(n,m-n*k); p[++q]=k;
}
void solve(i64 n,i64 m)
{
	R={1,1,0,1,0,0}; U={0,i2,0,0,0,1}; E={0,1,0,0,0,0}; q=0;
	gcd(n,m);
//	fr(i,1,q) printf("%lld%c",p[i],i==q?'\n':' ');
	info f={R,U,E}; p[1]--;
	if(p[1])
	{
		fd(i,q,1)
			if(p[i]==-1) f={f[1],f[0],f[2]};
			else f={f[0]+f[1]*p[i],f[1],f[2]+f[1]*p[i]};
	}
	vec ans=R+f[2]+U;
//	for(auto i:ans) printf("%lld ",i);; putchar(10);
	i64 a1=ans[0],a2=ans[2],a3=ans[4],t=ans[1],I=inv((t-1)*(t-1));
	a2=((a2-a2*t+a1*t%mod*(n%mod))%mod*I%mod+mod)%mod;
	a3=((a3-a3*t+a1*t%mod*(m%mod))%mod*I%mod+mod)%mod;
	a1=a1*inv(1-t+mod)%mod;
//	printf("%lld %lld %lld\n",a1,a2,a3);
	printf("%lld\n",inv(n%mod)*(n%mod*a1%mod-(m%mod*a2-n%mod*a3)%mod*i2%mod+mod)%mod);
}
int main()
{
	fr(T,1,read()){ i64 n=read(),m=read(); solve(n,m); }
	return 0;
}
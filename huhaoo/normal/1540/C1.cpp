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
const int N=110,mod=1000000007;
i64 power(i64 a,i64 b,i64 p=mod)
{
	i64 r=1; a%=p;
	for(;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p;
	return r;
}
i64 inv(i64 a){ return power(a,mod-2); }
i64 n,q,x,m,c[N],b[N],s[N];
i64 f[N][N*N],ans;
int main()
{
	n=read();
	fr(i,1,n) c[i]=read();
	fr(i,2,n) b[i]=read()+b[i-1];
	fr(i,2,n) s[i]=s[i-1]-b[i];
	q=read(); x=read();
	f[0][0]=1; m=0;
	fr(i,1,n)
	{
		fr(j,0,m) fr(k,0,c[i]) f[i][j+k]=(f[i][j+k]+f[i-1][j])%mod;
		m+=c[i];
		fr(j,0,m) if(j+s[i]<x*i) f[i][j]=0;
	}
	fr(i,0,m) ans+=f[n][i];
	printf("%I64d\n",ans%mod);
	return 0;
}
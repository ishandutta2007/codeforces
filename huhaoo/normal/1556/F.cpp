#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9'){ t=c=='-'?-1:1; c=getchar(); }
	while(c>='0'&&c<='9'){ r=(r<<3)+(r<<1)+(c^48); c=getchar(); }
	return r*t;
}
const int N=20,mod=1000000007;
i64 n,v[N],p[N][N],f[1<<14|10];
i64 power(i64 a,i64 b,i64 p=mod)
{
	i64 r=1;
	for(;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p;
	return r;
}
int main()
{
	n=read();
	fr(i,0,n-1) v[i]=read();
	fr(i,0,n-1) fr(j,0,n-1) p[i][j]=v[i]*power(v[i]+v[j],mod-2)%mod;
	i64 ans=0;
	fr(i,1,(1<<n)-1)
	{
		f[i]=1; int I=i&(i-1);
		for(int j=I;j;j=I&(j-1))
		{
			int k=i^j; i64 s1=1,s2=1;
			fr(p1,0,n-1) if((j>>p1)&1) fr(p2,0,n-1) if((k>>p2)&1){ s1=s1*p[p1][p2]%mod; s2=s2*p[p2][p1]%mod; }
			f[i]=((f[i]-s1*f[j]-s2*f[k])%mod+mod)%mod;
			if(i==end_i) fr(p1,0,n-1) if((j>>p1)&1) ans=(ans+s1*f[j])%mod;
			if(i==end_i) fr(p2,0,n-1) if((k>>p2)&1) ans=(ans+s2*f[k])%mod;
		}
//		printf("%d%c",int(f[i]*4%mod),i==end_i?'\n':' ');
	}
	printf("%I64d\n",(ans+n*f[(1<<n)-1])%mod);
//	printf("%d\n",clock());
	return 0;
}
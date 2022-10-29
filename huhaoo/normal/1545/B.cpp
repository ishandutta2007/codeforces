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
const int N=400010,mod=998244353;
i64 power(i64 a,i64 b,i64 p=mod)
{
	i64 r=1;
	for(;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p;
	return r;
}
i64 n,f[N],F[N];
char s[N];
int a,b;
int main()
{
	f[0]=1; n=N-10; fr(i,1,n) f[i]=f[i-1]*i%mod;
	F[n]=power(f[n],mod-2); fd(i,n,1) F[i-1]=F[i]*i%mod;
	fr(T,1,read())
	{
		n=read(); a=b=0;
		scanf("%s",s+1);
		for(int i=1,j;i<=n;i=j)
		{
			j=i+1;
			if(s[i]=='0'){ a++; continue; }
			while(j<=n&&s[j]=='1') j++;
			b+=(j-i)/2;
		}
		printf("%I64d\n",f[a+b]*F[a]%mod*F[b]%mod);
	}
	return 0;
}
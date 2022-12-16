#include<bits/stdc++.h>
using namespace std;
const int N=500005;
const int M=998244353;
int n,a[N],i,s;
long long f[N],c[N],x,y,z,ans[N],tp;
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		s+=a[i];
	}
	long long is=qpow(s,M-2),in=qpow(n-1,M-2);
	c[1]=1-n;
	f[0]=f[1]=1;
	for(i=1;i<s;++i)
	{
		x=i*is%M,y=(s-i)*is%M*in%M;
		z=qpow(y,M-2);
		f[i+1]=(f[i]*(x+y)-f[i-1]*x)%M*z%M;
		c[i+1]=(c[i]*(x+y)-1-c[i-1]*x)%M*z%M;
	}
	ans[0]=-c[s]*qpow(f[s],M-2)%M;
	for(i=1;i<s;++i)
		ans[i]=(f[i]*ans[0]+c[i])%M;
	for(i=1;i<=n;++i)
		tp+=ans[a[i]];
	tp-=ans[0]*(n-1);
	cout<<(tp%M*qpow(n,M-2)%M+M)%M;
}
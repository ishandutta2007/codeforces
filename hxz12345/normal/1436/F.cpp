#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
LL sum0[100005],sum1[100005],sum2[100005],f[100005],cnt,maxn,n;
LL QuickPow(LL x,LL p)
{
	if(p<0)	return 0;
	LL ans=1,base=x;
	while(p)
	{
		if(p&1)	ans=ans*base%MOD;
		base=base*base%MOD;
		p>>=1;
	}
	return ans;
}
int main(){
	scanf("%lld",&n);
	for(LL i=1;i<=n;++i)
	{
		LL x,v;
		scanf("%lld %lld",&x,&v);
		sum0[x]=v;
		sum1[x]=x*v%MOD;
		sum2[x]=x*x%MOD*v%MOD;
		maxn=max(maxn,x);
	}
	for(LL i=1;i<=maxn;++i)	for(LL j=2;j*i<=maxn;++j)	sum0[i]+=sum0[i*j];
	for(LL i=1;i<=maxn;++i)	for(LL j=2;j*i<=maxn;++j)	(sum1[i]+=sum1[i*j])%=MOD;
	for(LL i=1;i<=maxn;++i)	for(LL j=2;j*i<=maxn;++j)	(sum2[i]+=sum2[i*j])%=MOD;
	for(LL i=1;i<=maxn;++i)
	{
		if(sum0[i]<=1)	continue;
		(f[i]+=((sum0[i]-1+MOD)%MOD*QuickPow(2,(sum0[i]-2))%MOD*sum2[i]%MOD)%MOD)%=MOD;
		(f[i]+=((sum0[i]-2+MOD)%MOD*QuickPow(2,(sum0[i]-3))%MOD*((sum1[i]*sum1[i]%MOD+MOD-sum2[i])%MOD)%MOD+QuickPow(2,(sum0[i]-2))*((sum1[i]*sum1[i]%MOD+MOD-sum2[i])%MOD)))%=MOD;
	}
	for(LL i=maxn;i;--i)	for(LL j=2;j*i<=maxn;++j)	(f[i]+=MOD-f[i*j])%=MOD;
	printf("%lld",f[1]);
	return 0;
}
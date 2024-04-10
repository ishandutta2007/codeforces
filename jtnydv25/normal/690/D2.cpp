#include <bits/stdc++.h>
#define ll long long
#define mod 1000003
#define upperlimit 1000100
#define INF 1000000100
#define INFL 1000000000000000100
#define eps 1e-8
#define endl '\n'
#define sd(n) scanf("%d",&n)
#define slld(n) scanf("%lld",&n)
#define pd(n) printf("%d",n)
#define plld(n) printf("%lld",n)
#define pds(n) printf("%d ",n)
#define pllds(n) printf("%lld ",n)
#define pdn(n) printf("%d\n",n)
#define plldn(n) printf("%lld\n",n)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define F first
#define S second

using namespace std;

ll gcd(ll n1,ll n2){
	if(n1%n2==0)return n2;
	return gcd(n2,n1%n2);
}
ll powmod(ll base,ll exponent)
{
	ll ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		exponent/=2;
	}
	return ans;
}
ll fact[upperlimit+1];
ll C(int n,int r){
	ll ret=fact[n];
	ret*=powmod((fact[r]*fact[n-r])%mod,mod-2);
	return (ret%mod);
}
int main()
{
	fact[0]=1;
	int i,j,n,c,k;
	sd(n);
	sd(c);
	for(i=1;i<=upperlimit;i++)fact[i]=(i*fact[i-1])%mod;
	ll answer=(mod-1+C(n+c,c))%mod;
	plld(answer);
	return 0;
}
#include<cstdio>
#include<iostream>
#include<cmath>
#define INF 0x7f7f7f7f
#define mod 1000000007
#define maxn 5000005
#define ll long long
using namespace std;
ll fast(ll x,ll y,ll k){
	ll s=1;
	while(y){
		if(y%2)s=s*x%k;
		x=x*x%k;
		y=y>>1;
	}return s;
}
ll n=5000000;
ll isp[maxn];
ll p[maxn],cnt;
void init(){
	isp[1]=1;
	for(ll i=2;i<=n;i++){
		if(!isp[i]) p[++cnt]=i;
		for(ll j=1;j<=cnt&&i*p[j]<=n;j++){
			isp[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
ll f[5000005],it=1;
ll dfs(ll x){
	if(x==1) return 0;
	if(f[x]) return f[x];
	ll ans=x*(x-1)/2;
	if(isp[x]) for(ll i=1;i<=cnt&&p[i]<x;i++){
		if(x%p[i]==0){
			ans=min(ans,x/p[i]*dfs(p[i])+dfs(x/p[i]));
			break;
		}
	}
	return f[x]=ans;
}
int main(){
	init();
	ll t,l,r,ans=0;
	scanf("%lld%lld%lld",&t,&l,&r);
	for(ll i=l;i<=r;i++){
		ans+=dfs(i)%mod*it%mod;
		ans%=mod;
		it=it*t%mod;
	}
	printf("%lld",ans);
	return 0;
}
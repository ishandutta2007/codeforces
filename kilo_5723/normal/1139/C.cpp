#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,maxm=2e5+5,maxk=105;
const ll mod=1e9+7;
int fa[maxn],cnt[maxn];
int findf(int u){
	if (fa[u]==u) return u;
	return fa[u]=findf(fa[u]);
}
ll power(ll a,ll b){
	if (!b) return 1;
	if (b&1) return power(a*a%mod,b>>1)*a%mod;
	return power(a*a%mod,b>>1);
}
ll cal(int c,int n,int k){
	int i;
	ll ans=0;
	for (i=1;i<k;i++)
		ans=(ans+power(c,i)*power(n,k-i-1)%mod*(n-c)%mod)%mod;
	return ans;
}
int main(){
	int i,j,n,k;
	int u,v,w;
	ll ans;
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++) fa[i]=i;
	for (i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		if (!w) fa[findf(u)]=findf(v);
	}
	for (i=1;i<=n;i++) cnt[findf(i)]++;
	ans=0;
	for (i=1;i<=n;i++) if (cnt[findf(i)]){
		ans=(ans+cal(cnt[findf(i)],n,k))%mod;
		cnt[findf(i)]=0;
	}
	printf("%I64d\n",(ans+mod)%mod);
	return 0;
}
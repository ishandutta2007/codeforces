#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int maxn=25,mod=1000000007;
int n;
ll s;
ll f[maxn];
ll num[(1<<20)+5],sum[(1<<20)+5];
ll read(){
	ll x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
ll power(ll x,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*x%mod;
		x=x*x%mod;
		b>>=1;
	}
	return ans;
}
ll C(ll n,ll m){
	if(n<m)return 0;
	ll pai1=1,pai2=1;
	for(ll i=n-m+1;i<=n;i++)pai1=pai1*(i%mod)%mod;
	for(int i=1;i<=m;i++)pai2=pai2*i%mod;
	return pai1*power(pai2,mod-2)%mod;
}
signed main(){
	n=read();s=read();
	for(int i=0;i<n;i++)f[i]=read();
	ll ans=0,mx=1,c=0;
	for(int i=0;i<(1<<n);i++){
		if(i==2*mx)mx=2*mx,c++;
		if(i){
			num[i]=num[i-mx]+1;
			sum[i]=sum[i-mx]+f[c]+1;
		}
		ll op=(num[i]&1)?-1:1;
		ans=((ans+op*C(s+n-1-sum[i],n-1)%mod)%mod+mod)%mod;
//		cout<<i<<" "<<num[i]<<" "<<sum[i]<<" "<<ans<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}
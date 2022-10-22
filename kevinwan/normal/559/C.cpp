#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
 
const int mn = 2e5+10;
const ll mod = 1e9+7;
pii p[mn];

ll dp[mn],fact[mn],ifact[mn];
ll po(ll a,ll b=mod-2){
	ll ans=1;
	for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
	return ans;
}

ll ch(ll a, ll b){
	return fact[a]*ifact[b]%mod*ifact[a-b]%mod;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	fact[0]=ifact[0]=1;
	for(int i=1;i<mn;i++)fact[i]=fact[i-1]*i%mod,ifact[i]=po(fact[i]);
	int h,w,n;
	cin>>h>>w>>n;
	for(int i=0;i<n;i++){
		cin>>p[i].first>>p[i].second;
	}
	p[n]={1,1};
	sort(p,p+n+1);
	for(int i=n;i>=0;--i){
		dp[i]=ch(h+w-p[i].first-p[i].second,h-p[i].first);
		for(int j=i+1;j<=n;j++)if(p[i].second<=p[j].second){
			dp[i]-=ch(p[j].first+p[j].second-p[i].first-p[i].second,p[j].first-p[i].first)*dp[j];
			dp[i]%=mod;
		}
	}
	if(dp[0]<0)dp[0]+=mod;
	printf("%lld\n",dp[0]);
}
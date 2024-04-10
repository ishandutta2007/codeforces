#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
 
const int mn = 3e5+10;
const ll mod = 1e9+7;
 
int n,m,k,p;
ll h[mn],a[mn],tar[mn],num[mn];
bool solve(ll fin){
	ll req=0;
	for(int i=0;i<n;i++){
		tar[i]=max(0LL,h[i]+a[i]*m-fin);
		req+=(tar[i]+p-1)/p;
	}
	for(int i=0;i<=m;i++)num[i]=0;
	if(req>m*k)return 0;
	for(int i=0;i<n;i++){
		if(!tar[i])continue;
		ll st=(tar[i]-1)%p+1;
		while(st<=tar[i]){
			ll t=(st-h[i]+a[i]-1)/a[i];
			if(t<0)t=0;
			num[t]++;
			st+=p;
		}
	}
	ll rem = 0;
	for(int i=0;i<m;i++){
		rem+=num[i];
		rem-=min(rem,ll(k));
	}
	rem+=num[m];
	return rem==0;
}
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin>>n>>m>>k>>p;
	for(int i=0;i<n;i++)cin>>h[i]>>a[i];
	ll l=0, r=1e14;
	while(l<r){
		ll m=(l+r)/2;
		if(solve(m))r=m;
		else l=m+1;
	}
	printf("%lld\n",l);
}
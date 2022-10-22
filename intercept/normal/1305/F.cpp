#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int M=2e5+9;
int n;
ll a[M];
vector<ll>b;
void get(ll x){
	for(int i=2,s=sqrt(x)+1;i<=s;++i){
		if(x%i==0)b.pb(i);
		while(x%i==0)x/=i;
	}
	if(x>1)b.pb(x);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	shuffle(a+1,a+1+n,mt19937 (time(0)));
	for(int i=1;i<=min(n,50);++i){
		get(a[i]);
		get(a[i]+1);
		get(a[i]-1);
	}
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	ll ans=2e18;
	for(auto o:b){
		ll sum=0;
		for(int i=1;i<=n;++i){
			ll x=a[i]%o;
			if(a[i]<o&&x)sum+=o-x;
			else sum+=min(o-x,x);
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
/*
*/
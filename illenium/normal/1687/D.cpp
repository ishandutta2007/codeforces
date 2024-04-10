#include<bits/stdc++.h>
using namespace std;
#define N 2000200
typedef long long ll;
int n;
ll a[N];
inline bool check(ll k){
	if(k<0)return false;
	ll t=sqrt(a[1]+k);
	while((t+1)*(t+1)<=a[1]+k)++t;
	while(t*t>a[1]+k)--t;
	for(;;++t){
		int u=upper_bound(a+1,a+n+1,t*(t+1)-k)-a;
		if(u>n)return true;
		if(a[u]+k<(t+1)*(t+1))return false;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(check(0)){
		cout<<0<<'\n';
		return 0;
	}
	ll ans=1e18;
	for(int i=1;i<=n;++i){
		for(int z=1;i==1||z<=a[i]-a[i-1]+1;++z){
			ll k=1LL*z*z-a[i];
			if(check(k)){
				ans=min(ans,k);
				break;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
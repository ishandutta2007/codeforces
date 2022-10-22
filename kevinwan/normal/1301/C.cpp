#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=4e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
ll a[mn];
int main(){
	#ifdef LOCAL_PROJECT
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#else
	cin.tie(0);
	cin.sync_with_stdio(0);
	#endif
	int tc;
	cin>>tc;
	while(tc--){
		ll n,m;
		cin>>n>>m;
		ll z=n-m;
		m++;
		ll a=z/m,e=z-a*m,ne=m-e;
		ll ans=ne*a*(a+1)/2+e*(a+1)*(a+2)/2;
		ans=n*(n+1)/2-ans;
		printf("%lld\n",ans);
	}
}
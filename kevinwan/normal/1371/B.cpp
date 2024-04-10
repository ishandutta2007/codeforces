#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e3+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;

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
		ll n,r;
		cin>>n>>r;
		if(r<n){
			printf("%lld\n",r*(r+1)/2);
		}
		else{
			ll one=n*(n-1)/2;
			one++;
			printf("%lld\n",one);
		}
	}
}
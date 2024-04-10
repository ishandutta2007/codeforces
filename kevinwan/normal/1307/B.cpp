#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=2e5+10;
const int inf=0x3f3f3f3f;
int a[mn];
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
		int n;
		ll x;
		cin>>n>>x;
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		bool don=0;
		for(int i=0;i<n;i++)if(!don&&a[i]==x){
			printf("1\n");
			don=1;
		}
		if(!don)printf("%lld\n",max(2LL,(x+a[n-1]-1)/a[n-1]));
	}
}
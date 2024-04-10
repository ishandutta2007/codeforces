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
const ll inf=0x3f3f3f3f3f3f3f3f;

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
   		int n;
   		cin>>n;
   		for(int i=0;i<n;i++)cin>>a[i];
   		for(int i=2;i<n;i++)a[i]+=a[i-2];
   		ll ans=0;
   		ll sm=0;
   		for(int i=1;i<n;i+=2){
   			ans=max(ans,a[i]-a[i-1]-sm);
   			sm=min(sm,a[i]-a[i-1]);
   		}
   		sm=-a[0];
   		cerr<<sm<<endl;
   		for(int i=2;i<n;i+=2){
   			cerr<<a[i]-a[i-1]-sm<<' ';
   			ans=max(ans,a[i-1]-a[i]-sm);
   			sm=min(sm,a[i-1]-a[i]);
   		}
   		cerr<<endl;
   		ans+=a[(n-1)/2*2];
   		printf("%lld\n",ans);
   	}
}
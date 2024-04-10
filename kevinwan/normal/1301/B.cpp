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
		int n;
		cin>>n;
		vector<ll>v;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i+1<n;i++){
			if(a[i]==-1&&a[i+1]!=-1)v.push_back(a[i+1]);
			if(a[i]!=-1&&a[i+1]==-1)v.push_back(a[i]);
		}
		sort(v.begin(),v.end());
		ll k=v.size()?((v[0]+v.back())/2):0;
		for(int i=0;i<n;i++)if(a[i]==-1)a[i]=k;
		ll ans=-1;
		for(int i=0;i+1<n;i++)ans=max(ans,abs(a[i+1]-a[i]));
		printf("%lld %lld\n",ans,k);
	}
}
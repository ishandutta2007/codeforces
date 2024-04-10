#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=2e5+10;
inline ll sq(ll x){return x*x;}
ll a[mn],num[20];
int main(){
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	#else
		cin.tie(0);
		cin.sync_with_stdio(0);
	#endif
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<20;j++)if((a[i]>>j)&1)num[j]++;
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		ll v=0;
		for(int j=0;j<20;j++)if(num[j]>=i+1)v+=1LL<<j;
		ans+=sq(v);
	}
	printf("%lld",ans);
}
#include<bits/stdc++.h>
using namespace std;
#define N 1000100
const int mod=998244353;
typedef long long ll;
int n,k,a[N];
void Solve(){
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	rotate(a,a+n-k,a+n);
	bool o=true;
	for(int i=0;i<n;++i){
		o&=a[i]<=0||a[i]+k<=i;
	}
	if(!o){
		cout<<0<<'\n';
		return;
	}
	int ans=1;
	for(int i=0;i<n;++i){
    	if(a[i]==0){
    		ans=1LL*ans*(min(k,i)+1)%mod;
    	}
    	else if(a[i]==-1){
    		ans=1LL*ans*(i+1)%mod;
    	}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}
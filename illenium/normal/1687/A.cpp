#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N],k;
ll s[N];
void Solve(){
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(k>n){
		for(int i=1;i<=n;++i){
			a[i]+=k-n;
		}
		k=n;
	}
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	ll ans=0;
	for(int i=1;i<=n-k+1;++i){
		ans=max(ans,s[i+k-1]-s[i-1]);
	}
	ans+=1LL*k*(k-1)/2;
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}
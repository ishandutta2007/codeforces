//#prama GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pp;
#define endl '\n';
void solve(){
	int n,k;
	ll b,s;
	cin>>n>>k>>b>>s;
	ll div = s-b*k;
	if (div<0 || div>ll(k-1)*n){
		cout<<"-1\n";
		return;
	}
	ll real = s-div;
	for(int i = 1;i<=n;i+=1){
		ll cur = real;
		real = 0;
		int g = min(ll(k-1),div);
		div -= g;
		cur += g;
		cout<<cur<<' ';
	}
	cout<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
	cin>>tt;
	while(tt--){
		solve();
	}
}
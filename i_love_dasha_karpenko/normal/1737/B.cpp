#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
ll F(ll n){
	ll l = 0,r = sqrt(n);
	while(l!=r){
		ll mid = (l+r+1)/2;
		if (mid*(mid+2)<=n){
			l = mid;
		}
		else{
			r = mid-1;
		}
	}
	ll last = l*(l+2);
	ll nxt = last+1;
	ll ans = l*3;
	while(nxt<=n){
		ans += 1;
		nxt += l+1;
	}
	return ans;
}
void solve(){
	ll l,r;
	cin>>l>>r;
	cout<<F(r)-F(l-1)<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}
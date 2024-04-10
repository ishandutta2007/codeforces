#include<iostream>
using namespace std;
typedef long long ll;
int n;
ll h;
ll l[200001],r[200001];
ll p[200001];
ll f(ll pos){
	int lol=lower_bound(l+1,l+n+1,pos)-l-1;
	ll ans=pos;
	if(lol!=0) ans=pos-p[lol-1];
	ans-=min(pos,r[lol])-l[lol];
	return ans;
}
ll st(ll pos){
	ll li=pos,ri=2e9;
	while(li!=ri){
		ll mid=(li+ri)/2;
		if(f(mid)-f(pos)>=h) ri=mid;
		else li=mid+1;
	}
	return li-pos;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> h;
	for(int i=1; i<=n ;i++){
		cin >> l[i] >> r[i];
		p[i]=p[i-1]+r[i]-l[i];
	}
	ll ans=0;
	for(int i=1; i<=n ;i++){
		ans=max(ans,st(l[i]));
	}
	cout << ans << endl;
}
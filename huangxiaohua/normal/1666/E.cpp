#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll i,j,k,n,m,t,sb,a[100500],res[100500],ans=2e9;
int chk(ll x){
	ll l,r,md,cl,cr;
	l=1;r=1e9;
	while(l<=r){
		md=(l+r)/2;
		cl=cr=0;
		for(i=1;i<=n;i++){
			cl=max(cl+md,a[i]);
			cr=min(cr+md+x,a[i+1]);
			if(cr<a[i]){l=md+1;goto aaa;}
			if(cl>a[i+1]){r=md-1;goto aaa;}
		}
		if(cr<m){l=md+1;goto aaa;}
		return md;
		aaa:;
	}
	return 0;
}
pair<ll,ll> fuck(ll d,ll l,ll r){
	if(d==n){res[d]=m;return {m,m};}
	auto [cl,cr]=fuck(d+1,max(a[d+1],l+sb),min(a[d+2],r+sb+ans));
	l=max(l,cl-sb-ans);r=min(r,cr-sb);
	res[d]=r;
	return {l,r};
}
int main(){
	ios::sync_with_stdio(0);
	cin>>m>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	a[n+1]=m;
	ll l=0,r=1e9,md;
	while(l<=r){
		md=(l+r)/2;
		if(chk(md)){
			ans=min(ans,md);
			r=md-1;
		}
		else l=md+1;
	}
	sb=chk(ans);
	fuck(0,0,0);
	for(i=0;i<n;i++)cout<<res[i]<<' '<<res[i+1]<<'\n';
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,l,res=1e9;
string s;
pair<ll,ll> f[1005000];
#define fi first
#define se second

ll chk2(ll md){
	ll i,j,k;
	for(i=1;i<=n;i++){
		f[i]=f[i-1];f[i].fi+=s[i];
		j=max(0ll,i-l);
		f[i]=min(f[i],{f[j].fi+md,f[j].se+1});
	}
	return f[n].se;
}

void chk(){
	ll l=0,r=1e6,md,sb,ans;
	while(l<=r){
		md=(l+r)/2;
		sb=chk2(md);
		if(sb==m){ans=md;break;}
		if(sb<m)ans=min(ans,md),r=md-1;
		else l=md+1;
	}
	chk2(ans);res=min(res,f[n].fi-ans*m);
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m>>l>>s;s="X"+s;
	for(auto &i:s)i=(i>='a');
	chk();
	for(auto &i:s)i^=1;
	chk();
	cout<<res;
}
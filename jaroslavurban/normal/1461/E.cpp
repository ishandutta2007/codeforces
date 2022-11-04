#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

unordered_map<ll,bool>vis;
ll k,l,r,t,x,y;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>k>>l>>r>>t>>x>>y;
	ll safeadd=max(l,r-y);
	ll delta=y-x;
	if(delta<0){
		if(k>safeadd){
			ll stepsafe=(k-safeadd)/x;
			t-=stepsafe;
			if(t<=0){cout<<"Yes\n";return 0;}
			--t;
			k-=stepsafe*x;
			if(k>safeadd)k-=x;
			if(k<l){cout<<"No\n";return 0;}
		}
		ll canstep=(k-l)/-delta;
		assert(canstep>=0);
		t-=canstep;
		if(t<=0){cout<<"Yes\n";return 0;}
		else cout<<"No\n";
		return 0;
	}
	if(delta==0){
		ll stepsdown=(k-l)/x;
		k-=stepsdown*x;
		t-=stepsdown;
		if(t<=0){cout<<"Yes\n";return 0;}
		if(k+y<=r)cout<<"Yes\n";
		else cout<<"No\n";
		return 0;
	}
	ll cur=k;
	while(1){
		ll aboveplace=cur;
		if(cur+y<=r){
			ll abovesteps=(safeadd-cur)/delta+1;
			aboveplace=cur+delta*abovesteps;
			t-=abovesteps;
			//cerr<<cur<<" "<<delta<<" "<<abovesteps<<endl;
//			cerr<<abovesteps<<endl;
		}
		ll belowsteps=(aboveplace-safeadd)/x+!!((aboveplace-safeadd)%x);
		ll belowrsteps=(aboveplace-(r-y))/x+!!((aboveplace-(r-y))%x);
		ll belowplace=aboveplace-x*belowsteps;
		if(belowsteps)t-=belowsteps-1;
		if(t<=0){cout<<"Yes\n";return 0;}
		if(belowsteps!=belowrsteps){cout<<"No\n";return 0;}
		if(belowsteps)--t;
		if(belowplace<l){cout<<"No\n";return 0;}
		if(vis[belowplace]){cout<<"Yes\n";return 0;}
		vis[belowplace]=true;
//		cerr<<belowplace<<endl;
		cur=belowplace;
	}

}
#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif
#define int 		long long
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;

void solve(){
	int n;
	ll r;
	cin>>n>>r;
	vi l(n);
	vi t(n);
	rep(i,0,n)cin>>l[i];
	rep(i,0,n)cin>>t[i];
	rep(i,0,n){
		if(l[i]>t[i]){
			cout<<-1;
			return;
		}
	}
	l.resize(n+1);
	for(int i=n;i>0;i--){
		l[i]=l[i-1];
	}
	partial_sum(all(l),l.begin());
	int last=INT_MIN;
	ll ans=0;
	vi anss;
	ll curtime=0;
	rep(i,0,n){
		// bridge from l[i]...l[i+1]
		// time = t[i]
		if(last>l[i]){
			int maxlim=min(last,l[i+1]);
			curtime+=maxlim-l[i];
			t[i]-=maxlim-l[i];
			l[i]=maxlim;
		}
		if(l[i]==l[i+1])continue;
		if(t[i]>=(l[i+1]-l[i])*2){
			curtime+=(l[i+1]-l[i])*2;
			continue;
		}
		int halfspeed=2*(t[i]-(l[i+1]-l[i]));
		t[i]-=halfspeed;
		l[i]+=halfspeed/2;
		curtime+=halfspeed;
		int shots=((l[i+1]-l[i])+r-1)/r;
		int tempshots=shots;
		int tempcurtime=curtime;
		rep(_,0,tempshots){
			if(sz(anss)<100000){
				anss.pb(tempcurtime);
				tempcurtime+=r;
			}
			else{
				break;
			}
		}
		ans+=shots;
		last=l[i]+shots*r;
		curtime+=(l[i+1]-l[i]);
	}
	cout<<ans<<endl;
	if(ans<=100000)
		for(auto i:anss)cout<<i<<" ";
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
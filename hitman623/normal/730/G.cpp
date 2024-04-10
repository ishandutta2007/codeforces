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

bool intersect(pii a,pii b){
	return !(a.F>b.S or a.S<b.F);
}

void solve(){
	int n;
	cin>>n;
	set<pii>x;
	rep(_,0,n){
		int a,b;
		cin>>a>>b;
		bool good=0;
		for(auto i:x){
			if(intersect(i,mp(a,a+b-1)))good=1;
		}
		if(!good){
			cout<<a<<" "<<a+b-1<<endl;
			x.insert(mp(a,a+b-1));			
		}
		else{
			if(!intersect(mp(1,1+b-1),*x.begin())){
				cout<<1<<" "<<b<<endl;
				x.insert({1,b});
				continue;
			}
			vector<pii>temp(all(x));
			temp.pb(mp(LLONG_MAX,LLONG_MAX));
			rep(i,1,sz(temp)){
				if(temp[i].F-1-temp[i-1].S>=b){
					cout<<temp[i-1].S+1<<" "<<temp[i-1].S+b<<endl;
					x.insert(mp(temp[i-1].S+1,temp[i-1].S+b));
					break;
				}
			}
		}
	}
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
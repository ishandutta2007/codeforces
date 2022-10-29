#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

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
	cin>>n;
	vector<pii>x(n);
	rep(i,0,n)cin>>x[i].F>>x[i].S,x[i].S+=x[i].F;
	vector<pii>v(n);
	rep(i,0,n)v[i].F=x[i].S,v[i].S=i;
	sort(all(v));
	int idx=0;
	queue<pii>q;
	while(idx<n and v[idx].F==v[0].F){
		q.push(v[idx]);
		idx++;
	}
	vector<int>ans(n,-1);
	while(!q.empty()){
		auto curfuck=q.front();
		q.pop();
		int curnum=curfuck.F+1;
		while(idx<n and v[idx].F==curnum){
			q.push(v[idx++]);
		}
		if(ans[curfuck.S]!=-1)continue;
		ans[curfuck.S]=curfuck.F;
		if(curfuck.S>0){
			q.push(mp(curfuck.F+1,curfuck.S-1));
		}
		if(curfuck.S<n-1){
			q.push(mp(curfuck.F+1,curfuck.S+1));	
		}
	}
	ll sum1=0,sum2=0;
	rep(i,0,n){
		sum1+=ans[i];
		sum2+=x[i].F;
		if(ans[i]==-1)assert(false);
		if(ans[i]<x[i].F){
			cout<<-1;
			return;
		}
	}
	cout<<sum1-sum2<<endl;
	rep(i,0,n)cout<<ans[i]<<" ";
}

int main(){
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
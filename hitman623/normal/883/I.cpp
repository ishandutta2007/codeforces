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

vi x;
int n,k;

bool isGood(int mid){
	vector<bool>v(n+1);
	v[0]=1;
	vector<int>s;

	rep(i,1,n+1){
		if(i-k<0)continue;
		if(v[i-k])s.pb(x[i-k]);
		if(!s.empty() and x[i-1]-s.back()<=mid)v[i]=1;
	}
	return v.back();
}

void solve(){
	cin>>n>>k;
	x.resize(n);
	rep(i,0,n)cin>>x[i];
	sort(all(x));
	int mina=-1;
	int maxa=1e9+1;
	while(maxa-mina>1){
		int mid=mina+(maxa-mina)/2;
		if(isGood(mid))maxa=mid;
		else mina=mid;
	}
	cout<<maxa;
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
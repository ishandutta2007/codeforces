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
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;

char query(int a,int b){
	cout<<"? "<<a<<" "<<b<<endl;
	char ch;
	cin>>ch;
	return ch;
}

void solve(){
	int n;
	cin>>n;
	vector<int>mina,maxa;
	rep(i,1,n/2+1){
		char ch=query(i*2-1,i*2);
		if(ch=='>')maxa.pb(i*2-1),mina.pb(2*i);
		else mina.pb(i*2-1),maxa.pb(2*i);
	}
	if(n%2){
		maxa.pb(n);
		mina.pb(n);
	}
	while(sz(mina)>1){
		vi temp;
		rep(i,0,sz(mina)/2){
			char ch=query(mina[2*i],mina[2*i+1]);
			if(ch=='>')temp.pb(mina[2*i+1]);
			else temp.pb(mina[2*i]);
		}
		if(sz(mina)%2)temp.pb(mina.back());
		mina=temp;
	}
	vi ans;
	ans.pb(mina[0]);
	mina=maxa;

	while(sz(mina)>1){
		vi temp;
		rep(i,0,sz(mina)/2){
			char ch=query(mina[2*i],mina[2*i+1]);
			if(ch=='<')temp.pb(mina[2*i+1]);
			else temp.pb(mina[2*i]);
		}
		if(sz(mina)%2)temp.pb(mina.back());
		mina=temp;
	}
	ans.pb(mina[0]);
	cout<<"! "<<ans[0]<<" "<<ans[1]<<endl;
}

int main(){
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
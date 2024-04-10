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
	set<string>s;
	rep(_,0,n){
		string p;
		cin>>p;
		string ch;
		for(auto i:p){
			if(i=='h'){
				while(!ch.empty() and ch.back()=='k')ch.pop_back();
				ch.pb('h');
			}
			else if(i=='u')ch.pb('o'),ch.pb('o');
			else ch.pb(i);
		}
		s.insert(ch);
	}
	cout<<sz(s);
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
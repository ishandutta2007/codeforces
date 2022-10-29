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
	string s;
	cin>>s;
	int k;
	cin>>k;
	vector<bool>c(26);
	for(auto i:s)if(i!='*')c[i-'a']=1;
	vi b(26);
	int cntr=0;
	rep(i,0,k){
		string p;
		cin>>p;
		bool good=1;
		rep(j,0,n){
			if(s[j]=='*'){
				if(c[p[j]-'a'])good=0;
			}
			else{
				if(s[j]!=p[j])good=0;
			}
		}
		if(good){
			cntr++;
			set<int>q;
			for(auto j:p)if(c[j-'a']==0)q.insert(j-'a');
			for(auto j:q)b[j]++;
		}
	}
	cout<<count(all(b),cntr);
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
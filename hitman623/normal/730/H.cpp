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
	int n,m;
	cin>>n>>m;
	vector<string>v(n);
	rep(i,0,n)cin>>v[i];
	vi x(m);
	rep(i,0,m)cin>>x[i],x[i]--;
	rep(i,0,m){
		if(sz(v[x[i]])!=sz(v[x[0]])){
			cout<<"No\n";
			return;
		}
	}
	int k=sz(v[x[0]]);
	string ans(k,'.');
	rep(i,0,k){
		set<char>l;
		rep(j,0,m){
			l.insert(v[x[j]][i]);
		}
		if(sz(l)>1)ans[i]='?';
		else ans[i]=v[x[0]][i];
	}
	int cnt=0;
	rep(i,0,n){
		if(sz(v[i])!=k)continue;
		bool good=1;
		rep(j,0,k){
			if(ans[j]=='?')continue;
			if(v[i][j]!=ans[j])good=0;
		}
		cnt+=good;
	}
	if(cnt==m){
		cout<<"Yes\n";
		cout<<ans;
	}
	else{
		cout<<"No\n";
	}
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
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

vi diradj[300005];
vi undiradj[300005];
bool visitable[300005];
bool visitable2[300005];
set<pii>unedges;
void solve(){
	int n,m,s;
	cin>>n>>m>>s;
	vector<pair<int,pii>>edges(m);
	rep(i,0,m){
		int ch,u,v;
		cin>>ch>>u>>v;
		edges[i]=mp(ch,mp(u,v));
		if(ch==1)diradj[u].pb(v);
		else undiradj[u].pb(v),undiradj[v].pb(u);
	}
	queue<int>q;
	q.push(s);
	int vismin=0,vismax=0;
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		if(visitable[cur])continue;
		visitable[cur]=1;
		vismin++;
		for(auto i:diradj[cur]){
			q.push(i);
		}
	}
	rep(i,1,n+1){
		if(visitable[i])q.push(i);
	}
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		if(visitable2[cur])continue;
		vismax++;
		visitable2[cur]=1;
		if(visitable[cur]==0){
			for(auto i:diradj[cur])q.push(i);
			visitable[cur]=1;
		}
		for(auto i:undiradj[cur]){
			if(visitable2[i]==0)
				q.push(i),unedges.insert(mp(cur,i));
		}
	}
	cout<<vismax<<endl;
	vi anss;
	for(auto i:edges){
		if(i.F==2)if(unedges.count(mp(i.S.S,i.S.F)))cout<<"-",anss.pb('-');else cout<<"+",anss.pb('+');
	}
	cout<<endl;
	cout<<vismin<<endl;
	for(auto i:anss)cout<<char('-'+'+'-i);

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
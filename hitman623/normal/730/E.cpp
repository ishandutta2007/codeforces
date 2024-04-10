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
int indeg[101];
vi a[101];
void solve(){
	int n;
	cin>>n;
	vector<pii>x(n+1),rank;
	rep(i,1,n+1)
	{
		cin>>x[i].F>>x[i].S;
		rank.pb({-x[i].F,i});
	}
	sort(all(rank));
	rep(i,1,n+1){
		if(x[i].S==0) continue;
		rep(j,i+1,n+1){
			if(x[j].S==0) continue;
			if(x[i].F<x[j].F)
			{
				if(x[i].F+x[i].S>=x[j].F && x[i].F+x[i].S<x[j].F+x[j].S)
				a[i].pb(j),indeg[j]++;
				else if(x[j].F+x[j].S<=x[i].F && x[j].F+x[j].S>x[i].F+x[i].S)
				a[j].pb(i),indeg[i]++;
			}
			else
			{
				if(x[j].F+x[j].S>x[i].F && x[j].F+x[j].S<=x[i].F+x[i].S)
				a[j].pb(i),indeg[i]++;
				else if(x[i].F+x[i].S<x[j].F && x[i].F+x[i].S>=x[j].F+x[j].S)
				a[i].pb(j),indeg[j]++;
			}
		}
	}
	queue<int> q;
	rep(i,1,n+1){
		if(indeg[i]==0)
			q.push(i);
	}
	vi p;
	while(!q.empty())
	{
		int d=q.front();
		p.pb(d);
		q.pop();
		for(auto i:a[d])
		{
			indeg[i]--;
			if(indeg[i]==0) q.push(i);
		}
	}
	int ans=0;
	rep(i,0,n)
	{
		int initial,final;
		rep(j,0,n)
			if(rank[j].S==p[i])
				{
					initial=j;
					rank[j].F=-(x[p[i]].F+x[p[i]].S);
				}
		sort(all(rank));
		rep(j,0,n)
			if(rank[j].S==p[i])
				final=j;
		ans+=abs(final-initial);
	}
	cout<<ans;
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
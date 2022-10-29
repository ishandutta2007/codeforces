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
	vi x(n);
	rep(i,0,n){
		cin>>x[i];
	}
	int cost=*min_element(all(x));
	for(;cost>0;cost--){
		priority_queue<pii>pq;
		rep(i,0,n){
			if(x[i]>cost)
				pq.push(mp(x[i],i));
		}
		vector<pii>games;
		while(sz(pq)>1){
			auto cur1=pq.top();
			pq.pop();
			auto cur2=pq.top();
			pq.pop();
			games.pb(mp(cur1.S,cur2.S));
			cur1.F--;
			cur2.F--;
			if(cur1.F>cost)pq.push(cur1);
			if(cur2.F>cost)pq.push(cur2);
		}
		vector<pii>gamesadd;
		if(!pq.empty()){
			int cnt=0;
			for(auto i:games){
				cnt+=(i.F!=pq.top().S and i.S!=pq.top().S);
			}
			if(cnt>=pq.top().F-cost){
				rep(i,0,sz(games)){
					if(games[i].F!=pq.top().S and games[i].S!=pq.top().S and pq.top().F-cost>0){
						gamesadd.pb(games[i]);
						auto beta=pq.top();
						pq.pop();
						beta.F--;
						pq.push(beta);
					}
				}
			}
			else continue;
		}
		cout<<cost<<endl;
		cout<<sz(games)<<endl;
		int j=0;
		rep(i,0,sz(games)){
			string s(n,'0');
			s[games[i].F]='1';
			s[games[i].S]='1';
			if(j<sz(gamesadd) and games[i]==gamesadd[j]){
				assert(s[pq.top().S]=='0');
				s[pq.top().S]='1';
				j++;
			}
			cout<<s<<endl;
		}
		return;
	}
	cout<<0<<endl;
	cout<<50*n<<endl;
	rep(i,0,50){
		rep(j,0,n){
			string s(n,'0');
			s[j]='1';
			s[(j+1)%n]='1';
			cout<<s<<endl;
		}
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
#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
vector<pair<int,ll>> E[202020];
ll A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		ll a;
		cin>>x>>y>>a;
		E[x-1].push_back({y-1,a});
		E[y-1].push_back({x-1,a});
	}
	priority_queue<pair<ll,int>> P;
	FOR(i,N) {
		cin>>A[i];
		P.push({-A[i],i});
	}
	
	while(P.size()) {
		ll co=-P.top().first;
		int cur=P.top().second;
		P.pop();
		if(A[cur]!=co) continue;
		FORR(e,E[cur]) if(A[e.first]>co+2*e.second) {
			A[e.first]=co+2*e.second;
			P.push({-A[e.first],e.first});
		}
	}
	FOR(i,N) cout<<A[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
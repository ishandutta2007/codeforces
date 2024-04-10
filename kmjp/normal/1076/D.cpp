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

int N,M,K;
int X[303030],Y[303030],W[303030];
vector<pair<int,int>> E[303030];
ll D[303030];
int from[303030];
set<int> ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&N,&M,&K);
	FOR(i,M) {
		scanf("%d%d%d",&x,&y,&r);
		X[i]=x-1;
		Y[i]=y-1;
		W[i]=r;
		E[x-1].push_back({y-1,i});
		E[y-1].push_back({x-1,i});
	}
	
	FOR(i,N) D[i]=1LL<<60;
	D[0]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	while(ret.size()<K && Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		
		if(D[cur]!=co) continue;
		
		if(cur) ret.insert(from[cur]+1);
		FORR(e,E[cur]) if(D[e.first]>D[cur]+W[e.second]) {
			D[e.first]=D[cur]+W[e.second];
			from[e.first]=e.second;
			Q.push({-D[e.first],e.first});
		}
	}
	
	cout<<ret.size()<<endl;
	FORR(e,ret) cout<<e<<" ";
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
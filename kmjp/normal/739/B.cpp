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

int N;
int A[202020];
int P[202020];
ll W[202020];
ll D[202020];
vector<pair<int,int>> E[202020];
priority_queue<ll> Q[202020];
int ret[202020];

void dfs(int cur,int pre,ll d) {
	D[cur]=d;
	FORR(e,E[cur]) if(e.first!=pre) {
		dfs(e.first,cur,d+e.second);
		if(Q[cur].size()<Q[e.first].size()) swap(Q[cur],Q[e.first]);
	}
	FORR(e,E[cur]) if(e.first!=pre) {
		while(Q[e.first].size()) {
			Q[cur].push(Q[e.first].top());
			Q[e.first].pop();
		}
	}
	while(Q[cur].size()) {
		if(Q[cur].top()<=D[cur]) break;
		Q[cur].pop();
	}
	ret[cur]=Q[cur].size();
	Q[cur].push(D[cur]-A[cur]);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N-1) {
		cin>>x>>y;
		x--;
		E[i+1].push_back({x,y});
		E[x].push_back({i+1,y});
	}
	
	dfs(0,-1,0);
	
	FOR(i,N) _P("%d%c",ret[i],(i==N-1)?'\n':' ');
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
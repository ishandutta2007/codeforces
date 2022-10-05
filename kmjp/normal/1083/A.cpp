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
ll W[303030];
vector<pair<int,int>> E[303030];

ll best[303030];
ll ma;

void dfs(int cur,int pre) {
	vector<ll> C;
	
	FORR(e,E[cur]) if(e.first!=pre) {
		dfs(e.first,cur);
		if(best[e.first]-e.second>0) C.push_back(best[e.first]-e.second);
	}
	
	C.push_back(0);
	C.push_back(0);
	sort(ALL(C));
	reverse(ALL(C));
	
	ma=max(ma,W[cur]+C[0]+C[1]);
	best[cur]=W[cur]+C[0];
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>W[i];
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	
	dfs(0,-1);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
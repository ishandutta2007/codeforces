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
vector<int> E[202020];
set<int> NE[202020];
int D[202020];
set<int> S[202020];

void dfs(int cur,int pre,int d) {
	D[cur]=d;
	S[d].insert(cur);
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur,d+1);
		NE[cur].insert(e);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	dfs(1,1,0);
	
	queue<set<int>> Q;
	set<int> S;
	S.insert(1);
	Q.push(S);
	FOR(i,N) {
		cin>>x;
		while(Q.size() && Q.front().empty()) Q.pop();
		if(Q.empty()) return _P("No\n");
		
		if(Q.front().count(x)==0) return _P("No\n");
		Q.front().erase(x);
		Q.push(NE[x]);
	}
	_P("Yes\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
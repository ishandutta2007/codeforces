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
set<int> center;
vector<vector<int>> ret;
int last=-1;
int dfs(int cur,int pre) {
	int C=1;
	int ok=1;
	FORR(e,E[cur]) if(e!=pre) {
		int x=dfs(e,cur);
		if(x>N/2) ok=0;
		C+=x;
	}
	if(N-C>N/2) ok=0;
	if(ok) center.insert(cur);
	return C;
}

void dfs2(int cur,int pre,int cent,int nex) {
	if(pre!=nex) {
		ret.push_back({cent,last,cur});
		ret.push_back({cur,pre,nex});
		last=cur;
	}
	FORR(e,E[cur]) if(e!=pre) dfs2(e,cur,cent,nex);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	dfs(1,-1);
	
	FORR(c,center) {
		FORR(e,E[c]) if(center.count(e)==0) {
			last=e;
			FORR(e2,E[e]) if(e2!=c) dfs2(e2,e,c,e);
			if(last>=0) ret.push_back({c,last,e});
		}
	}
	
	
	_P("%d\n",ret.size());
	FORR(r,ret) _P("%d %d %d\n",r[0],r[1],r[2]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
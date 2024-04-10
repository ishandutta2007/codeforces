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
vector<int> Q[1010101];
int ret[1010101];
vector<int> E[1010101];

void dfs(int cur,int pre) {
	int ma=1,id=0;
	Q[cur].push_back(1);
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		Q[e].push_back(0);
		if(Q[e].size()>Q[cur].size()) {
			swap(Q[e],Q[cur]);
			id=ret[e]+1;
			ma=Q[cur][Q[cur].size()-1-id];
		}
	}
	int x;
	FORR(e,E[cur]) if(e!=pre) {
		FOR(x,Q[e].size()) {
			Q[cur][Q[cur].size()-1-x]+=Q[e][Q[e].size()-1-x];
			if(Q[cur][Q[cur].size()-1-x]>ma || (Q[cur][Q[cur].size()-1-x]==ma && x<id)) ma=Q[cur][Q[cur].size()-1-x], id=x;
		}
		Q[e].clear();
	}
	
	ret[cur]=id;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,0);
	
	FOR(i,N) cout<<ret[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
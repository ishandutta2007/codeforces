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

int N,K,R;
vector<pair<int,int>> E[202020];
vector<pair<int,int>> C;
int col[202020];

void dfs(int cur,int pre,int pc) {
	
	if(E[cur].size()>R) {
		if(pc==-1) pc=0;
		FORR(e,E[cur]) if(e.first!=pre) {
			col[e.second]=pc;
			dfs(e.first,cur,pc);
		}
	}
	else {
		int c=0;
		FORR(e,E[cur]) if(e.first!=pre) {
			if(c==pc) c++;
			col[e.second]=c;
			dfs(e.first,cur,c);
			c++;
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back({y-1,i});
		E[y-1].push_back({x-1,i});
	}
	FOR(i,N) C.push_back({E[i].size(),i});
	sort(ALL(C));
	while(K) {
		C.pop_back();
		K--;
	}
	R=C.back().first;
	dfs(0,0,-1);
	
	cout<<R<<endl;
	FOR(i,N-1) cout<<col[i]+1<<" ";
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
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

int N,M,S;
int vis[5050];
vector<int> E[5050];

class SCC {
public:
	static const int MV = 5010;
	vector<vector<int> > SC; int NV,GR[MV];
private:
public:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu);
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0; SC.clear(); SC.resize(MV); NUM.clear();
		ZERO(vis); for(int i=0;i<NV;i++) if(!vis[i]) dfs(i);
		ZERO(vis); for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
			SC[c].clear(); revdfs(NUM[i],c); sort(SC[c].begin(),SC[c].end()); c++;
		}
		SC.resize(c);
	}
};

SCC scc;
int in[5050];

void dfs(int cur) {
	if(vis[cur]) return;
	vis[cur]=1;
	FORR(e,E[cur]) dfs(e);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	scc.init(N);
	FOR(i,M) {
		cin>>x>>y;
		scc.add_edge(x-1,y-1);
	}
	S--;
	scc.scc();
	
	FOR(i,N) {
		FORR(e,scc.E[i]) {
			if(scc.GR[i]!=scc.GR[e]) E[scc.GR[i]].push_back(scc.GR[e]), in[scc.GR[e]]=1;
		}
	}
	dfs(scc.GR[S]);
	int ret=0;
	FOR(i,scc.SC.size()) if(vis[i]==0 && in[i]==0) ret++;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
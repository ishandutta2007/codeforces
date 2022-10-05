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

int N,K;
int P[202020];
int Q[202020];

class SCC {
public:
	static const int MV = 255000;
	vector<vector<int> > SC; int NV,GR[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu);
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0; SC.clear(); SC.resize(MV); NUM.clear();
		assert(NV);
		ZERO(vis); for(int i=0;i<NV;i++) if(!vis[i]) dfs(i);
		ZERO(vis); for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
			SC[c].clear(); revdfs(NUM[i],c); sort(SC[c].begin(),SC[c].end()); c++;
		}
		SC.resize(c);
	}
};
SCC scc;
string S;

void debug_sb(SCC& sb) {
	int i,j;
	FOR(i,sb.SC.size()) {
		_P("SC %d : ",i);
		FOR(j,sb.SC[i].size()) _P("%d%s",sb.SC[i][j],(j!=sb.SC[i].size()-1)?" ":"\n");
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	S.resize(N);
	scc.init(N);
	FOR(i,N) cin>>P[i];
	FOR(i,N) cin>>Q[i];
	FOR(i,N-1) {
		scc.add_edge(P[i+1]-1,P[i]-1);
		scc.add_edge(Q[i+1]-1,Q[i]-1);
	}
	scc.scc();
	if(scc.SC.size()<K) {
		cout<<"NO"<<endl;
	}
	else {
		FOR(i,scc.SC.size()) {
			FOR(j,scc.SC[i].size()) {
				S[scc.SC[i][j]]='a'+max(K-1-i,0);
			}
		}
		cout<<"YES"<<endl;
		cout<<S<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
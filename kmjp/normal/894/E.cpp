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
int X[1010101],Y[1010101],W[1010101];

class SCC {
public:
	static const int MV = 1010101;
	vector<vector<int> > SC; int NV,GR[MV],rev[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu); rev[cu]=ind;
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

ll VW[1010101];
vector<pair<int,int>> E[1010101];

ll memo[1010101];

ll hoge(int cur) {
	if(memo[cur]>=0) return memo[cur];
	ll ret=VW[cur];
	FORR(e,E[cur]) ret=max(ret,VW[cur]+hoge(e.first)+e.second);
	return memo[cur]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	scc.init(N);
	FOR(i,M) {
		scanf("%d%d%d",&X[i],&Y[i],&W[i]);
		X[i]--;
		Y[i]--;
		
		scc.add_edge(X[i],Y[i]);
	}
	
	scc.scc();
	FOR(i,M) {
		if(scc.GR[X[i]]==scc.GR[Y[i]]) {
			x=0;
			for(j=14;j>=0;j--) {
				y=x+(1<<j);
				if(y*(y+1)<W[i]*2) x=y;
			}
			VW[scc.GR[X[i]]]+=1LL*W[i]*(x+1)-1LL*x*(x+1)*(x+2)/6;
		}
		else {
			E[scc.GR[X[i]]].push_back({scc.GR[Y[i]],W[i]});
		}
	}
	
	scanf("%d",&S);
	MINUS(memo);
	cout<<hoge(scc.GR[S-1])<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
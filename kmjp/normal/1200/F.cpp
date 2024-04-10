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
int K[1010];
pair<int,int> nex[1010][2520];
int P,Q;

int num[1010][2520];
int vis[1010][2520];

class SCC {
public:
	static const int MV = 1010*2520;
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
		ZERO(vis); for(int i=0;i<NV;i++) if(!vis[i]) dfs(i);
		ZERO(vis); for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
			SC[c].clear(); revdfs(NUM[i],c); sort(SC[c].begin(),SC[c].end()); c++;
		}
		SC.resize(c);
	}
};

int dfs(int v,int val,vector<int>& V) {
	if(vis[v][val]==2) {
		set<int> S;
		int i;
		for(i=V.size()-1;i>=0;i--) {
			S.insert(V[i]/2520);
			if(V[i]==v*2520+val) break;
		}
		num[v][val]=S.size();
	}
	else if(vis[v][val]==0) {
		vis[v][val]=2;
		V.push_back(v*2520+val);
		num[v][val]=dfs(nex[v][val].first,nex[v][val].second,V);
		V.pop_back();
	}
	vis[v][val]=1;
	return num[v][val];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>K[i];
		K[i]=(K[i]%2520+2520)%2520;
	}
	FOR(i,N) {
		vector<int> E;
		cin>>x;
		E.resize(x);
		FOR(j,x) cin>>E[j];
		FOR(j,2520) {
			nex[i][j].first=E[(j+K[i])%x]-1;
			nex[i][j].second=(j+K[i])%2520;
		}
	}
	FOR(i,N) FOR(j,2520) if(vis[i][j]==0) {
		vector<int> V;
		dfs(i,j,V);
	}
	
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		x--;
		y=(y%2520+2520)%2520;
		cout<<num[x][y]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
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


class SCC {
public:
	static const int MV = 105000;
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


SCC scc;
int N,M;
int U[101010],V[101010],C[101010];

vector<int> E[101010];
int in[101010];
int order[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>C[i];
		U[i]--;
		V[i]--;
	}
	
	int ret=(1<<30)-1;
	for(i=29;i>=0;i--) {
		scc.init(N);
		FOR(j,M) if(C[j]>(ret-(1<<i))) {
			scc.add_edge(U[j],V[j]);
		}
		scc.scc();
		if(scc.SC.size()==N) ret-=(1<<i);
	}
	
	FOR(i,M) if(C[i]>ret) {
		E[U[i]].push_back(V[i]);
		in[V[i]]++;
	}
	
	queue<int> Q;
	FOR(i,N) if(in[i]==0) Q.push(i);
	x=0;
	while(Q.size()) {
		i=Q.front();
		Q.pop();
		order[i]=x++;
		
		FORR(e,E[i]) {
			in[e]--;
			if(in[e]==0) Q.push(e);
		}
	}
	
	vector<int> R;
	FOR(i,M) if(order[U[i]]>order[V[i]]) R.push_back(i+1);
	
	cout<<ret<<" "<<R.size()<<endl;
	FORR(r,R) cout<<r<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
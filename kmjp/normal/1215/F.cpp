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
	static const int MV = 2010000;
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

class TwoSat {
	int NV;
	SCC sc;
public:
	vector<int> val;
	void init(int NV) { this->NV=NV*2; sc.init(NV*2); val.resize(NV);}
	void add_edge(int x,int y) { // k+0:normal k+NV:inverse
		sc.add_edge((x+NV/2)%NV,y);
		sc.add_edge((y+NV/2)%NV,x);
	}
	bool sat() { // empty:false 
		sc.scc();
		for(int i=0;i<NV/2;i++) if(sc.GR[i]==sc.GR[i+NV/2]) return false;
		for(int i=0;i<NV/2;i++) val[i]=sc.GR[i]>sc.GR[i+NV/2];
		return true;
	}
};
TwoSat ts;
int N,P,M,L;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P>>M>>L;
	ts.init(P+M);
	FOR(i,N) {
		cin>>x>>y;
		ts.add_edge(x-1,y-1);
	}
	FOR(i,P) {
		cin>>x>>y;
		x--;
		ts.add_edge(i+(P+M),x+P);
		if(y<M) ts.add_edge(i+(P+M),y+P+M+P);
	}
	FOR(i,M-1) {
		ts.add_edge(i+P,i+P+1+(P+M));
	}
	FOR(i,L) {
		cin>>x>>y;
		ts.add_edge(x-1+(P+M),y-1+(P+M));
	}
	
	if(!ts.sat()) {
		cout<<-1<<endl;
	}
	else {
		
		int mi=0;
		FOR(i,M) if(ts.val[i+P]) mi=i+1;
		vector<int> R;
		FOR(i,P) if(ts.val[i]) R.push_back(i+1);
		cout<<R.size()<<" "<<mi<<endl;
		FORR(r,R) cout<<r<<" ";
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
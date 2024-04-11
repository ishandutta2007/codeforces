#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string S,R;
int L,N,M;
int nex[27];

class SCC {
public:
	static const int MV = 5000;
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

vector<pair<int,int> > PP[202][2];

vector<int> isok(vector<int> V) {
	int i;
	FOR(i,N) if(V[i]!=2) {
		FORR(r,PP[i][V[i]]) {
			if(V[r.first]==2) V[r.first]=r.second;
			if(V[r.first]!=r.second) return vector<int>();
		}
	}
	return V;
}

void dfs(int cur,vector<int> V) {
	int i;
	if(cur==N) {
		cout<<S<<endl;
		exit(0);
	}
	
	FOR(i,2) {
		if(i&&nex[0]==L) break;
		S[cur]='a' + (i?nex[0]:0);
		vector<int> V2=V;
		if(V2[cur]!=2 && V2[cur]!=R[0]^i) continue;
		V2[cur]=R[0]^i;
		V2=isok(V2);
		if(V2.size()) dfs(cur+1,V2);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	SCC scc;
	
	cin>>R;
	L=R.size();
	FORR(r,R) r=(r=='V');
	FOR(i,L) {
		for(nex[i]=i+1;nex[i]<L;nex[i]++) if(R[nex[i]]!=R[i]) break;
	}
	cin>>N>>M;
	
	scc.init(2*N);
	FOR(i,M) {
		int p0,p1;
		string t0,t1;
		cin>>p0>>t0>>p1>>t1;
		PP[p0-1][t0=="V"].push_back({p1-1,t1=="V"});
		scc.add_edge((p0-1)*2+(t0=="V"),(p1-1)*2+(t1=="V"));
	}
	cin>>S;
	
	scc.scc();
	FOR(i,N) if(scc.GR[i*2]==scc.GR[i*2+1]) return _P("-1\n");
	
	vector<int> V(N,0),ret;
	FOR(i,N) V[i]=R[S[i]-'a'];
	ret=isok(V);
	if(ret.size()) {
		cout<<S<<endl;
		return;
	}
	
	for(i=N-1;i>=0;i--) {
		FOR(j,2) {
			if(j==0) {
				if(S[i]-'a'+1>=L) continue;
				S[i]++;
			}
			else {
				if(nex[S[i]-'a']>=L) continue;
				S[i]='a'+nex[S[i]-'a'];
			}
			
			V.clear();
			FOR(x,i+1) V.push_back(R[S[x]-'a']);
			for(x=i+1;x<N;x++) V.push_back(2);
			
			V=isok(V);
			if(V.size()) dfs(i+1,V);
		}
	}
	_P("-1\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
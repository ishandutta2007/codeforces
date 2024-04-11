#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 402020;
	vector<edge> E[MV];
	int itr[MV],lev[MV];
	void add_edge(int x,int y,V cap,bool undir=false) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
	}
	void bfs(int cur) {
		MINUS(lev);
		queue<int> q;
		lev[cur]=0;
		q.push(cur);
		while(q.size()) {
			int v=q.front(); q.pop();
			FORR(e,E[v]) if(e.cap>0 && lev[e.to]<0) lev[e.to]=lev[v]+1, q.push(e.to);
		}
	}
	V dfs(int from,int to,V cf) {
		if(from==to) return cf;
		for(;itr[from]<E[from].size();itr[from]++) {
			edge* e=&E[from][itr[from]];
			if(e->cap>0 && lev[from]<lev[e->to]) {
				V f=dfs(e->to,to,min(cf,e->cap));
				if(f>0) {
					e->cap-=f;
					E[e->to][e->reve].cap += f;
					return f;
				}
			}
		}
		return 0;
	}
	V maxflow(int from, int to) {
		V fl=0,tf;
		while(1) {
			bfs(from);
			if(lev[to]<0) return fl;
			ZERO(itr);
			while((tf=dfs(from,to,numeric_limits<V>::max()))>0) fl+=tf;
		}
	}
};

class SCC {
public:
	static const int MV = 555000;
	vector<vector<int> > SC; int NV,GR[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<NV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu);
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0,i; SC.clear(); SC.resize(NV); NUM.clear();
		assert(NV);
		FOR(i,NV) vis[i]=0; FOR(i,NV) if(!vis[i]) dfs(i); FOR(i,NV) vis[i]=0;
		for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
			SC[c].clear(); revdfs(NUM[i],c); sort(SC[c].begin(),SC[c].end()); c++;
		}
		SC.resize(c);
	}
};

pair<vector<int>,vector<pair<int,int>>> DMdecomposition(int L,int R,vector<vector<int>> E) {
	static MaxFlow_dinic<int> mf; //static
	static SCC scc;
	//
	int i;
	FOR(i,L) mf.add_edge(L+R,i,1);
	FOR(i,R) mf.add_edge(L+i,L+R+1,1);
	E.resize(L+R);
	FOR(i,L) FORR(e,E[i]) mf.add_edge(i,L+e,1);
	vector<int> G(L+R,-1); 

	int flow=mf.maxflow(L+R,L+R+1);
	vector<vector<int>> E2(L+R),RE2(L+R);
	vector<pair<int,int>> match;
	FOR(i,L) {
		if(mf.E[L+R][i].cap==1) G[i]=0;
		FORR(e,mf.E[i]) if(e.to<L+R) {
			if(e.cap==0) { //
				E2[i].push_back(e.to);
				E2[e.to].push_back(i);
				RE2[i].push_back(e.to);
				RE2[e.to].push_back(i);
				match.push_back({i,e.to});
			}
			else {
				E2[i].push_back(e.to);
				RE2[e.to].push_back(i);
			}
		}
	}
	FOR(i,R) if(mf.E[L+i][0].cap==1) G[i+L]=1;
	
	
	queue<int> Q;
	// 
	FOR(i,L) if(G[i]==0) Q.push(i);
	while(Q.size()) {
		int x=Q.front();
		Q.pop();
		FORR(e,E2[x]) if(G[e]==-1) G[e]=0, Q.push(e);
	}
	// 
	FOR(i,R) if(G[L+i]==1) Q.push(L+i);
	while(Q.size()) {
		int x=Q.front();
		Q.pop();
		FORR(e,RE2[x]) if(G[e]==-1) G[e]=1, Q.push(e);
	}
	
	
	scc.init(L+R);
	FOR(i,L) if(G[i]==-1) {
		FORR(e,mf.E[i]) if(e.to<L+R && G[e.to]==-1) {
			if(e.cap==0) scc.add_edge(e.to,i);
			scc.add_edge(i,e.to);
		}
	}
	scc.scc();
	FOR(i,L+R) if(G[i]==-1) G[i]=scc.GR[i]+2;
	
	return {G,match};
}

int N1,N2,M,Q;
int X[202020],Y[202020];
map<pair<int,int>,int> mp;
int dead[404040];
MaxFlow_dinic<int> mf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N1>>N2>>M>>Q;
	vector<vector<int>> Es(N1);
	FOR(i,M) {
		cin>>X[i]>>Y[i];
		X[i]--,Y[i]--;
		Es[X[i]].push_back(Y[i]);
		mp[{X[i],N1+Y[i]}]=i+1;
	}
	auto P=DMdecomposition(N1,N2,Es);
	vector<int> G=P.first;
	vector<pair<int,int>> matches=P.second;
	
	ll sum=0;
	FORR2(a,b,matches) sum+=mp[{a,b}];
	
	while(Q--) {
		cin>>x;
		if(x==1) {
			x=matches.back().first;
			y=matches.back().second;
			sum-=mp[{x,y}];
			matches.pop_back();
			cout<<1<<endl;
			if(G[x]==1) {
				cout<<(x+1)<<endl;
			}
			else {
				cout<<-(y-N1+1)<<endl;
			}
			cout<<sum<<endl;
		}
		else {
			vector<int> V;
			FORR2(a,b,matches) V.push_back(mp[{a,b}]);
			sort(ALL(V));
			cout<<V.size()<<endl;
			FORR(r,V) cout<<r<<" ";
			cout<<endl;
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
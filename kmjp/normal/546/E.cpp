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

int N,M;
int A[1010],B[1010];
int mat[101][101];

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 1100;
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
			ITR(e,E[v]) if(e->cap>0 && lev[e->to]<0) lev[e->to]=lev[v]+1, q.push(e->to);
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


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MaxFlow_dinic<int> mf;
	cin>>N>>M;
	int ta=0,tb=0;
	FOR(i,N) {
		cin>>A[i];
		ta+=A[i];
		mf.add_edge(0,i+1,A[i]);
		mf.add_edge(i+1,i+101,1010);
	}
	FOR(i,N) {
		cin>>B[i];
		tb+=B[i];
		mf.add_edge(i+101,202,B[i]);
	}
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		mf.add_edge(x+1,y+101,1010);
		mf.add_edge(y+1,x+101,1010);
	}
	int fl=mf.maxflow(0,202);
	
	if(ta!=tb || ta!=fl) return _P("NO\n");
	
	FOR(i,N) {
		FORR(r,mf.E[i+1]) {
			if(r.to>=101) mat[i][r.to-101] = 1010-r.cap;
		}
	}
	_P("YES\n");
	FOR(x,N) {
		FOR(y,N) _P("%d ",mat[x][y]);
		_P("\n");
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
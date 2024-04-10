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

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 16000;
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


int N,M;
int P[5050],C[5050];
int D;
int K[5050],alive[5050];

MaxFlow_dinic<int> mf;
int ret[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>P[i];
	FOR(i,N) {
		cin>>C[i];
		C[i]--;
		alive[i]=1;
	}
	cin>>D;
	FOR(i,D) {
		cin>>K[i];
		K[i]--;
		alive[K[i]]=0;
	}
	
	FOR(i,M) mf.add_edge(0,5+i,1);
	FOR(i,N) if(alive[i]) mf.add_edge(5+C[i],5010+P[i],1);
	
	ret[D-1]=0;
	mf.add_edge(5010+ret[D-1],1,1);
	while(mf.maxflow(0,1)) {
		ret[D-1]++;
		mf.add_edge(5010+ret[D-1],1,1);
	}
	for(i=D-2;i>=0;i--) {
		mf.add_edge(5+C[K[i+1]],5010+P[K[i+1]],1);
		ret[i]=ret[i+1];
		while(mf.maxflow(0,1)) {
			ret[i]++;
			mf.add_edge(5010+ret[i],1,1);
		}
	}
	FOR(i,D) cout<<ret[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
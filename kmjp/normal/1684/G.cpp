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

int N;
ll M;
ll T[1010];

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
MaxFlow_dinic<int> mf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<ll> O,L;
	FOR(i,N) {
		cin>>T[i];
		if(T[i]*2+1>M) {
			cout<<-1<<endl;
			return;
		}
		else if(T[i]*3>M) {
			O.push_back(T[i]);
		}
		else {
			L.push_back(T[i]);
		}
	}
	FOR(x,O.size()) {
		mf.add_edge(1000,x,1);
		FOR(y,L.size()) {
			if(O[x]%L[y]==0&&2*O[x]+L[y]<=M) mf.add_edge(x,O.size()+y,1);
		}
	}
	FOR(y,L.size()) mf.add_edge(O.size()+y,1001,1);
	
	x=mf.maxflow(1000,1001);
	if(x<O.size()) {
		cout<<-1<<endl;
		return;
	}
	vector<pair<int,int>> V;
	FOR(x,O.size()) {
		FORR(e,mf.E[x]) if(e.to<1000&&e.cap==0) {
			i=O[x];
			j=L[e.to-O.size()];
			V.push_back({2*i+j,i+j});
			L[e.to-O.size()]=-1;
		}
	}
	FORR(v,L) if(v>0) V.push_back({v*3,v*2});
	
	cout<<V.size()<<endl;
	FORR2(a,b,V) cout<<a<<" "<<b<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
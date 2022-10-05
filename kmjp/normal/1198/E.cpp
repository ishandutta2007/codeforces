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

int N,M;
int X1[51],X2[51],Y1[51],Y2[51];
vector<int> Xs,Ys;
MaxFlow_dinic<ll> mf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	if(M==0) return _P("0\n");
	
	FOR(i,M) {
		cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i];
		X2[i]++;
		Y2[i]++;
		Xs.push_back(X1[i]);
		Xs.push_back(X2[i]);
		Ys.push_back(Y1[i]);
		Ys.push_back(Y2[i]);
	}
	sort(ALL(Xs));
	sort(ALL(Ys));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	Ys.erase(unique(ALL(Ys)),Ys.end());
	
	int NX=Xs.size()-1;
	int NY=Ys.size()-1;
	
	ll sum=0;
	FOR(i,NX) {
		x=Xs[i+1]-Xs[i];
		sum+=x;
		mf.add_edge(NX+NY,i,x);
	}
	FOR(i,NY) {
		x=Ys[i+1]-Ys[i];
		mf.add_edge(NX+i,NX+NY+1,x);
	}
	FOR(x,NX) FOR(y,NY) {
		int ins=0;
		FOR(i,M) if(Xs[x]>=X1[i]&&Xs[x]<X2[i]&&Ys[y]>=Y1[i]&&Ys[y]<Y2[i]) ins=1;
		if(ins) mf.add_edge(x,NX+y,1LL<<40);
	}
	
	cout<<mf.maxflow(NX+NY,NX+NY+1)<<endl;
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
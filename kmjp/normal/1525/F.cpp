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
	static const int MV = 110;
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

int N,M,K;
vector<int> E[55];
int disable[101];

int go() {
	MaxFlow_dinic<int> mf;
	int i;
	FOR(i,N) {
		if(disable[i]==0) mf.add_edge(100,i,1);
		if(disable[i+N]==0) mf.add_edge(i+N,101,1);
		FORR(e,E[i]) mf.add_edge(i,e+N,1);
	}
	
	return N-mf.maxflow(100,101);
}

ll dp[55][55];
int from[55][55];
ll X[55],Y[55];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
	}
	for(i=1;i<=K;i++) cin>>X[i]>>Y[i];
	int cur=go(),start=cur;
	vector<int> cand;
	while(cur<N) {
		FOR(i,2*N) if(disable[i]==0) {
			disable[i]=1;
			x=go();
			if(x==cur+1) {
				cur++;
				if(i<N) cand.push_back(i+1);
				else cand.push_back(-((i-N)+1));
				break;
			}
			disable[i]=0;
		}
	}
	
	FOR(x,55) FOR(y,55) dp[x][y]=-1LL<<60;
	dp[0][start]=0;
	for(x=1;x<=K;x++) {
		for(y=x+1;y<=N;y++) {
			for(i=start;i<=y;i++) {
				ll a=dp[x-1][i]+max(0LL,X[x]-(y-i)*Y[x]);
				if(a>dp[x][y]) {
					dp[x][y]=a;
					from[x][y]=i;
				}
			}
		}
	}
	y=max_element(dp[K]+K,dp[K]+N+1)-dp[K];
	vector<int> V;
	x=K;
	for(x=K;x>=1;x--) {
		i=from[x][y];
		V.push_back(0);
		for(j=y-1;j>=i;j--) V.push_back(cand[j-start]);
		y=i;
	}
	
	cout<<V.size()<<endl;
	reverse(ALL(V));
	FORR(v,V) cout<<v<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
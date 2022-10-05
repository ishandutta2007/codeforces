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

int N,K;
int P[101],C[101],L[101];

template<class V> class MaxFlow_Ford {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 102;
	vector<edge> E[MV];
	int vis[MV];
	void add_edge(int x,int y,V cap,bool undir=false) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
	}
	V dfs(int from,int to,V cf) {
		V tf;
		if(from==to) return cf;
		vis[from]=1;
		FORR(e,E[from]) if(vis[e.to]==0 && e.cap>0 && (tf = dfs(e.to,to,min(cf,e.cap)))>0) {
			e.cap -= tf;
			E[e.to][e.reve].cap += tf;
			return tf;
		}
		return 0;
	}
	V maxflow(int from, int to) {
		V fl=0,tf;
		while(1) {
			ZERO(vis);
			if((tf = dfs(from,to,numeric_limits<V>::max()))==0) return fl;
			fl+=tf;
		}
	}
};

const int prime_max = 1000000;
int NP,prime[100000],divp[prime_max];
map<int,int> M;

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) divp[j]=i;
	}
}


int ok(int val) {
	int i,j;
	MaxFlow_Ford<ll> mf;
	ll tot=0;
	FOR(i,N) if(L[i]<=val && C[i]!=1) {
		tot+=P[i];
		if(C[i]%2==0) {
			mf.add_edge(100,i,P[i]);
			FOR(j,N) if(C[j]%2==1 && divp[C[i]+C[j]]==0) {
				mf.add_edge(i,j,1LL<<60);
			}
		}
		else mf.add_edge(i,101,P[i]);
	}
	
	int id=-1;
	FOR(i,N) if(C[i]==1 && L[i]<=val && (id==-1 || P[i]>P[id]) ) id=i;
	if(id>-1) {
		tot+=P[id];
		mf.add_edge(id,101,P[id]);
	}
	
	return tot-mf.maxflow(100,101)>=K;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	cin>>N>>K;
	FOR(i,N) cin>>P[i]>>C[i]>>L[i];
	
	int ret=N+1;
	for(i=10;i>=0;i--) if(ok(ret-(1<<i))) ret -= 1<<i;
	if(ret==N+1) ret=-1;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
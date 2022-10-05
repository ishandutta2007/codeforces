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

int N,M,K,Q;
vector<pair<int,int>> E[101010];
vector<pair<int,ll>> E2[101010];
int from[101010];
ll dist[101010];

int P[21][200005],D[200005];
ll ma[21][200005];


template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<500000> uf;

void dfs(int cur) {
	FORR(e,E2[cur]) if(e.first!=P[0][cur]) {
		D[e.first]=D[cur]+1;
		P[0][e.first]=cur;
		ma[0][e.first]=e.second;
		dfs(e.first);
	}
}
int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d%d",&N,&M,&K,&Q);
	FOR(i,M) {
		scanf("%d%d%d",&x,&y,&r);
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	priority_queue<pair<ll,int>> PQ;
	FOR(i,N) {
		if(i<K) from[i]=i, PQ.push({0,i});
		else dist[i]=1LL<<60;
	}
	
	while(PQ.size()) {
		ll co=-PQ.top().first;
		int cur=PQ.top().second;
		PQ.pop();
		if(dist[cur]!=co) continue;
		FORR(e,E[cur]) if(dist[e.first]>co+e.second) {
			dist[e.first]=co+e.second;
			from[e.first]=from[cur];
			PQ.push({-dist[e.first],e.first});
		}
	}
	
	vector<vector<ll>> Es;
	FOR(i,N) FORR(e,E[i]) if(from[e.first]>from[i]) {
		Es.push_back({dist[i]+dist[e.first]+e.second,from[i],from[e.first]});
	}
	sort(ALL(Es));
	FORR(e,Es) {
		if(uf[e[1]]!=uf[e[2]]) {
			uf(e[1],e[2]);
			E2[e[1]].push_back({e[2],e[0]});
			E2[e[2]].push_back({e[1],e[0]});
		}
	}
	dfs(0);
	FOR(i,19) FOR(x,K) {
		P[i+1][x]=P[i][P[i][x]];
		ma[i+1][x]=max(ma[i][x],ma[i][P[i][x]]);
	}
	while(Q--) {
		scanf("%d%d",&x,&y);
		x--;
		y--;
		int lc=lca(x,y);
		ll ret=0;
		for(i=18;i>=0;i--) {
			if(D[x]-D[lc]>=1<<i) ret=max(ret,ma[i][x]), x=P[i][x];
			if(D[y]-D[lc]>=1<<i) ret=max(ret,ma[i][y]), y=P[i][y];
		}
		cout<<ret<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
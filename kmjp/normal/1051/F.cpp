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

int N,M,Q;
vector<pair<int,ll>> E[101010],AE[101010];

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

int P[21][200005],D[200005];
ll DD[200005];
void dfs(int cur) {
	FORR(e,E[cur]) if(e.first!=P[0][cur]) {
		D[e.first]=D[cur]+1;
		DD[e.first]=DD[cur]+e.second;
		P[0][e.first]=cur;
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

ll dist(int a,int b) {
	int l=lca(a,b);
	return DD[a]+DD[b]-2*DD[l];
}

vector<int> C;
ll dp[101010][45];
ll dp2[45][45];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>r;
		x--,y--;
		if(uf[x]!=uf[y]) {
			E[x].push_back({y,r});
			E[y].push_back({x,r});
			uf(x,y);
		}
		else {
			AE[x].push_back({y,r});
			AE[y].push_back({x,r});
		}
	}
	
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	FOR(i,N) if(AE[i].size()) C.push_back(i);
	
	FOR(i,N) FOR(x,C.size()) dp[i][x]=dist(i,C[x]);
	FOR(x,C.size()) {
		FOR(y,C.size()) dp2[x][y]=dp[C[x]][y];
		FORR(a,AE[C[x]]) {
			y=lower_bound(ALL(C),a.first)-C.begin();
			dp2[x][y]=min(dp2[x][y],a.second);
		}
	}
	FOR(z,C.size()) FOR(x,C.size()) FOR(y,C.size()) dp2[x][y]=min(dp2[x][y],dp2[x][z]+dp2[z][y]);
	
	cin>>Q;
	while(Q--) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		ll ret=dist(u,v);
		FOR(x,C.size()) FOR(y,C.size()) ret=min(ret,dp[u][x]+dp2[x][y]+dp[v][y]);
		cout<<ret<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
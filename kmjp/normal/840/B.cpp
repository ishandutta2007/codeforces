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

int N,M;
int DD[303030];
vector<pair<int,int>> E[303030];
int PE[303030];
int P[21][300005],D[300005];

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
vector<int> C[2];
vector<int> DC[303030];
int X[303030];

void dfs(int cur) {
	DC[D[cur]].push_back(cur);
	ITR(it,E[cur]) {
		if(it->first!=P[0][cur]) D[it->first]=D[cur]+1, P[0][it->first]=cur, dfs(it->first);
		if(it->first==P[0][cur]) PE[cur]=it->second;
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
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x;
		if(x==1) C[0].push_back(i);
		if(x==-1) C[1].push_back(i);
	}
	
	if(C[0].size()%2==1 && C[1].size()) C[0].push_back(C[1][0]);
	if(C[0].size()%2==1) return _P("-1\n");
	
	FOR(i,M) {
		cin>>x>>y;
		if(uf[x]!=uf[y]) {
			E[x-1].push_back({y-1,i+1});
			E[y-1].push_back({x-1,i+1});
			uf(x,y);
		}
	}
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	FOR(i,C[0].size()/2) {
		X[C[0][i*2]]^=1;
		X[C[0][i*2+1]]^=1;
	}
	
	vector<int> R;
	for(i=N;i>0;i--) FORR(v,DC[i]) {
		X[P[0][v]]^=X[v];
		if(X[v]) R.push_back(PE[v]);
	}
	sort(ALL(R));
	cout<<R.size()<<endl;
	FORR(r,R) cout<<r<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
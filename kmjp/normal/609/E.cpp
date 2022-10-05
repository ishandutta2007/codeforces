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

int N,M;
map<pair<int,int>,int > MP;
int U[202020],V[202020], W[202020];
vector<pair<int,int> > VV;
int inc[202020];
vector<int> E[202020];
ll sum;

int P[21][200005],MA[21][200005],D[200005];

void dfs(int cur) {
	ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
}
int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

int hoge(int a,int b) {
	int ret=0;
	for(int i=19;i>=0;i--) if(D[a]-D[b]>=(1<<i)) {
		ret = max(ret,MA[i][a]);
		a=P[i][a];
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>W[i];
		U[i]--, V[i]--;
		if(U[i]>V[i]) swap(U[i],V[i]);
		MP[{U[i],V[i]}]=i;
		VV.push_back({W[i],i});
	}
	sort(ALL(VV));
	FORR(r,VV) {
		x = r.second;
		if(uf[U[x]] != uf[V[x]]) {
			inc[x]=1;
			sum += W[x];
			uf(U[x],V[x]);
			E[U[x]].push_back(V[x]);
			E[V[x]].push_back(U[x]);
		}
	}
	
	dfs(0);
	FOR(x,N) {
		y=P[0][x];
		if(x!=y) MA[0][x]=W[MP[{min(x,y),max(x,y)}]];
	}
	FOR(i,19) FOR(x,N) {
		P[i+1][x]=P[i][P[i][x]];
		MA[i+1][x] = max(MA[i][x],MA[i][P[i][x]]);
	}
	FOR(i,M) {
		if(inc[i]) {
			cout<<sum<<endl;
		}
		else {
			int lc=lca(U[i],V[i]);
			int mae=max(hoge(U[i],lc),hoge(V[i],lc));
			cout<<(sum-mae+W[i])<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
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
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

int N,M,K;
set<pair<int,int>> E;
set<int> L;
UF<500000> uf;
int toone[303030];

void dfs(int cur) {
	vector<int> v;
	FORR(r,L) if(E.count({r,cur})==0) v.push_back(r);
	FORR(r,v) uf(cur,r);
	FORR(r,v) L.erase(r);
	FORR(r,v) dfs(r);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y;
		E.insert({x-1,y-1});
		E.insert({y-1,x-1});
	}
	
	
	for(i=1;i<N;i++) L.insert(i);
	for(i=1;i<N;i++) if(L.count(i)) dfs(i);
	
	int mi=0,ma=0;
	for(i=1;i<N;i++) if(E.count({i,0})==0) toone[uf[i]]++;
	for(i=1;i<N;i++) if(uf[i]==i) {
		if(toone[i]==0) return _P("impossible\n");
		mi++;
		ma+=toone[i];
	}
	
	if(mi<=K && K<=ma) _P("possible\n");
	else _P("impossible\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
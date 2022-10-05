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

int N;
int C[202020];
vector<int> E[202020];
map<int,vector<int>> M;
int id;
int L[202020],R[202020];

set<int> S,leafs;

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

void dfs(int cur,int pre) {
	L[cur]=id;
	if(cur>0 && E[cur].size()==1) {
		leafs.insert(L[cur]);
		id++;
	}
	
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
	R[cur]=id;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>C[i];
		M[C[i]].push_back(i);
	}
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,-1);
	leafs.insert(N);
	
	ll ret=0;
	FORR(m,M) {
		FORR(v,m.second) if(uf[L[v]]!=uf[R[v]]) S.insert(v);
		FORR(v,m.second) if(uf[L[v]]!=uf[R[v]]) {
			ret+=m.first;
			uf(L[v],R[v]);
		}
	}
	cout<<ret<<" "<<S.size()<<endl;
	FORR(s,S) cout<<(s+1)<<" ";
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
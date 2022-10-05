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

int N;
int C[202020];
int A[202020],B[202020];
int ma,id;
vector<int> E[202020];

void dfs(int cur,int d,int pre) {
	if(d>ma) id=cur, ma=d;
	FORR(e,E[cur]) if(e!=pre) dfs(e,d+1,cur);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>C[i];
	FOR(i,N-1) {
		cin>>A[i]>>B[i];
		A[i]--,B[i]--;
		if(C[A[i]]==C[B[i]]) uf(A[i],B[i]);
	}
	
	int st=-1;
	FOR(i,N-1) {
		if(C[A[i]]!=C[B[i]]) {
			E[uf[A[i]]].push_back(uf[B[i]]);
			E[uf[B[i]]].push_back(uf[A[i]]);
			st=uf[A[i]];
		}
	}
	
	if(st==-1) return _P("0\n");
	
	id=st;
	dfs(st,0,-1);
	
	ma=0;
	st=id;
	dfs(st,0,-1);
	cout<<(ma+1)/2<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
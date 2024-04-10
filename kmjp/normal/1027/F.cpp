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
UF<2500000> uf;

int N;
int A[1010101],B[1010101];
vector<int> V;
vector<ll> C[2010101];
int NE[2010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) {
		scanf("%d%d",&A[i],&B[i]);
		V.push_back(A[i]);
		V.push_back(B[i]);
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	FOR(i,N) {
		A[i]=lower_bound(ALL(V),A[i])-V.begin();
		B[i]=lower_bound(ALL(V),B[i])-V.begin();
		uf(A[i],B[i]);
	}
	
	FOR(i,V.size()) C[uf[i]].push_back(V[i]);
	FOR(i,N) NE[uf[A[i]]]++;
	
	ll ma=0;
	FOR(i,V.size()) if(C[i].size()) {
		if(C[i].size()<NE[i]) return _P("-1\n");
		if(C[i].size()==NE[i]) ma=max(ma,C[i].back());
		if(C[i].size()==NE[i]+1) {
			C[i].pop_back();
			ma=max(ma,C[i].back());
		}
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
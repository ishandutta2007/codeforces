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
int N,M,Q;
int U[1010101],V[1010101],W[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<pair<int,int>> P;
	cin>>N>>M>>Q;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>W[i];
		P.push_back({W[i],i});
	}
	sort(ALL(P));
	reverse(ALL(P));
	while(Q--) {
		int L,R;
		cin>>L>>R;
		L--,R--;
		UF<2002> uf;
		int ret=-1;
		FORR(r,P) {
			x=r.second;
			if(x<L || R<x) continue;
			if(uf[2*U[x]]==uf[2*V[x]+1]) continue;
			uf(2*U[x],2*V[x]+1);
			uf(2*U[x]+1,2*V[x]);
			if(uf[2*U[x]]==uf[2*U[x]+1]) {
				ret=W[x];
				break;
			}
		}
		cout<<ret<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
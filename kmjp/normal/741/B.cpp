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

int N,M,WW;
int W[1010];
int B[1010];
int X[101010],Y[101010];
vector<int> E[1010];

int from[1010];
int to[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>WW;
	FOR(i,N) cin>>W[i];
	FOR(i,N) cin>>B[i];
	FOR(i,M) {
		cin>>X[i]>>Y[i];
		uf(X[i]-1,Y[i]-1);
	}
	FOR(i,N) E[uf[i]].push_back(i);
	
	FOR(i,N) if(E[i].size()) {
		int tw=0;
		int tb=0;
		FOR(j,1001) to[j]=from[j];
		FORR(r,E[i]) {
			tw+=W[r],tb+=B[r];
			// one
			for(x=W[r];x<=WW;x++) to[x]=max(to[x],from[x-W[r]]+B[r]);
		}
		for(x=tw;x<=WW;x++) to[x]=max(to[x],from[x-tw]+tb);
		swap(from,to);
	}
	
	cout<<*max_element(from,from+WW+1)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
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
int X[2020],Y[2020];
ll C[2020],K[2020];

vector<vector<ll>> E;
vector<int> P;
vector<pair<int,int>> R;

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
UF<2020> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	FOR(i,N) {
		cin>>C[i];
		E.push_back({C[i],i,N});
	}
	FOR(i,N) {
		cin>>K[i];
		FOR(j,i) E.push_back({(abs(X[i]-X[j])+abs(Y[i]-Y[j]))*(K[j]+K[i]),i,j});
	}
	
	sort(ALL(E));
	ll ret=0;
	FORR(e,E) if(uf[e[1]]!=uf[e[2]]) {
		ret+=e[0];
		uf(e[1],e[2]);
		if(e[2]==N) P.push_back(e[1]);
		else R.push_back({e[1],e[2]});
	}
	
	cout<<ret<<endl;
	cout<<P.size()<<endl;
	FORR(p,P) cout<<(p+1)<<" ";
	cout<<endl;
	cout<<R.size()<<endl;
	FORR(r,R) cout<<(r.first+1)<<" "<<(r.second+1)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
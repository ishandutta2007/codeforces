#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<1020202> uf;

int N,Q;
int A[1010101];

int C[1010101];
vector<int> V[1010101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=1000011;i++) C[i]=i;
	for(i=1;i<=1000011;i++) if(C[i]>1) {
		for(j=i;j<=1000011;j+=i) {
			V[j].push_back(i);
			while(C[j]%i==0) C[j]/=i;
		}
	}
	
	cin>>N>>Q;
	set<pair<int,int>> E;
	FOR(i,N) {
		cin>>A[i];
		FORR(v,V[A[i]]) uf(v,A[i]);
	}
	FOR(i,N) {
		auto v=V[A[i]+1];
		FORR(a,v) a=uf[a];
		v.push_back(uf[A[i]]);
		FOR(j,v.size()) FOR(k,v.size()) {
			E.insert({v[j],v[k]});
		}
		
	}
	FOR(i,Q) {
		int S,T;
		cin>>S>>T;
		S=uf[A[S-1]];
		T=uf[A[T-1]];
		if(S==T) {
			cout<<0<<endl;
		}
		else if(E.count({S,T})) {
			cout<<1<<endl;
		}
		else {
			cout<<2<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
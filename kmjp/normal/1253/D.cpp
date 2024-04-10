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

int N,M;
int L[202020],R[202020];
UF<202020> uf;
int did[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) L[i]=R[i]=i;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		if(uf[x]!=uf[y]) {
			L[uf[x]]=L[uf[y]]=min(L[uf[x]],L[uf[y]]);
			R[uf[x]]=R[uf[y]]=max(R[uf[x]],R[uf[y]]);
			uf(x,y);
		}
	}
	int add=0;
	FOR(i,N) if(did[uf[i]]==0) {
		did[uf[i]]=1;
		for(x=i+1;x<=R[uf[i]];x++) if(did[uf[x]]==0) {
			add++;
			did[uf[x]]=1;
			L[uf[x]]=L[uf[i]]=min(L[uf[x]],L[uf[i]]);
			R[uf[x]]=R[uf[i]]=max(R[uf[x]],R[uf[i]]);
			uf(x,i);
		}
	}
	cout<<add<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
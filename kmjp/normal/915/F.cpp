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
int A[1010101];
vector<int> E[1010101];
pair<int,int> P[1010101];
int S[1010101];

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
UF<1010101> uf[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) {
		scanf("%d",&A[i]);
		P[i]={A[i],i};
	}
	FOR(i,N-1) {
		scanf("%d%d",&x,&y);
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	sort(P,P+N);
	
	ll ret=0;
	FOR(i,N) {
		x=P[i].second;
		S[x]=1;
		
		int cur=1;
		FORR(e,E[x]) if(S[e]==1) {
			ret += 1LL*A[x]*uf[0].count(x)*uf[0].count(e);
			uf[0](x,e);
		}
	}
	FOR(i,N) {
		x=P[N-1-i].second;
		S[x]=2;
		
		int cur=1;
		FORR(e,E[x]) if(S[e]==2) {
			int nv=uf[1].count(e);
			ret -= 1LL*A[x]*uf[1].count(x)*uf[1].count(e);
			uf[1](x,e);
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
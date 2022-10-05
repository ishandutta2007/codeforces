#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
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
UF<202020> uf;
int M,N;
int A[101010],B[101010];
vector<pair<int,pair<int,int>>> P;
vector<pair<int,int>> V[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&M,&N);
	FOR(i,M) {
		scanf("%d",&A[i]);
	}
	FOR(i,N) scanf("%d",&B[i]);
	FOR(i,M) {
		scanf("%d",&x);
		while(x--) {
			scanf("%d",&y);
			P.push_back({A[i]+B[y-1],{i,y-1}});
		}
		sort(ALL(V[i]));
		reverse(ALL(V[i]));
	}
	sort(ALL(P));
	reverse(ALL(P));
	
	ll ret=0;
	FORR(p,P) {
		x=p.second.first;
		y=p.second.second+100000;
		if(uf[x]==uf[y]) {
			ret+=p.first;
		}
		else {
			uf(x,y);
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
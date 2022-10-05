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

int N,K,M;
int KA[505050],KB[505050];
int FA[505050],FB[505050],FC[505050];

vector<pair<int,int>> E[505050];
int P[500005],D[500005],C[500005];

void dfs(int cur) {
	FORR(e,E[cur]) {
		if(e.first==P[cur]) C[cur]=e.second;
		else {
			D[e.first]=D[cur]+1;
			P[e.first]=cur;
			dfs(e.first);
		}
	}
}

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

UF<505050> uf;
ll ret=0;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&N,&K,&M);
	FOR(i,K) {
		scanf("%d%d",&KA[i],&KB[i]);
		KA[i]--;
		KB[i]--;
		uf(KA[i],KB[i]);
		E[KA[i]].push_back({KB[i],1});
		E[KB[i]].push_back({KA[i],1});
	}
	FOR(i,M) {
		scanf("%d%d%d",&FA[i],&FB[i],&FC[i]);
		FA[i]--;
		FB[i]--;
		if(uf[FA[i]]!=uf[FB[i]]) {
			E[FA[i]].push_back({FB[i],0});
			E[FB[i]].push_back({FA[i],0});
			uf(FA[i],FB[i]);
			FC[i]=0;
		}
	}
	
	dfs(0);
	
	ll ret=0;
	FOR(i,M) if(FC[i]) {
		x=FA[i];
		y=FB[i];
		while(x!=y) {
			if(D[x]>D[y]) {
				if(C[x]) ret+=FC[i], C[x]=0, K--;
				x=P[x];
			}
			else if(D[x]<D[y]) {
				if(C[y]) ret+=FC[i], C[y]=0, K--;
				y=P[y];
			}
			else {
				if(C[x]) ret+=FC[i], C[x]=0, K--;
				if(C[y]) ret+=FC[i], C[y]=0, K--;
				x=P[x];
				y=P[y];
			}
		}
		while(FA[i]!=x) {
			y=FA[i];
			FA[i]=P[y];
			P[y]=x;
		}
		while(FB[i]!=x) {
			y=FB[i];
			FB[i]=P[y];
			P[y]=x;
		}
	}
	
	if(K) ret=-1;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
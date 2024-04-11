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

int T;
int N,NE,Q;

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
UF<202020> uf;
vector<pair<int,int>> E[202020];
int P[21][200005],M[21][200005],D[200005];
int LC[21][200005],ML[21][200005];

void dfs(int cur) {
	FORR2(e,l,E[cur]) if(e!=P[0][cur]) {
		D[e]=D[cur]+1;
		P[0][e]=cur;
		M[0][e]=l;
		dfs(e);
	}
}
int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

int getlev(int c,int p) {
	int ret=0;
	int i;
	for(i=18;i>=0;i--) if(D[c]-D[p]>=1<<i) {
		ret=max(ret,M[i][c]);
		c=P[i][c];
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>NE>>Q;
		uf.reinit(N);
		FOR(i,N) E[i].clear();
		FOR(i,NE) {
			cin>>x>>y;
			x--,y--;
			if(uf[x]!=uf[y]) {
				uf(x,y);
				E[x].push_back({y,i+1});
				E[y].push_back({x,i+1});
			}
		}
		dfs(0);
		FOR(i,19) FOR(x,N) {
			P[i+1][x]=P[i][P[i][x]];
			M[i+1][x]=max(M[i][x],M[i][P[i][x]]);
		}
		FOR(i,N) {
			LC[0][i]=i;
			ML[0][i]=0;
		}
		FOR(i,19) FOR(x,N) {
			LC[i+1][x]=lca(LC[i][x],LC[i][min(x+(1<<i),N-1)]);
			ML[i+1][x]=max({ML[i][x],ML[i][min(x+(1<<i),N-1)],getlev(LC[i][x],LC[i+1][x]),getlev(LC[i][min(x+(1<<i),N-1)],LC[i+1][x])});
		}
		while(Q--) {
			int L,R;
			cin>>L>>R;
			if(L==R) {
				cout<<0<<" ";
				continue;
			}
			L--;
			x=0;
			while(1<<(x+1)<=R-L) x++;
			R=R-(1<<x);
			int ret=max(ML[x][L],ML[x][R]);
			i=LC[x][L];
			j=LC[x][R];
			int lc=lca(i,j);
			ret=max({ret,getlev(i,lc),getlev(j,lc)});
			cout<<ret<<" ";
		}
		cout<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
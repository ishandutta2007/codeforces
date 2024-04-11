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


int T,N,M;
vector<int> E[1010101];
int U[1010101],V[1010101];

vector<int> path,odd;

int P[21][1200005],D[1200005];
int S[1200005];

void dfs(int cur) {
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
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
UF<1010101> uf;

void dfs2(int cur,int pre) {
	FORR(e,E[cur]) if(e!=pre) dfs2(e,cur);
	if(pre!=-1) S[pre]+=S[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&M);
		FOR(i,max(N,M)+5) E[i].clear(),S[i]=0;
		uf.reinit(N);
		vector<pair<int,int>> rem;
		FOR(i,M) {
			scanf("%d%d",&x,&y);
			x--,y--;
			if(uf[x]!=uf[y]) {
				E[x].push_back(y);
				E[y].push_back(x);
				uf(x,y);
			}
			else {
				rem.push_back({x,y});
			}
		}
		dfs(0);
		FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
		vector<pair<int,int>> odd;
		FORR2(x,y,rem) {
			int lc=lca(x,y);
			if(D[x]%2==D[y]%2) {
				odd.push_back({x,y});
				S[x]++;
				S[y]++;
				S[lc]-=2;
			}
			else {
				S[x]--;
				S[y]--;
				S[lc]+=2;
			}
		}
		if(odd.size()<=1) {
			x=0;
			if(odd.size()&&D[odd[0].first]%2==0) x^=1;

			cout<<"YES"<<endl;
			FOR(i,N) cout<<((D[i]%2)^x);
			cout<<endl;
			continue;
		}
		dfs2(0,-1);
		FOR(i,N) if(S[i]==odd.size()) break;
		if(i==N) {
			cout<<"NO"<<endl;
		}
		else {
			x=i;
			y=P[0][x];
			
			
			FOR(i,N) if(D[i]>D[x]&&getpar(i,D[i]-D[x])==x) D[i]^=1;
			D[x]^=1;
			if(D[x]%2==0) {
				FOR(i,N) D[i]^=1;
			}
			
			cout<<"YES"<<endl;
			FOR(i,N) cout<<D[i]%2;
			cout<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
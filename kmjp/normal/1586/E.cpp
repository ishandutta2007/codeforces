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

int N,M,Q;
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

vector<int> E[303030];
int P[21][300005],D[300005];

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


UF<303030> uf;
int num[303030];
int X[303030],Y[303030];
set<pair<int,int>> E2[303030];
vector<int> ret[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		if(uf[x]!=uf[y]) {
			E[x].push_back(y);
			E[y].push_back(x);
			uf(x,y);
		}
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>X[i]>>Y[i];
		X[i]--;
		Y[i]--;
		num[X[i]]++;
		num[Y[i]]++;
	}
	x=0;
	FOR(i,N) x+=num[i]%2;
	if(x) {
		cout<<"NO"<<endl;
		cout<<x/2<<endl;
		return;
	}
	
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	cout<<"YES"<<endl;
	FOR(i,Q) {
		int lc=lca(X[i],Y[i]);
		x=X[i];
		y=Y[i];
		vector<int> ret={x},ret2={y};
		while(x!=lc) {
			x=P[0][x];
			ret.push_back(x);
		}
		while(y!=lc) {
			y=P[0][y];
			ret2.push_back(y);
		}
		ret2.pop_back();
		reverse(ALL(ret2));
		cout<<ret.size()+ret2.size()<<endl;
		FORR(a,ret) cout<<a+1<<" ";
		FORR(a,ret2) cout<<a+1<<" ";
		cout<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
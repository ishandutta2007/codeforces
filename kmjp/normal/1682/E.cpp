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

int N,M;
int S[202020];
int A[202020],B[202020];
map<pair<int,int>,int> Es;
vector<int> E[202020];
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
int P[21][200005],D[200005];

vector<int> to[202020];
int in[202020];

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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x;
		S[x]=i+1;
	}
	FOR(i,M) {
		cin>>A[i]>>B[i];
		Es[{A[i],B[i]}]=Es[{B[i],A[i]}]=i;
		E[A[i]].push_back(B[i]);
		E[B[i]].push_back(A[i]);
		uf(A[i],B[i]);
	}
	FOR(i,N) if(uf[i+1]==i+1) E[0].push_back(i+1),E[i+1].push_back(0);
	dfs(0);
	FOR(i,19) FOR(x,N+1) P[i+1][x]=P[i][P[i][x]];
	for(i=1;i<=N;i++) if(i!=S[i]) {
		int lc=lca(i,S[i]);
		x=S[i];
		vector<int> AA,BB;
		while(x!=lc) {
			AA.push_back(Es[{x,P[0][x]}]);
			x=P[0][x];
		}
		x=i;
		while(x!=lc) {
			BB.push_back(Es[{x,P[0][x]}]);
			x=P[0][x];
		}
		reverse(ALL(BB));
		FORR(b,BB) AA.push_back(b);
		FOR(j,AA.size()-1) {
			to[AA[j]].push_back(AA[j+1]);
			in[AA[j+1]]++;
		}
	}
	queue<int> Q;
	FOR(i,M) if(in[i]==0) Q.push(i);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		cout<<cur+1<<" ";
		FORR(t,to[cur]) {
			in[t]--;
			if(in[t]==0) Q.push(t);
		}
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
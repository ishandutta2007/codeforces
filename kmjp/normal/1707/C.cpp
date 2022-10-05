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
vector<int> E[602020];
int U[602020],V[602020];
int used[602020];

int P[21][200005],D[200005];
int id;
int L[602020],R[602020];
int S[602020];

void dfs(int cur) {
	L[cur]=id++;
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
	R[cur]=id;
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
UF<602020> uf;


int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	FOR(i,M) {
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
		if(uf[U[i]]!=uf[V[i]]) {
			uf(U[i],V[i]);
			used[i]=1;
			E[U[i]].push_back(V[i]);
			E[V[i]].push_back(U[i]);
		}
	}
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	FOR(i,M) if(used[i]==0) {
		x=U[i];
		y=V[i];
		if(L[x]>L[y]) swap(x,y);
		if(L[y]>=R[x]) {
			S[0]++;
			S[L[x]]--;
			S[R[x]]++;
			S[L[y]]--;
			S[R[y]]++;
		}
		else {
			x=getpar(y,D[y]-D[x]-1);
			S[L[x]]++;
			S[R[x]]--;
			S[L[y]]--;
			S[R[y]]++;
		}
	}
	
	FOR(i,N) S[i+1]+=S[i];
	FOR(i,N) cout<<(S[L[i]]==0);
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
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

int N,K,R,M;
vector<int> E[402020];
int G[402020];
int GD[402020];
int P[21][400005],D[404040];

UF<402020> uf;

void dfs(int cur) {
	ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}
int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>R;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(N+i);
		E[N+i].push_back(x-1);
		E[y-1].push_back(N+i);
		E[N+i].push_back(y-1);
	}
	N=2*N-1;
	FOR(i,N) {
		G[i]=-1-i;
		GD[i]=1<<30;
	}
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	queue<int> Q;
	FOR(i,R) {
		cin>>x;
		x--;
		G[x]=x;
		GD[x]=0;
		Q.push(x);
	}
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		if(GD[x]==K) continue;
		FORR(e,E[x]) {
			if(G[e]<0) {
				G[e]=G[x];
				GD[e]=GD[x]+1;
				Q.push(e);
			}
			else {
				if(GD[x]+GD[e]+1<=2*K) uf(G[x],G[e]);
			}
		}
	}
	
	cin>>M;
	while(M--) {
		int U,V;
		cin>>U>>V;
		U--,V--;
		int l=lca(U,V);
		int td=D[U]+D[V]-2*D[l];
		if(td<=2*K) {
			cout<<"YES"<<endl;
			continue;
		}
		
		int tu,tv;
		if(D[U]-D[l]>=K) {
			tu=getpar(U,K);
		}
		else {
			tu=getpar(V,td-K);
		}
		if(D[V]-D[l]>=K) {
			tv=getpar(V,K);
		}
		else {
			tv=getpar(U,td-K);
		}
		if(G[tu]>=0&&G[tv]>=0&&uf[G[tu]]==uf[G[tv]]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
		
	}
	
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}